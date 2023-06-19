#include <stdio.h>
//creating the structure of processes
struct process {
	char name;
	int at, bt, ct, wt, tt;
	int completed;
	float ntt;	
} p[10],p1[10];
int n,counter=0;
// Sorting Processes by Arrival Time
void sortByArrival()
{
	struct process temp;
	int i, j;
	// Selection Sort applied
	for (i = 0; i< n - 1; i++) {
		for (j = i + 1; j < n; j++) {
		if (p[i].at > p[j].at) {
	temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void main()
{
	int i, j, t, sum_bt = 0;
	char c;
	float avgwt = 0, avgtt = 0;
	n;
	printf("enter the value of n :");
	scanf("%d",&n);
	int arriv[n];
	printf("enter the arrival times of %d processes : ",n);
for(i=0;i<n;i++)
{
scanf("%d",&arriv[i]);
}
	int burst[n];
printf("enter the burst times of %d processes : ",n);
for(i=0;i<n;i++)
{
scanf("%d",&burst[i]);
}
	// Initializing the structure variables
	for (i = 0, c = 'A'; i< n; i++, c++) {
		p[i].name = c;
		p[i].at = arriv[i];
		p[i].bt = burst[i];
		p[i].completed = 0;
		sum_bt += p[i].bt;
	}

	// Sorting the structure by arrival times
	sortByArrival();

	for (t = p[0].at; t <sum_bt;) {
		// Set lower limit to response ratio
		float hrr = -9999;
		// Response Ratio Variable
		float temp;
		// Variable to store next process selected
		int loc;
		for (i = 0; i< n; i++) {
			// Checking if process has arrived and is Incomplete
			if (p[i].at <= t && p[i].completed != 1) {
				// Calculating Response Ratio
				temp = (float)(p[i].bt + (t - p[i].at)) / p[i].bt;
				printf("\nProcess %d and its response ratio: %0.3f",i,temp);
				// Checking for Highest Response Ratio
				if (hrr< temp) {
					// Storing Response Ratio
					hrr = temp;
					// Storing Location
					loc = i;
				}
			}
		}
		printf("\nProcess %d is selected \n\n",loc);
		// Updating time value
		t += p[loc].bt;
		// Calculation of waiting time
		p[loc].wt = t - p[loc].at - p[loc].bt;
		// Calculation of Turn Around Time
		p[loc].tt = t - p[loc].at;
		// Sum Turn Around Time for average
		avgtt += p[loc].tt;
		// Calculation of Normalized Turn Around Time
		p[loc].ntt = ((float)p[loc].tt / p[loc].bt);
		// Updating Completion Status
		p[loc].completed = 1;
		// Sum Waiting Time for average
		avgwt += p[loc].wt;
		p1[counter]=p[loc];
		counter++;
	}
	printf("\nName\tArrival Time\tBurst Time\tWaiting Time");
printf("\tTurnAround Time\t Normalized TT");
	for(i=0;i<n;i++)
	{
	printf("\n%c\t\t%d\t\t", p1[i].name, p1[i].at);
printf("%d\t\t%d\t\t", p1[i].bt, p1[i].wt);
printf("%d\t\t%f", p1[i].tt, p1[i].ntt);
	}
	printf("\nAverage waiting time:%f\n", avgwt / n);
	printf("Average Turn Around time:%f\n", avgtt / n);
}
