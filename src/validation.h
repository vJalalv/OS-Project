#ifndef VALIDATION_H
#define VALIDATION_H
#include "process.h"
int validate_processes(Process *processes, int n);
int validate_single_process(Process p, int index);
int validate_unique_pids(Process *processes, int n);

#endif