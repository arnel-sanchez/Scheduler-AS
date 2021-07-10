// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // // //
//  PROCESS LIBRARY: //
// // // // // // // //

#include "process.h"

void create_process(process *proc, int index, int *values)
{
    proc->global_index = index;
    proc->arrival_time = values[0];
    proc->delay_time = values[1];
    proc->time_to_end = values[1];
    proc->start_time = -1;
    proc->time_in_queue = 0;
    proc->completion_time = -1;
    proc->time_to_ready = 0;
    proc->current_interruption = 0;
    values = values + 2;
    int i = 0;
    while (*values != -1)
    {
        proc->interruptions[i++] = *values++;
    }
    proc->interruptions[i++] = -1;
    proc->interruptions[i] = -1;
    print_process(*proc, 1, 0);
}

void add_process(process proc, int time, int *current, int *change)
{
    printf("READING PROCESS %i... (SEC %i)\n\n", proc.global_index, time);
    *current += 1;
    *change = 1;
}

void start_process(process *proc, int time, int *max_response, double *avg_response)
{
    if (proc->time_to_end == proc->delay_time)
    {
        printf("EXECUTING PROCESS %i... (SEC %i)\n\n", proc->global_index, time);
        proc->start_time = time;
        int response = time - proc->arrival_time;
        if (*max_response < response)
            *max_response = response;
        *avg_response += response;
    }
    else
        printf("RESUMING PROCESS %i... (SEC %i)\n\n", proc->global_index, time);
}

void io_operation(process *proc, int *time, int dif)
{
    if (dif > 0)
        *time += dif;
    proc->current_interruption++;
    proc->time_to_end -= dif + (proc->interruptions)[proc->current_interruption];
    proc->time_to_ready = *time + (proc->interruptions)[proc->current_interruption++];
    printf("PROCESS %i INTERRUPT BY I/O OPERATION. (SEC %i)\n\n", proc->global_index, *time);
}

void interrupt_process(process *proc, int quantum, int *time)
{
    if (proc->time_to_end > quantum)
    {
        proc->time_to_end = proc->time_to_end - quantum;
        *time += quantum;
        printf("PROCESS %i INTERRUPT. (SEC %i)\n\n", proc->global_index, *time);
    }
    else
    {
        if (proc->time_to_end > 0)
            *time += proc->time_to_end;
        proc->time_to_end = 0;
    }
}

void end_process(process *proc, int time, int *max_turnaround, double *avg_turnaround)
{
    proc->time_to_end = -1;
    proc->completion_time = time;
    int turnaround = time - proc->arrival_time;
    *avg_turnaround += turnaround;
    if (*max_turnaround < turnaround)
        *max_turnaround = turnaround;
    printf("PROCESS %i WAS COMPLETED SUCCESSFULLY. (SEC %i)\n\n", proc->global_index, time);
}

void print_process(process proc, int tab, int ended)
{
    int i = tab;
    while (i > 0)
    {
        printf("    ");
        i--;
    }
    printf("PROCESS %i:\n", proc.global_index);
    i = tab;
    while (i > 0)
    {
        printf("    ");
        i--;
    }
    printf("    ARRIVAL TIME: %i\n", proc.arrival_time);
    i = tab;
    while (i > 0)
    {
        printf("    ");
        i--;
    }
    printf("    DELAY TIME: %i\n", proc.delay_time);
    if (!ended)
    {
        i = tab;
        while (i > 0)
        {
            printf("    ");
            i--;
        }
        printf("    INTERRUPTIONS TIMES:");
        int j = 0;
        while (proc.interruptions[j] != -1)
        {
            printf(" %i ", proc.interruptions[j]);
            j += 2;
        }
        if (j == 0)
            printf(" - ");
        printf("\n");
        i = tab;
        while (i > 0)
        {
            printf("    ");
            i--;
        }
        printf("    INTERRUPTIONS DELAYS:");
        j = 1;
        while (proc.interruptions[j] != -1)
        {
            printf(" %i ", proc.interruptions[j]);
            j += 2;
        }
        if (j == 1)
            printf(" - ");
        printf("\n");
    }
    else
    {
        i = tab;
        while (i > 0)
        {
            printf("    ");
            i--;
        }
        printf("    START TIME: %i\n", proc.start_time);
        i = tab;
        while (i > 0)
        {
            printf("    ");
            i--;
        }
        printf("    COMPLETION TIME: %i\n", proc.completion_time);
        i = tab;
        while (i > 0)
        {
            printf("    ");
            i--;
        }
        printf("    RESPONSE TIME: %i\n", proc.start_time - proc.arrival_time);
        i = tab;
        while (i > 0)
        {
            printf("    ");
            i--;
        }
        printf("    TURNAROUND TIME: %i\n", proc.completion_time - proc.arrival_time);
    }
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //