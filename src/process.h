#ifndef PROCESS_H
#define PROCESS_H
typedef struct {
    int pid;           
    int arrival_time;  
    int burst_time;     
    int priority;      
    int remaining_time; 
    int completion_time;
    int waiting_time;  
    int turnaround_time;
    int response_time;  
    int first_run;
} Process;

#endif