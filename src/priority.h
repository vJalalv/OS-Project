#ifndef PRIORITY_H
#define PRIORITY_H

#include "process.h"
void priority_scheduling(Process *processes, int n);
void print_gantt_priority(int *gantt, int *gantt_time, int gantt_size);

#endif
