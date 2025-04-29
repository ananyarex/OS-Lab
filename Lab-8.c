#include <stdio.h>
#include <limits.h>
#define MAX 3

int arr[100];   
int frame[MAX]; 
int n, l;      


void fifo() {
    int count = 0;  
    int oldest = 0; 

   
    for (int i = 0; i < n; i++) {
        frame[i] = -1;
    }

   
    for (int i = 0; i < l; i++) {
        int pageFault = 1;

      
        for (int j = 0; j < n; j++) {
            if (frame[j] == arr[i]) {
                pageFault = 0; 
                break;
            }
        }

       
        if (pageFault) {
            frame[oldest] = arr[i];
            oldest = (oldest + 1) % n;
            count++;
        }

       
        printf("PF no.%d : ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", count);
}

                                                                                                                                                                                                                                     
int main() {
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    printf("Enter the length of reference string: ");
    scanf("%d", &l);

    printf("Enter the reference string: ");
    for (int i = 0; i < l; i++) {
        scanf("%d", &arr[i]);
    }

    // Call each algorithm
    printf("\nFIFO Page Replacement:\n");
    fifo();
    
  

    return 0;
}
