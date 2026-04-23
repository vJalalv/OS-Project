#include <stdio.h>
#include "metrics.h"

void calculate_metrics(Process *processes, int n) {
    for (int i = 0; i < n; i++) {

        processes[i].turnaround_time = processes[i].completion_time
                                     - processes[i].arrival_time;

        processes[i].waiting_time = processes[i].turnaround_time
                                  - processes[i].burst_time;

     
        processes[i].response_time = processes[i].response_time
                                   - processes[i].arrival_time;
    }
}


void print_averages(Process *processes, int n) {
    float total_wt  = 0;
    float total_tat = 0;
    float total_rt  = 0;

    for (int i = 0; i < n; i++) {
        total_wt  += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;
        total_rt  += processes[i].response_time;
    }

    printf("\n==============================\n");
    printf("         AVERAGES\n");
    printf("==============================\n");
    printf("Average Waiting Time    : %.2f\n", total_wt  / n);
    printf("Average Turnaround Time : %.2f\n", total_tat / n);
    printf("Average Response Time   : %.2f\n", total_rt  / n);
    printf("==============================\n");
}

void print_results_table(Process *processes, int n) {
    printf("\n+-------+----+----+----+-----+-----+-----+\n");
    printf("| PID   | AT | BT | PR |  WT | TAT |  RT |\n");
    printf("+-------+----+----+----+-----+-----+-----+\n");

    for (int i = 0; i < n; i++) {
        printf("| P%-4d | %2d | %2d | %2d | %3d | %3d | %3d |\n",
            processes[i].pid,
            processes[i].arrival_time,
            processes[i].burst_time,
            processes[i].priority,
            processes[i].waiting_time,
            processes[i].turnaround_time,
            processes[i].response_time
        );
    }

    printf("+-------+----+----+----+-----+-----+-----+\n");
    print_averages(processes, n);
}
