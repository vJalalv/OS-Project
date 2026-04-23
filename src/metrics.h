#ifndef METRICS_H
#define METRICS_H
#include "process.h"
void calculate_metrics(Process *processes, int n);
void print_averages(Process *processes, int n);
void print_results_table(Process *processes, int n);

#endif