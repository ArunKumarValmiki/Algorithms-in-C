#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int compare(const void* a, const void* b) {
    Job* job1 = (Job*)a;
    Job* job2 = (Job*)b;
    return job2->profit - job1->profit;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    int max_deadline = 0;

    printf("Enter job details (ID Deadline Profit):\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    qsort(jobs, n, sizeof(Job), compare);

    char schedule[max_deadline];
    for (int i = 0; i < max_deadline; i++)
        schedule[i] = '\0';

    int total_profit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = min(max_deadline, jobs[i].deadline) - 1; j >= 0; j--) {
            if (schedule[j] == '\0') {
                schedule[j] = jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for (int i = 0; i < max_deadline; i++) {
        if (schedule[i] != '\0')
            printf("%c ", schedule[i]);
    }
    printf("\nTotal Profit: %d\n", total_profit);

    return 0;
}
