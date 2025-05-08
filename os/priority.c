#include <stdio.h>

int main() {
    int at[10], bt[10], pr[10], wt[10], tat[10], rt[10];
    int n, i, j, temp, time = 0, min_priority, current;
    float avgwait = 0, avgturn = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter arrival time, execution time, and priority for process %d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    int completed = 0;
    while (completed < n) {
        min_priority = 9999; // A large number indicating lowest priority
        current = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && pr[i] < min_priority) {
                min_priority = pr[i];
                current = i;
            }
        }

        if (current == -1) {
            time++;
            continue;
        }

        rt[current]--;

        if (rt[current] == 0) {
            completed++;
            tat[current] = time + 1 - at[current];
            wt[current] = tat[current] - bt[current]-at[current];
            avgwait += wt[current];
            avgturn += tat[current];
        }

        time++;
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

