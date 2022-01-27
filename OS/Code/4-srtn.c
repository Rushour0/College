#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} process_details;

void sortP_byAT(process_details *processes, int n)
{
    int i, j;
    process_details temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void sortP_byRT(process_details *processes, int n)
{
    int i, j;
    process_details temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].remaining_time > processes[j + 1].remaining_time)
            {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int ifOver(process_details *processes, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (processes[i].remaining_time > 0)
        {
            return 0;
        }
    }
    return 1;
}

void accept(process_details *process, int i, int *bt, int *at)
{
    process->id = i;
    printf("Process %d:  ", i);
    printf("Enter the arrival time of the process: ");
    scanf("%d", &process->arrival_time);
    at[i] = process->arrival_time;
    printf("Enter the burst time of the process: ");
    scanf("%d", &process->burst_time);
    bt[i] = process->burst_time;
    process->remaining_time = process->burst_time;
}

void display(process_details *process)
{
    printf("Process %d:  ", process->id);
    printf("Arrival time: %d  ", process->arrival_time);
    printf("Burst time: %d  ", process->burst_time);
    printf("Completion time: %d  ", process->completion_time);
    printf("Remaining time: %d  ", process->remaining_time);
    printf("\n");
}

int main()
{
    process_details details[10];
    int n;
    printf("Input the number of processes to be added : ");
    scanf("%d", &n);
    int *bt, *wt, *at, *tt, *ct, *done;
    bt = (int *)malloc(n * sizeof(int));
    done = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    at = (int *)malloc(n * sizeof(int));
    tt = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    int time, lbt;
    for (int i = 0; i < n; i++)
            {
                accept(&details[i], i, bt, at);
            }
    int ch;
    do
    {
        printf("\nMenu:\n1.Non-PreEmptive SFJ\n2.Pre-Emtive SFJ\n3.To Quit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        
        switch (ch)
        {
        case 1:
            lbt = 0;
            for (int i = 0; i < n; i++)
            {
                if (bt[i] > bt[lbt])
                {
                    lbt = i;
                }
                done[i] = 0;
            }

            int temp;
            for (int s = 0; s < n - 1; s++)
            {
                for (int t = 0; t < n - s - 1; t++)
                {
                    if (at[t] > at[t + 1])
                    {
                        temp = at[t];
                        at[t] = at[t + 1];
                        at[t + 1] = temp;

                        temp = bt[t];
                        bt[t] = bt[t + 1];
                        bt[t + 1] = temp;
                        if (t == lbt)
                        {
                            lbt++;
                        }
                    }
                }
            }

            int sum_bt = 0, sum_wt = 0;
            printf("\nGant Chart:\n");
            time = 0;
            int j = 0;
            while (1)
            {
                for (int i = 1; i < n; i++)
                {
                    if (done[i] == 0 && at[i] <= time && bt[j] > bt[i])
                    {
                        j = i;
                    }
                }
                if (j == lbt && done[j] != 0)
                {
                    break;
                }
                wt[j] = sum_bt - at[j];
                if (wt[j] < 0)
                {
                    printf("%d ---IDLE--- ", sum_bt, j);
                    sum_bt += -wt[j];
                    wt[j] = 0;
                }
                printf("%d ---P%d--- ", sum_bt, j);
                done[j] = 1;
                time += bt[j];
                ct[j] = time;
                sum_bt += bt[j];
                sum_wt += wt[j];
                j = lbt;
            }
            printf("%d\n\n", sum_bt);

            int sum_tt = 0;
            for (int k = 0; k < n; k++)
            {
                tt[k] = ct[k] - at[k];
                sum_tt += tt[k];
            }

            float average_wt = (sum_wt) / (n * 1.0);
            float average_tt = (sum_tt) / (n * 1.0);

            printf("Processes  Burst Time  Arrival Time  Waiting Time  Turn-around Time  Completion Time\n");
            for (int l = 0; l < n; l++)
            {
                printf("    P%d          %d            %d             %d              %d                %d       \n", l, bt[l], at[l], wt[l], tt[l], ct[l]);
            }

            printf("Average waiting time : %f\n", average_wt);
            printf("Average turnaorund time : %f\n", average_tt);
            break;

        case 2:
            sortP_byAT(details, n);
            time = 0;
            sortP_byRT(details, n);

            int curr_pri_i = -1;

            printf("\n\nGNATT CHART:-\n");
            while (1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (details[i].arrival_time <= time)
                    {

                        if (details[i].remaining_time > 0)
                        {
                            if (i != curr_pri_i)
                            {
                                curr_pri_i = i;
                                printf("%d----P%d----", time, details[i].id);
                            }
                            details[i].remaining_time--;
                            if (details[i].remaining_time == 0)
                            {
                                details[i].completion_time = time + 1;
                                details[i].turnaround_time = details[i].completion_time - details[i].arrival_time;
                                details[i].waiting_time = details[i].turnaround_time - details[i].burst_time;
                            }
                            break;
                        }
                    }
                }
                time++;
                sortP_byRT(details, n);
                if (ifOver(details, n))
                {
                    break;
                }
            }
            printf("%d\n", time);
            int total_waiting_time = 0;
            int total_turnaround_time = 0;
            printf("\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");

            for (int i = 0; i < n; i++)
            {
                printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, details[i].burst_time, details[i].arrival_time, details[i].waiting_time, details[i].turnaround_time, details[i].completion_time);
                total_waiting_time += details[i].waiting_time;
                total_turnaround_time += details[i].turnaround_time;
            }
            printf("\nAverage waiting time = %f\n", (float)total_waiting_time / n);
            printf("Average turnaround time = %f\n", (float)total_turnaround_time / n);

            break;

        default:
            printf("Quitting\n");
            break;
        }
    } while (ch > 0 && ch < 3);

    return 0;
}
/*
5
0
3
1
1
2
2
7
4
8
2
*/