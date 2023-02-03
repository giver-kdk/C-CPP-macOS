// Program to design DFA that accepts set of all strings of atleast 2 length
#include <stdio.h>
int state = -1;						
enum STATES{q0, q1, q2};				
char inputs[2] = {'a', 'b'};		
int initial = q0;					
int final = q2;					

void transition_q0(char input)
{
	if(input == inputs[0] || input == inputs[1]) state = q1;
	else state = -1;
}
void transition_q1(char input)
{
	if(input == inputs[0] || input == inputs[1]) state = q2;
	else state = -1;
}
void transition_q2(char input)
{
	if(input == inputs[0] || input == inputs[1]) state = q2;
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
		printf("Enter a string: ");
		gets(string);				// Reads Character even after whitespace

		state = initial;			// Initialize state
		for(i = 0; string[i] != '\0'; i++)
		{
			if(state == q0) transition_q0(string[i]);
			else if(state == q1) transition_q1(string[i]);
			else if(state == q2) transition_q2(string[i]);
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

