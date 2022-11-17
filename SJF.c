#include <stdio.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int waitingTime(int mat[][4], int n)
{
    mat[2][0]=0;
    for (int i=1; i<n; i++)
        mat[2][i]=mat[2][i-1]+mat[1][i-1];
    return 0;
}

int turnaroundTime(int mat[][4], int n)
{
    for (int i=0; i<n; i++)
        mat[3][i]=mat[1][i]+mat[2][i];
    return 0;
}
int avgtime(int mat[][4], int n) {
    int total_tat=0, total_wt=0;
   waitingTime(mat, n);
   turnaroundTime(mat, n);
   printf(" \nProcesses    Burst_time   Waiting_time    Turnaround_time \n");

   for (int i=0; i<n; i++) {
        printf("%d     %d     %d    %d \n", mat[0][i], mat[1][i], mat[2][i], mat[3][i]);
        total_wt+=mat[2][i];
        total_tat+=mat[3][i];
   }
    printf("Average Waiting Time = %f \n", (float)total_wt/(float)n);
    printf("Average Turnaround Time = %f", (float)total_tat/(float)n);
    return 0;
}

int scheduling(int mat[][4], int n) {
   for (int i=0; i<n; i++){
    for (int j=0; j<n-1-i; j++){
        if (mat[1][i]>mat[1][j]){
            for (int k=0; k<4; k++){
                swap(&mat[k][i],&mat[k][j]);
            }
        }
    }
   }
    printf("Order in which processes gets executed \n");
    for (int i = 0 ; i < n; i++)
      printf("%d ", mat[0][i]) ;
    avgtime(mat, n);
    return 0;
}

int main() {
   int mat[][4] = {{1, 2, 3}, {3, 6, 4}, {0, 0, 0}, {0, 0, 0}};
   scheduling(mat, 3);
   return 0;
}