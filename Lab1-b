#include<stdio.h>

int n;
int bt[100],process[100],wt[100],tat[100];

void calc_waiting_time_and_turnaround_time()
{
    float wtavg=0;
    float tatavg=0;
    tat[0]=bt[0];
    wt[0]=0;
    for(int i=1;i<=n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
        tat[i]=tat[i-1]+bt[i];
        wtavg=wtavg+wt[i];
        tatavg=tatavg+tat[i];
        printf("%d\t%d\t%d\t%d\t",process[i],bt[i],tat[i],wt[i]);
        printf("\n");

    }
    
        printf("The average waiting time is: %f",wtavg/n);
        printf("The average turnaround time is: %f",tatavg/n);
}

void main()
{
    int temp,tp;
    printf("This is SJF Scheduling\n");
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        process[i]=i;
        printf("Enter the burst time for process %d : ",i);
        scanf("%d",&bt[i]);        
        
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                tp=process[i];
                process[i]=process[j];
                process[j]=tp;
            }
        }
    }



    printf("\nprocess\tburst time\tturnaround time\twaiting time\n");

    calc_waiting_time_and_turnaround_time();

}
