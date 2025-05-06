#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int start_block;
    int length;
    int allocated;
} File;

int main() {
    int disk[MAX] = {0}; // 0 = free, 1 = occupied
    int n, i;
    
    printf("Enter the number of files: ");
    scanf("%d", &n);

    File files[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter starting block and length of file %d: ", i + 1);
        scanf("%d%d", &files[i].start_block, &files[i].length);
        files[i].allocated = 1;

        // Check if blocks are free
        for (int j = files[i].start_block; j < files[i].start_block + files[i].length; j++) {
            if (j >= MAX || disk[j] == 1) {
                printf("Block %d not available. File %d cannot be allocated.\n", j, i + 1);
                files[i].allocated = 0;
                break;
            }
        }

        // Allocate if all blocks are free
        if (files[i].allocated) {
            for (int j = files[i].start_block; j < files[i].start_block + files[i].length; j++) {
                disk[j] = 1;
            }
            printf("File %d allocated.\n", i + 1);
        }
    }

    // Display allocation
    printf("\nFile Allocation Table:\n");
    printf("File\tStart\tLength\tStatus\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%s\n", i + 1, files[i].start_block, files[i].length,
               files[i].allocated ? "Allocated" : "Not Allocated");
    }

    return 0;
}

