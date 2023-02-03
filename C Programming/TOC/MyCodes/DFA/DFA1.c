// Program to design DFA that accepts set of all strings ending with 1 
#include <stdio.h>
int state = -1;						// Current State
enum STATES{q0, q1};				// Set of all states
char inputs[2] = {'0', '1'};		// Set of all inputs
int initial = q0;					// Initial State
int final = q1;						// Set of Final States

void transition_q0(char input)
{
	if(input == inputs[0]) state = q0;
	else if(input == inputs[1]) state = q1;
	else state = -1;
}
void transition_q1(char input)
{
	if(input == inputs[0]) state = q0;
	else if(input == inputs[1]) state = q1;
	else state = -1;
}

int main()
{
	int i;
	char string[20];
	char choice;

	while(choice != 'n' && choice != 'N')
	{
		fflush(stdin);
		printf("\nEnter a string: ");
		gets(string);				// Reads Character even after whitespace
		state = initial;			// Initialize state
		for(i = 0; string[i] != '\0'; i++)
		{
			if(state == q0) transition_q0(string[i]);
			else if(state == q1) transition_q1(string[i]);
			else break;
		}
		if(state == final) printf("\nString Accepted");
		else printf("\nString Rejected");
		if(state == -1) printf("\nInvalid String");
		printf("\nContinue? (Y/N): ");
		scanf(" %c", &choice);
	}
	return 0;
}

