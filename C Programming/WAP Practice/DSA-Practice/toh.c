#include <stdio.h>
#include <stdlib.h>

void toh(int num, char start, char finish, char mid)
{
	if(num == 0)
	{
		return;
	}
	toh(num - 1, start, mid, finish);
	printf("Move disk %d from rod %c to rod %c\n", num, start, finish);
	toh(num - 1, mid, finish, start);
}

int main()
{
	int num;
	printf("Enter the numnber of disks: ");
	scanf("%d", &num);
	toh(num, 'A', 'C', 'B');
	return 0;
}