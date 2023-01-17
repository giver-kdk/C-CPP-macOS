#include <stdio.h>
#include <math.h>

void toh(int num, char start, char finish, char mid)
{
	if(num == 0) return;

	toh(num - 1, start, mid, finish);
	printf("\nMove disk %d from %c to %c", num, start, finish);
	toh(num - 1, mid, finish, start);
}

int main()
{
	int num;
	printf("Enter the number of disks: ");
	scanf("%d", &num);
	toh(num, 'A', 'C', 'B');
	return 0;
}