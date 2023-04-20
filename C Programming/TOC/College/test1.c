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
            if(str[i]=='a')
            {
            	state = 'B';
            	printf("0");
			}
            else if(str[i]=='b')
            {
            	state = 'C';
            	printf("0");
			}
                
            break;
            
            case 'B':
            if(str[i]=='a')
            {
            	state = 'B';
            	printf("1");
			}
            else if(str[i]=='b')
            {
            	state = 'C';
            	printf("0");
			}
            break;

            case 'C':
            if(str[i]=='a')
            {
            	state = 'B';
            	printf("0");
			}
            else if(str[i]=='b')
            {
            	state = 'C';
            	printf("1");
			}
            break;
    	}	
    	
	}

}