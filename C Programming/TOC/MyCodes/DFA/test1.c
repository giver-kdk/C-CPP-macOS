#include <stdio.h>
#include <stdlib.h>
int state = -1;
enum STATES{q0, q1};
char inputs[2] = {'0', '1'};
int initial = q0;
int final[] = {q1};
int n = 1;

void dq0(char input)
{
	if(input == inputs[0]) state = q0;
	else if(input == inputs[1]) state = q1;
	else state = -1;
}
void dq1(char input)
{
	if(input == inputs[0]) state = q0;
	else if(input == inputs[1]) state = q1;
	else state = -1;
}

int main()
{
	int i;
	char string[20], choice;
	while(choice != 'n' && choice != 'N')
	{
		int isAccepted = 0;
		fflush(stdin);
		printf("Enter the string: ");
		gets(string);
		state = initial;
		for(i = 0; string[i] != '\0'; i++)
		{
			if(state == q0) dq0(string[i]);
			else if(state == q1) dq1(string[i]);
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
		if(isAccepted == 0) printf("\nString Rejected");
		if(state == -1) printf("\nInvalid String");
		printf("COntinue? (Y/N): ");
		scanf(" %c", &choice);
	}
	return 0;
}
