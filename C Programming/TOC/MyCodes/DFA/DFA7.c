// Program to design DFA that accepts set of all strings starting and ending with same symbols
#include <stdio.h>
int state = -1;						
enum STATES{q0, q1, q2, q3, q4};				
char inputs[2] = {'a', 'b'};		
int initial = q0;					
int final[] = {q2, q4};				// Set of final states
int n = 2;							// No. of final states

void transition_q0(char input)
{
	if(input == inputs[0]) state = q1;
	else if(input == inputs[1]) state = q3;
	else state = -1;
}
void transition_q1(char input)
{
	if(input == inputs[0]) state = q2;
	else if(input == inputs[1]) state = q1;
	else state = -1;
}
void transition_q2(char input)
{
	if(input == inputs[0]) state = q2;
	else if(input == inputs[1]) state = q1;
	else state = -1;
}
void transition_q3(char input)
{
	if(input == inputs[0]) state = q3;
	else if(input == inputs[1]) state = q4;
	else state = -1;
}
void transition_q4(char input)
{
	if(input == inputs[0]) state = q3;
	else if(input == inputs[1]) state = q4;
	else state = -1;
}

int main()
{
	int i;
	char string[20];
	char choice;

	while(choice != 'n' && choice != 'N')
	{
		int isAccepted = 0;
		fflush(stdin);
		printf("Enter a string: ");
		gets(string);				// Reads Character even after whitespace

		state = initial;			// Initialize state
		for(i = 0; string[i] != '\0'; i++)
		{
			if(state == q0) transition_q0(string[i]);
			else if(state == q1) transition_q1(string[i]);
			else if(state == q2) transition_q2(string[i]);
			else if(state == q3) transition_q3(string[i]);
			else if(state == q4) transition_q4(string[i]);
			else break;
		}
		for(i = 0; i < n; i++)
		{
			if(state == final[i])
			{
				printf("\nString Accepted");
				isAccepted = 1;
				break;
			}
		}
		if(isAccepted == 0) printf("\nString Rejected");
		if(state == -1) printf("\nInvalid String");
		printf("\nContinue? (Y/N): ");
		scanf(" %c", &choice);
	}
	return 0;
}

