/*
Name: Rushikesh Patade
Batch: G2
Roll no.: PG19
*/

#include <stdio.h>
#include <stdlib.h>

#define line printf("\n");
#define clrscr system("clear || cls");

// Structure Process - Defintion
typedef struct {
    int pid, at, bt, ct, tat, wt;
} Process;

// Structure Process related functions
void readJobs(Process*, int);
void calculateJobs(Process*, int);
void displayJobs(Process*, int);

// Helper function declarations
void sortByArrivalTime(Process*, int);
void sortByBurstTimeRemaining(Process*, int, int);
void swapNum(Process* ,int, int);

// main function - driver code
int main()
{
    clrscr
    int n;

    // Take input
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    Process jobs[n];

    // Reading at & bt
    readJobs(jobs, n);
    clrscr
    
    // Sorting the arrival time to calculate
    sortByArrivalTime(jobs, n);

    // Calculating properties
    calculateJobs(jobs, n);

    // Display final
    displayJobs(jobs, n);

    return 0;
}

// Function definition - readJobs
void readJobs(Process *jobs, int n)
{
    for( int i = 0; i < n; i++ )
    {
        printf("Enter the arrival time for process : ");
        scanf("%d", &jobs[i].at);
        printf("Enter the burst time for process : ");
        scanf("%d", &jobs[i].bt);
        jobs[i].pid = i;
        jobs[i].ct = 0;
        jobs[i].wt = 0;
        jobs[i].tat = 0;
    }
}

// Function defintion - calculateJobs
void calculateJobs(Process *jobs, int n)
{
    Process temps[n];
    for( int i = 0; i < n; i++ )
    {
        temps[i].at = jobs[i].at;
        temps[i].bt = jobs[i].bt;
        temps[i].pid = jobs[i].pid;
        temps[i].ct = jobs[i].ct;
        temps[i].wt = jobs[i].wt;
        temps[i].tat = jobs[i].tat;
    }

    int current, current_ct = 0;

    for( int i = 0; i < n-1; i++)
    {
        current = temps[i+1].at - temps[i].at;
        if ( >  
    }

    for( int i = 0; i < n; i++ )
    {   
        if ( i > 0 && jobs[i-1].ct > jobs[i].at )
            current_ct = current_ct + jobs[i].bt;
        else
            current_ct = jobs[i].at + jobs[i].bt;
        jobs[i].ct = current_ct;
        jobs[i].tat = jobs[i].ct - jobs[i].at;
        
        if (jobs[i].tat > jobs[i].bt)
            jobs[i].wt = jobs[i].tat - jobs[i].bt;
    }
}

// Function definition - displayJobs
void displayJobs(Process *jobs, int n)
{
    int tat_avg = 0;
    int wt_avg = 0;

    // Tabular form
    printf("Tabular form");line
    printf("PID\t\tAT\tBT\tCT\tWT\tTAT\n");
    for( int i = 0; i < n; i++ )
    {
        printf("%d\t\t%d\t%d\t%d\t%d\t%d\n", jobs[i].pid, jobs[i].at, jobs[i].bt, jobs[i].ct, jobs[i].wt, jobs[i].tat);
        tat_avg = tat_avg + jobs[i].tat;
        wt_avg = wt_avg + jobs[i].wt;
    }
    line line

    // Graphical form
    
    printf("Graphical form");line
    for( int i = 0; i < n; i++ )
    {
        if ( i > 0 && jobs[i-1].ct <= jobs[i].at )
            printf("\tIDLE\t");
        printf("\tP%d\t",jobs[i].pid);
    }
    line

    printf("||0|");
    for( int i = 0; i < n; i++ )
    {
        if ( i > 0 && jobs[i-1].ct <= jobs[i].at )
            printf("\t\t|%d|",jobs[i].at);
        printf("\t\t|%d|", jobs[i].ct);
    }
    
    printf("|");
    line line
    printf("Average TAT : %d", tat_avg / n);line
    printf("Average WT : %d", wt_avg / n);line
}

// Function definition - sortByArrivalTime
void sortByArrivalTime(Process *jobs, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
		{
			if(jobs[j-1].at > jobs[j].at) 
				swapNum(jobs, j-1, j);
		}
}

// Function definition - swapNum
void swapNum(Process *jobs,int p1, int p2)
{
	Process temp = jobs[p1];
	jobs[p1] =  jobs[p2];
	jobs[p2] = temp;
}
