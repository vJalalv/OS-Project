#ifndef SRTF_H
#define SRTF_H

#include "process.h"

void srtf_scheduling(Process *processes, int n);
void print_gantt_srtf(int *gantt, int *gantt_time, int gantt_size);

#endif
