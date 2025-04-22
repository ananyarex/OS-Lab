#include<stdio.h>

int n, r; // n = number of processes, r = number of resources
int allocation[10][10], max[10][10], need[10][10];
int available[10], work[10], finish[10];

void initialise() {
    // Initialize Work = Available and Finish = false
    for (int i = 0; i < r; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < n; i++) {
        finish[i] = 0; // False (not finished)
    }
}

void calculateneed() {
    // Calculate Need matrix: Need[i][j] = Max[i][j] - Allocation[i][j]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void safetyalgorithm() {
    initialise();
    int count = 0; // Count of processes completed
    while (count < n) {
        int found = 0; // Flag to indicate if a process can proceed
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) { // Process not finished
                int canProceed = 1;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) { // Not enough resources
                        canProceed = 0;
                        break;
                    }
                }
                if (canProceed) {
                    // Process i can proceed
                    for (int j = 0; j < r; j++) {
                        work[j] += allocation[i][j]; // Release resources
                    }
                    finish[i] = 1; // Mark process as finished
                    found = 1;
                    count++;
                    printf("Process P%d can proceed\n", i);
                }
            }
        }
        if (found == 0) {
            // No process can proceed; system is not in a safe state
            printf("System is not in a safe state\n");
            return;
        }
    }
    // If all processes finished
    printf("System is in a safe state\n");
}

int main() {
    // Input: number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    // Input Allocation matrix
    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Max matrix
    printf("Enter Max matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available resources
    printf("Enter Available resources:\n");
    for (int i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }

    calculateneed();
    safetyalgorithm();

    return 0;
}
