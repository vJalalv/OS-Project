#include <stdio.h>
#include "validation.h"
int validate_single_process(Process p, int index) {

    if (p.arrival_time < 0) {
        printf("Error: Process %d has negative Arrival Time.\n", index + 1);
        return 0;
    }

    if (p.burst_time <= 0) {
        printf("Error: Process %d has invalid Burst Time (must be > 0).\n", index + 1);
        return 0;
    }

    if (p.priority < 0) {
        printf("Error: Process %d has invalid Priority Value.\n", index + 1);
        return 0;
    }

    return 1;
}

int validate_unique_pids(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].pid == processes[j].pid) {
                printf("Error: Duplicate PID found: %d\n", processes[i].pid);
                return 0;
            }
        }
    }
    return 1;
}

int validate_processes(Process *processes, int n) {
    if (n <= 0) {
        printf("Error: No processes entered.\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (!validate_single_process(processes[i], i)) {
            return 0;
        }
    }
    if (!validate_unique_pids(processes, n)) {
        return 0;
    }

    return 1; 
}