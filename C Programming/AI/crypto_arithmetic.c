#include <stdio.h>
#include <string.h>
#define MAX_CHAR 26
#define MAX_DIGIT 10
struct Node {
    char c;
    int v;
};
int use[MAX_DIGIT] = {0};

int check(struct Node* nodeArr, const int count, char* s1, char* s2, char* s3) {
    int val1 = 0, val2 = 0, val3 = 0, m = 1, j, i;

    for (i = strlen(s1) - 1; i >= 0; i--) {
        char ch = s1[i];
        for (j = 0; j < count; j++)
            if (nodeArr[j].c == ch) break;

        val1 += m * nodeArr[j].v;
        m *= 10;
    }
    m = 1;
    for (i = strlen(s2) - 1; i >= 0; i--) {
        char ch = s2[i];
        for (j = 0; j < count; j++)
            if (nodeArr[j].c == ch) break;
        val2 += m * nodeArr[j].v;
        m *= 10;
    }
    m = 1;
    for (i = strlen(s3) - 1; i >= 0; i--) {
        char ch = s3[i];
        for (j = 0; j < count; j++)
            if (nodeArr[j].c == ch) break;

        val3 += m * nodeArr[j].v;
        m *= 10;
    }
    return (val3 == (val1 + val2));
}

int permutation(const int count, struct Node* nodeArr, int n, char* s1, char* s2, char* s3) {
    if (n == count - 1) {
        for (int i = 0; i < MAX_DIGIT; i++) {
            if (use[i] == 0) {
                nodeArr[n].v = i;
                if (check(nodeArr, count, s1, s2, s3)) {
                    printf("\nSolution found:");
                    for (int j = 0; j < count; j++)
                        printf(" %c = %d", nodeArr[j].c, nodeArr[j].v);
                    return 1;
                }
            }
        }
        return 0;
    }
    for (int i = 0; i < MAX_DIGIT; i++) {
        if (use[i] == 0) {
            nodeArr[n].v = i;
            use[i] = 1;
            if (permutation(count, nodeArr, n + 1, s1, s2, s3)) return 1;
            use[i] = 0;
        }
    }
    return 0;
}

int solve(char* s1, char* s2, char* s3) {
    int count = 0;
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int l3 = strlen(s3);
    int freq[MAX_CHAR] = {0};

    for (int i = 0; i < l1; i++) ++freq[s1[i] - 'A'];
    for (int i = 0; i < l2; i++) ++freq[s2[i] - 'A'];
    for (int i = 0; i < l3; i++) ++freq[s3[i] - 'A'];

    for (int i = 0; i < MAX_CHAR; i++)
        if (freq[i] > 0)
            count++;

    if (count > MAX_DIGIT) {
        printf("Invalid strings\n");
        return 0;
    }
    struct Node nodeArr[MAX_DIGIT];
    for (int i = 0, j = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            nodeArr[j].c = (char)(i + 'A');
            j++;
        }
    }
    return permutation(count, nodeArr, 0, s1, s2, s3);
}

int main() {
    char s1[] = "SEND";
    char s2[] = "MORE";
    char s3[] = "MONEY";
    if (solve(s1, s2, s3) == 0) printf("No solution\n");
    return 0;
}
