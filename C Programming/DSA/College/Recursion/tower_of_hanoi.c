/* Program to print instructions for solving tower of Hanoi in C using recursion.
Steps:
1) Move top (n - 1) disks from start to mid rod
2) Move last one disk from start to end rod
3) Move top (n - 1) disks from mid to end rod
Execute the above steps recursively. 
This program is simple and straight forward according to algorithm */
#include <stdio.h>
#include <math.h>

void printInstruction(int num, char start, char finish, char mid)
{
	// Base condition to finish recursion
	if (num == 0) return;
	else
	{
		// Step 1: Move top (n - 1) from start to mid
		printInstruction((num - 1), start, mid, finish);
		// Step 2: Move last(num) from start to finish
		printf("Move disk %d from rod %c to rod %c\n", num, start, finish);
		// Step 3: Move top (n - 1) from mid to finish
		printInstruction((num - 1), mid, finish, start);
	}
}

int main()
{
	int number;
	printf("Enter the number of disks: ");
	scanf("%d", &number);
	printInstruction(number, 'A', 'C', 'B'); // A, B and C are rods
	// Number of steps is always (2^n) - 1
	printf("Total number of steps: %.0f\n", (pow(2, number) - 1));
	return 0;
}