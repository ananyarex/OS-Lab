#include<stdio.h>
int wt[100],tat[100], p_id[100],process_bt[100],system_bt[100],user_bt[100];
int p1,p2;

void calc_wt_and_tat(int n) 
{
    float wtavg=0;
    float tatavg=0;

    tat[0]=process_bt[0];
    wt[0] = 0;
    for (int i = 1; i <=n ; i++) 
    {
        wt[i] = wt[i - 1] + process_bt[i - 1]; 
        tat[i] = tat[i-1] + process_bt[i]; 
        wtavg=wtavg+wt[i];
        tatavg=tatavg+tat[i];

        printf("%d\t%d\t%d\t%d\t",p_id[i],process_bt[i],tat[i],wt[i]);
        printf("\n");    
    }
    printf("The average waiting time is: %.2f\n",wtavg/n);
    printf("The average turn around time is: %.2f\n",tatavg/n);
}


void main()
{
    
    printf("Enter the number of processes in system processes: ");
    scanf("%d",&p1);
    printf("Enter the number of processes in user processes: ");
    scanf("%d",&p2);

    for(int i=1;i<=p1+p2;i++)
    {
        p_id[i]=i;
    }

    for(int i=1;i<=p1;i++)
    {
        
        printf("Enter burst time for system process %d: ",i);
        scanf("%d",&system_bt[i]);
    }

    for(int i=1;i<=p2;i++)
    {
        
        printf("Enter burst time for user process %d: ",i);
        scanf("%d",&user_bt[i]);
    }

    for(int i=1;i<=p1;i++)
    {
        process_bt[i]=system_bt[i];
    }

    for(int i=1;i<=p2;i++)
    {
        process_bt[i+p1]=user_bt[i];
    }

    printf("\nP\tbt\ttat\twt\n");
    calc_wt_and_tat(p1+p2);
}
