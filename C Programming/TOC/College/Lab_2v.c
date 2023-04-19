// Program to design NFA that accepts set of all strings ending with 01
#include <stdio.h>
int state[50];				
int s = 0;						// No. of resultant states		
enum STATES{q0, q1, q2, dead};				
char inputs[2] = {'0', '1'};		
int initial = q0;					
int final[] = {q2};				// Set of final states
int n = 1;						// No. of final states
int len0 = 0, len1 = 0, len2 = 0, k;

int * tq0(char input)
{
	int newState[100];
	len0 = 0;
	if(input == inputs[0]){
		newState[len0++] = q0;
		newState[len0++] = q1;
	}
	else if(input == inputs[1]){
		newState[len0++] = q0;
	}
	return newState;
}
int * tq1(char input)
{
	int newState[100];
	len1 = 0;
	if(input == inputs[0]){
		newState[len1++] = dead;
	}
	else if(input == inputs[1]){
		newState[len1++] = q2;
	}
	return newState;
}
int * tq2(char input)
{
	int newState[100];
	len2 = 0;
	if(input == inputs[0] || input == inputs[1]){
		newState[len2++] = dead;
	}
	return newState;
}

int main()
{
	int i, j;
	char string[20];
	char choice;

	while(choice != 'n' && choice != 'N')
	{
		int isAccepted = 0;
		fflush(stdin);
		printf("Enter a string: ");
		gets(string);				// Reads Character even after whitespace

		state[s++] = initial;			// Initialize state
		for(i = 0; string[i] != '\0'; i++)
		{
			int *newState;
			// k = 0;
			for(j = 0; j < s; j++)
			{
				int *currentState;
				if(state[j] == q0) currentState = tq0(string[i]);
				else if(state[j] == q1) currentState = tq1(string[i]);
				else if(state[j] == q2) currentState = tq2(string[i]);
				newState = concat_array(newState, currentState, s, len0);
			}
			
			// if(state == q0) transition_q0(string[i]);
			// else if(state == q1) transition_q1(string[i]);
			// else if(state == q2) transition_q2(string[i]);
			// else if(state == q3) transition_q3(string[i]);
			// else break;
		}
		// for(i = 0; i < n; i++)
		// {
		// 	if(state == final[i])
		// 	{
		// 		printf("\nString Accepted");
		// 		isAccepted = 1;
		// 		break;
		// 	}
		// }
		// if(isAccepted == 0) printf("\nString Rejected");
		// if(state == -1) printf("\nInvalid String");
		printf("\nContinue? (Y/N): ");
		scanf(" %c", &choice);
	}
	printf("\n***** Name: Giver Khadka *****");
	return 0;
}


int * concat_array(int array1[50], int array2[50], int len1, int len2)
{
	int i, j = 0, result[50];
	for(i = 0; i < len1; i++)
	{
		result[j] = array1[i];
		i++;
		j++;
	}
	for(i = 0; i < len2; i++)
	{
		result[j] = array2[i];
		i++;
		j++;
	}
	s = j;								// Updated Number of states 
	return result;
}