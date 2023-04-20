#include <stdio.h>
#define max 10
int main()
{
    char str[max], state='A';
    int i;
    printf("Enter the string: ");
    scanf("%s", str);
    for(i=0;str[i]!='\0';i++)
    {
    	switch(state)
        {
            case 'A':
            if(str[i]=='0')
            {
            	state = 'A';
            	printf("c");
			}
            else if(str[i]=='1')
            {
            	state = 'B';
            	printf("c");
			}
            break;
            
            case 'B':
            if(str[i]=='0')
            {
            	state = 'D';
			}
            else if(str[i]=='1')
            {
            	state = 'C';
			}
            break;

            case 'C':
            if(str[i]=='0')
            {
            	state = 'D';
			}
            else if(str[i]=='1')
            {
            	state = 'C';
			}
            break;
            
            case 'D':
            if(str[i]=='0')
           	{
            	state = 'A';
			}
            else if(str[i]=='1')
            {
            	state = 'B';
			}
            break;
    	}	
    	if(state=='B')
		{
			printf("c");
		}
		else if(state=='D')
		{
			printf("a");
		}
		else if(state=='C')
		{
			printf("b");
		}
	}

}