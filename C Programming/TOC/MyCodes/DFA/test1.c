#include <stdio.h>
int state = -1;
enum STATES{q0, q1, q2, q3, q4};
char inputs[2] = {'a', 'b'};
int initial = q0;
int final[] = {q2, q4};
int n = 2;

void t_q0(char input)
{
	if(input == inputs[0]) state = q1;
	else if(input == inputs[1]) state = q3;
	else state = -1;
}
void t_q1(char input)
{
	if(input == inputs[0]) state = q1;
	else if(input == inputs[1]) state = q2;
	else state = -1;
}
void t_q2(char input)
{
	if(input == inputs[0]) state = q4;
	else if(input == inputs[1]) state = q2;
	else state = -1;
}
void t_q3(char input)
{
	if(input == inputs[0]) state = q4;
	else if(input == inputs[1]) state = q3;
	else state = -1;
}
void t_q4(char input)
{
	if(input == inputs[0]) state = q4;
	else if(input == inputs[1]) state = q3;
	else state = -1;
}


int main()
{
	int i;
	char choice, string[20];

	while(choice != 'n' && choice != 'N')
	{
		int isAccepted = 0;
		fflush(stdin);

		printf("Enter the string: ");
		gets(string);

		state = initial;
		for(i = 0; string[i] != '\0'; i++) 
		{
			if(state == q0) t_q0(string[i]);
			else if(state == q1) t_q1(string[1]);
			else if(state == q2) t_q2(string[1]);
			else if(state == q3) t_q3(string[1]);
			else if(state == q4) t_q4(string[1]);
			else break;
		}
		for(i = 0; i < n; i++)
		{
			if(state == final[i])
			{
				isAccepted = 1;
				printf("\nString Accepted");
				break;
			}
		}
		if(isAccepted == 0) printf("\n String Rejected");
		if(state == -1) printf("\nInvalid String");

		printf("Continue? (Y/N): ");
		scanf(" %c", &choice);
	}
}