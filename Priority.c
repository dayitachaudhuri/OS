#include <stdio.h>

struct Process {
   int pid;
   int bt; 
   int priority; 
}typedef Process;

int waitingtime(Process pro[], int n, int wt[]) {
   wt[0] = 0;
   for (int i = 1; i < n ; i++ )
      wt[i] = pro[i-1].bt + wt[i-1] ;
    return 0;
}

int turnarround( Process pro[], int n, int wt[], int tat[]) {
   for (int i = 0; i < n ; i++)
      tat[i] = pro[i].bt + wt[i];
    return 0;
}

int avgtime(Process pro[], int n) {
   int wt[n], tat[n], total_wt = 0, total_tat = 0;
   waitingtime(pro, n, wt);
   turnarround(pro, n, wt, tat);
   printf(" \nProcesses    Burst_time   Waiting_time    Turnaround_time \n");

   for (int i=0; i<n; i++) {
        printf("%d     %d     %d    %d \n", pro[i].pid, pro[i].bt, wt[i],tat[i]);
        total_wt+=wt[i];
        total_tat+=tat[i];
   }
    printf("Average Waiting Time = %f \n", (float)total_wt/(float)n);
    printf("Average Turnaround Time = %f", (float)total_wt/(float)n);
    return 0;
}

int scheduling(Process pro[], int n) {
   for (int i=0; i<n; i++){
    for (int j=0; j<n-1-i; j++){
        if (pro[i].priority<pro[j].priority){
            Process temp=pro[i];
            pro[i]=pro[j];
            pro[j]=temp;
        }
    }
   }
    printf("Order in which processes gets executed \n");
    for (int i = 0 ; i < n; i++)
      printf("%d ", pro[i].pid) ;
    avgtime(pro, n);
    return 0;
}

int main() {
   Process pro[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
   int n = sizeof(pro) / sizeof(pro[0]);
   scheduling(pro, n);
   return 0;
}