#include <stdio.h>
#include <string.h>
#include "srtf.h"
#include "metrics.h"

void srtf_scheduling(Process *processes, int n) {

    Process temp[n];
    memcpy(temp, processes, sizeof(Process) * n);

    for (int i = 0; i < n; i++) {
        temp[i].remaining_time = temp[i].burst_time;
        temp[i].first_run      = -1;
    }

    int current_time = 0;
    int completed    = 0;
    int gantt[1000];
    int gantt_time[1001];
    int gantt_size = 0;
    int last_pid   = -1;

    while (completed < n) {

        int best = -1;

        for (int i = 0; i < n; i++) {
            if (temp[i].arrival_time <= current_time && temp[i].remaining_time > 0) {
                if (best == -1) {
                    best = i;
                } else if (temp[i].remaining_time < temp[best].remaining_time) {
                    best = i;
                } else if (temp[i].remaining_time == temp[best].remaining_time) {
                    if (temp[i].arrival_time < temp[best].arrival_time) {
                        best = i;
                    } else if (temp[i].arrival_time == temp[best].arrival_time) {
                        if (temp[i].pid < temp[best].pid) {
                            best = i;
                        }
                    }
                }
            }
        }

        if (best == -1) {
            current_time++;
            continue;
        }

        if (temp[best].first_run == -1) {
            temp[best].first_run     = current_time;
            temp[best].response_time = current_time;
        }

        if (temp[best].pid != last_pid) {
            gantt[gantt_size]      = temp[best].pid;
            gantt_time[gantt_size] = current_time;
            gantt_size++;
            last_pid = temp[best].pid;
        }

        temp[best].remaining_time--;
        current_time++;

        if (temp[best].remaining_time == 0) {
            temp[best].completion_time = current_time;
            completed++;

            for (int i = 0; i < n; i++) {
                if (processes[i].pid == temp[best].pid) {
                    processes[i].completion_time = temp[best].completion_time;
                    processes[i].response_time   = temp[best].response_time;
                    break;
                }
            }
        }
    }

    gantt_time[gantt_size] = current_time;

    printf("\n============================\n");
    printf("   SRTF SCHEDULING\n");
    printf("============================\n");

    print_gantt_srtf(gantt, gantt_time, gantt_size);
    calculate_metrics(processes, n);
    print_results_table(processes, n);
}

void print_gantt_srtf(int *gantt, int *gantt_time, int gantt_size) {
    printf("\nGantt Chart:\n");
    printf("+");
    for (int i = 0; i < gantt_size; i++) printf("------+");
    printf("\n|");
    for (int i = 0; i < gantt_size; i++) printf(" P%-3d |", gantt[i]);
    printf("\n+");
    for (int i = 0; i < gantt_size; i++) printf("------+");
    printf("\n");
    for (int i = 0; i <= gantt_size; i++) printf("%-7d", gantt_time[i]);
    printf("\n");
}
