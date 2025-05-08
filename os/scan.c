#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int track, no_req, head, head1, distance;
int disc_req[100];

void sort() {
    int i, j, temp;
    for (i = 0; i < no_req; i++) {
        for (j = 0; j < no_req; j++) {
            if (disc_req[i] < disc_req[j]) {
                temp = disc_req[i];
                disc_req[i] = disc_req[j];
                disc_req[j] = temp;
            }
        }
    }
}  

void scan() {
    int index;
    distance = 0;
    head = head1;

    sort();

    int i = 0;
    while (head >= disc_req[i]) {
        index = i;
        i++;
    }

    for (i = index + 1; i < no_req; i++) {
        printf("%d=>", disc_req[i]);
        distance += abs(head - disc_req[i]);
        head = disc_req[i];
    }

    if (index != no_req - 1) {
        distance += abs(track  - disc_req[i - 1]);
        printf("%d=>", track );
        head = track;
    }

    for (i = index; i >= 0; i--) {
        printf("%d=>", disc_req[i]);
        distance += abs(head - disc_req[i]);
        head = disc_req[i];   
    }

    printf("\nTotal Distance Traversed = %d\n", distance);
}

int main() {
    printf("Enter Total number of tracks: ");
    scanf("%d", &track);

    printf("Enter total number of disc requests: ");
    scanf("%d", &no_req);

    printf("\nEnter disc requests in FCFS order:\n");
    for (int i = 0; i < no_req; i++) {
        scanf("%d", &disc_req[i]);     
    }

    printf("\nEnter current head position: ");
    scanf("%d", &head1);

    scan();
    return 0;
}

