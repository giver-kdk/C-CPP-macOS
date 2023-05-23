#include <stdio.h>

struct Process
{
	int AT;
	int BT;
	int tempBT;
	int CT;
	int TAT;
	int WT;
	int finished;
} p[20];
// Find current process id with minimum Burst Time
int minimumBT(struct Process pro[20], int n, int time)
{
	int id, min, i, j;
	for (i = 0; i < n; i++)
	{
		if (pro[i].finished == 0 && pro[i].AT <= time)
		{
			min = pro[i].BT;
			id = i;
			for (j = 0; j < n; j++)
			{
				if (min > pro[j].BT && pro[j].finished == 0 && pro[j].AT <= time)
				{
				 	min = pro[j].BT;
					id = j;
				}
			}
			break;
		}
	}
	return id;
}
int main()
{
	int n, avWT = 0, avTAT = 0, minAtId = 0, minAT = 0, minBtPid = 0, i, j, notComplete = 1;
	printf("Enter total number of processes:");
	scanf("%d", &n);
	// User input
	for (i = 0; i < n; i++)
	{
		printf("\nEnter Process Arrival Time\n");
		printf("P[%d]:", i + 1);
		scanf("%d", &p[i].AT);
		printf("\nEnter Process Burst Time\n");
		printf("P[%d]:", i + 1);
		scanf("%d", &p[i].BT);
		p[i].tempBT = p[i].BT;
		if(minAT > p[i].AT)
		{
			minAT = p[i].AT;							 // Find minimum arrival time during input
			minAtId = i;
		}
		p[i].finished = 0; 								// Initial Process Status
	}

	// SRTF Logic Gantt Chart
	int startAT = minAT;
	int time = minAT;
	int currTime = time;
	while (notComplete == 1)
	{
		minBtPid = minimumBT(p, n, currTime);
		for (i = 0; i < n; i++)
		{
			// Select un-executed process with minimum AT
			if (p[i].finished == 0 && minBtPid == i && time >= minAT)
			{
				if (time != startAT) printf(" --> ");
				printf("P%d(%d-%d)", i + 1, currTime, currTime + 1);
				currTime++;										// Increment time by 1 unit only
				p[i].CT = currTime;
				p[i].tempBT--;									// Decrement temporary burst time by 1 unit 
				if(p[i].tempBT == 0) p[i].finished = 1;
			}
		}
		if (currTime == time)
		{
			time++;
			currTime++;
		}
		else time = currTime;
		notComplete = 0;
		// Check if all processes are finished executing
		for (j = 0; j < n; j++)
		{
			if (p[j].finished == 0) notComplete = 1;
		}
	}
	// Display calculated output
	printf("\nProcess\t\tCompletion Time\t\tTurnaround Time\t\tWaiting Time");
	for (i = 0; i < n; i++)
	{
		p[i].TAT = p[i].CT - p[i].AT;
		p[i].WT = p[i].TAT - p[i].BT;
		avTAT += p[i].TAT;
		avWT += p[i].WT;
		printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t%d", i + 1, p[i].CT, p[i].TAT, p[i].WT);
	}
	avTAT /= n;
	avWT /= n;
	printf("\nAverage Turnaround Time:%d", avTAT);
	printf("\nAverage Waiting Time:%d\n", avWT);
}