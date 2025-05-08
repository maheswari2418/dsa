#include <stdio.h>

int main() {
    int at[10], bt[10], wt[10], tat[10], ct[10] = {0};
    int n, i, j, temp, min, time = 0;
    float avgwait = 0, avgturn = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and execution time for process %d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
    }

    // Sort processes based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    time = at[0]; // Start time with the first process's arrival time

    for (i = 0; i < n; i++) {
        min = -1;
        for (j = 0; j < n; j++) {
            if (!ct[j] && at[j] <= time) {
                if (min == -1 || bt[j] < bt[min]) {
                    min = j;
                }
            }
        }

        if (min == -1) {
            time++;
            continue;
        }

        wt[min] = time - at[min];
        tat[min] = wt[min] + bt[min];
        time += bt[min];
        ct[min] = 1;

        avgwait += wt[min];
        avgturn += tat[min];
    }

    avgwait /= n;
    avgturn /= n;

    printf("\nProcess\t| Arrival time\t| Execution time\t| Waiting time\t| Turnaround time\n\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t| %d\t\t| %d\t\t| %d\t\t| %d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time: %.2f\n", avgwait);
    printf("Average turnaround time: %.2f\n", avgturn);

    return 0;
}

