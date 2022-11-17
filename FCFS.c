#include <stdio.h>

int waitingTime(int proc[], int bt[], int wt[], int n)
{
    wt[0]=0;
    for (int i=1; i<n; i++)
        wt[i]=wt[i-1]+bt[i-1];
    return 0;
}

int turnaroundTime(int proc[], int bt[], int wt[], int tat[], int n)
{
    for (int i=0; i<n; i++)
        tat[i]=wt[i]+bt[i];
    return 0;
}

int avgTime(int proc[], int bt[], int n)
{
    int wt[n], tat[n], avg_wt=0, avg_tat=0;
    waitingTime(proc,bt,wt,n);
    turnaroundTime(proc,bt,wt,tat,n);
    printf("Process  Burst_Time  Waiting_Time  Turnaround_Time \n");
    for (int i=0; i<n; i++)
    {
        printf("%d            %d            %d            %d \n", proc[i], bt[i], wt[i], tat[i]);
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }
    printf("Average Waiting Time = %f \n", (float)avg_wt/(float)n);
    printf("Average Turnaround Time = %f", (float)avg_tat/(float)n);
    return 0;
}

int main() {
    // Write C code here
    int proc[]={1,2,3};
    int n=3;
    int bt[]={3,5,6};
    avgTime(proc,bt,n);
    return 0;
}
