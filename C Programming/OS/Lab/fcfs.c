// Gantt Chart:P1(0-15)-> P2(15-17)
#include<stdio.h>

struct Process
{
    int pid;
    int bt;
    int wt;
    int at;
    int tat;
}p[20];

 int main()

{
    int n,avwt=0,avtat=0,i,j;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter Process Arrival Time\n");
        printf("P[%d]:",i+1);
        scanf("%d",&p[i].at);
        printf("\nEnter Process Burst Time\n");
        printf("P[%d]:",i+1);
        scanf("%d",&p[i].bt);
    }


    p[0].wt=0;

    for(i=1;i<n;i++)
    {
        p[i].wt=0;
        for(j=0;j<i;j++)
        {
            p[i].wt+=p[j].bt;
        }
    }

    //Printing Gantt Chart
    int currAt = 0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n;j++)
        {
            if(currAt < p[j].at)
            {
                currAt = p[j].at;
            }
        }
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++)
    {
        p[i].tat=p[i].bt+p[i].wt;
        avwt+=p[i].wt;
        avtat+=p[i].tat;
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,p[i].bt,p[i].wt,p[i].tat);
    }

    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);

    return 0;
}
