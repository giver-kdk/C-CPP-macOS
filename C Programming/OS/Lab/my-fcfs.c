#include <stdio.h>

struct Process
{
	int AT;
	int BT;
	int CT;
	int TAT;
	int WT;
	int finished;
} p[20];

int minimumAT(struct Process pro[20], int n)
{
	int min, i, j;
	for (i = 0; i < n; i++)
	{
		if (pro[i].finished == 0)
		{
			min = pro[i].AT;
			for (j = 0; j < n; j++)
			{
				if (min > pro[j].AT && pro[j].finished == 0) min = pro[j].AT;
			}
			break;
		}
	}
	return min;
}
int main()
{
	int n, avWT = 0, avTAT = 0, minAT = 0, i, j, notComplete = 1;
	printf("Enter total number of processes:");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("\nEnter Process Arrival Time\n");
		printf("P[%d]:", i + 1);
		scanf("%d", &p[i].AT);
		printf("\nEnter Process Burst Time\n");
		printf("P[%d]:", i + 1);
		scanf("%d", &p[i].BT);
		p[i].finished = 0; // Initial Process Status
	}
	minAT = minimumAT(p, n);
	// printf("%d\n", minAT);

	// Printing Gantt Chart
	int startAT = minAT;
	int time = minAT;
	int currTime = time;
	while (notComplete == 1)
	{
		for (i = 0; i < n; i++)
		{
			minAT = minimumAT(p, n);
			// printf("%d\n", minAT);
			if (p[i].finished == 0 && p[i].AT == minAT && time >= minAT)
			{
				if (time != startAT)
					printf("-->");
				printf("P%d(%d-%d)", i + 1, currTime, currTime + p[i].BT);
				currTime = currTime + p[i].BT;
				p[i].CT = currTime;
				p[i].finished = 1;
			}
		}
		if (currTime == time)
		{
			time++;
			currTime++;
		}
		else time = currTime;
		notComplete = 0;

		for (j = 0; j < n; j++)
		{
			if (p[j].finished == 0) notComplete = 1;
		}
	}

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