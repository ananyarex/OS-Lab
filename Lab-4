#include<stdio.h>
#include<stdlib.h>

int ch,mutex=1,full=0,empty=10,x=0;

void wait(int *s)
{
    while (*s<=0);
    (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

void producer()
{
    if (empty > 0 && mutex > 0) {
        wait(&empty);
        wait(&mutex);

        x++; // Produce an item
        printf("Producer has produced: Item %d\n", x);

        signal(&mutex);
        signal(&full);
    } else {
        printf("Buffer is full! Cannot produce.\n");
    }

   
}

void consumer()
{
    if (full > 0 && mutex > 0) {
        wait(&full);
        wait(&mutex);

        printf("Consumer has consumed: Item %d\n", x);
        x--; // Consume an item

        signal(&mutex);
        signal(&empty);
    } else {
        printf("Buffer is empty! Cannot consume.\n");
    }

    
}



void main()
{   

    
    printf("Enter choice 1:Producer  2:Consumer  3:Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:producer();break;
            case 2:consumer();break; 
            case 3:exit(0);
        }
    }
    
}
