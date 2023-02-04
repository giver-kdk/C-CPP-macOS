#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int i, state=1;
    printf("Enter any string of containing a and b\n ");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
        switch(state)
        {
            case 0:
            if(str[i]=='a')
                state=1;
            else if(str[i]=='b')
                state=0;
            break;
            case 1:
            if(str[i]=='a')
                state=0;
            else if(str[i]=='b')
                state=1;
            break;
        }
    }
    if(state==1)
    {
        printf("\nstring is accepted as it contains even no. of a's");
    }
    else
    {
        printf("%s Rejected.\n", str);
    }
}