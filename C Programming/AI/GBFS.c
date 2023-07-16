#include <stdio.h>
#define MAX_NODES 10
typedef struct {
    int heu;					// Heuristic
    int visited;
    int adj[MAX_NODES - 1];		// Adjacent Vertices List
} Node;

int gbfs(Node graph[], int start, int goal) {
    int current = start;
    graph[current].visited = 1;
    printf("Path: %d ", current);

    int cost = 0; // Initialize the cost to 0

    while (current != goal) {
        int graphVertex = graph[current].adj[0];
        int next = graphVertex;
        int minHeu = graph[graphVertex].heu;
        // Go to unvisited adjacent node with the smallest heuristic value
        for (int i = 0; graph[current].adj[i] != -1; i++) {
            int vertex = graph[current].adj[i];
            if (graph[vertex].heu < minHeu && graph[vertex].visited == 0) {
                minHeu = graph[vertex].heu;
                next = vertex;
            }
        }
        graph[next].visited = 1;
        printf("-> %d ", next);
        current = next;

        cost++; // Increment the cost after moving to the next node
    }
    printf("\n");
    printf("Cost: %d\n", cost); // Print the cost to reach the goal
    return current;
}

int main() {
    Node graph[MAX_NODES];
    // Set the heu values for each node (example values)
    graph[0].heu = 270;
    graph[1].heu = 264;
    graph[2].heu = 178;
    graph[3].heu = 142;
    graph[4].heu = 364;
    graph[5].heu = 278;
    graph[6].heu = 165;
    graph[7].heu = 146;
    graph[8].heu = 54;
    graph[9].heu = 0;
    // Set all nodes as unvisited
    for (int i = 0; i < MAX_NODES; i++) {
        graph[i].visited = 0;
        for (int j = 0; j < MAX_NODES - 1; j++) {			// Adjacent nodes can have max N-1 nodes
            graph[i].adj[j] = -1;
        }
    }
    // Set Adjacent vertices list for individual nodes (Make graph on paper)
    graph[0].adj[0] = 1;
    graph[0].adj[1] = 2;
    graph[1].adj[0] = 0;
    graph[1].adj[1] = 4;
    graph[2].adj[0] = 0;
    graph[2].adj[1] = 3;
    graph[2].adj[2] = 6;
    graph[3].adj[0] = 2;
    graph[3].adj[1] = 8;
    graph[3].adj[2] = 9;
    graph[4].adj[0] = 1;
    graph[4].adj[1] = 5;
    graph[5].adj[0] = 4;
    graph[5].adj[1] = 6;
    graph[5].adj[2] = 7;
    graph[6].adj[0] = 2;
    graph[6].adj[1] = 5;
    graph[6].adj[2] = 8;
    graph[7].adj[0] = 5;
    graph[7].adj[1] = 8;
    graph[8].adj[0] = 3;
    graph[8].adj[1] = 6;
    graph[8].adj[2] = 7;
    graph[8].adj[3] = 9;
    graph[9].adj[0] = 3;
    graph[9].adj[1] = 8;

    int startNode = 0;
    int goalNode = 9;
    printf("Greedy Best-First Search Path:\n");
    int finalNode = gbfs(graph, startNode, goalNode);
    printf("Goal node reached: %d\n", finalNode);
    return 0;
}
