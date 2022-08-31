/* Program to print instructions for solving tower of Hanoi in C using recursion.
Steps:
1) Move top (n - 1) disks from start to mid rod
2) Move last one disk from start to end rod
3) Move top (n - 1) disks from mid to end rod
Execute the above steps recursively. */
#include <stdio.h>
#include <math.h>

void transfer(char S, char A, char T, int n)
{
	// Base condition to finish recursion
	if (n == 1)
	{
		printf("Move disk %d from peg %c to peg %c\n", n, S, T);
	}
	else
	{
		// Step 1
		transfer(S, T, A, n - 1);
		// Step 2
		printf("Move disk %d from peg %c to peg %c\n", n, S, T);
		// Step 3
		transfer(A, S, T, n - 1);
	}
}

int main()
{
	int number;
	printf("Enter the number of disks: ");
	scanf("%d", &number);
	transfer('A', 'B', 'C', number); // A, B and C are rods
	// Number of steps is always (2^n) - 1
	printf("Total numebr of steps: %.0f\n", (pow(2, number) - 1));
	return 0;
}