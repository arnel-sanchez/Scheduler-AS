// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // // //
//  PROCESS LIBRARY: //
// // // // // // // //

#ifndef PROJECT_PROCESS_H
#define PROJECT_PROCESS_H

#include <stdio.h>

typedef struct process
{
    int global_index;
    int arrival_time;
    int delay_time;
    int time_to_end;
    int start_time;
    int time_in_queue;
    int completion_time;
    int time_to_ready;
    int current_interruption;
    int interruptions[22];
} process;

extern void create_process(process *proc, int index, int *values);

extern void add_process(process proc, int time, int *current, int *change);

extern void start_process(process *proc, int time, int *max_response, double *avg_response);

extern void io_operation(process *proc, int *time, int dif);

extern void interrupt_process(process *proc, int quantum, int *time);

extern void end_process(process *proc, int time, int *max_turnaround, double *avg_turnaround);

extern void print_process(process proc, int tab, int ended);

#endif //PROJECT_PROCESS_H

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //