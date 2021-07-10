// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // //
//  STCF LIBRARY: //
// // // // // // //

#include "stcf.h"

void stcf(int quantum, process processes[], int count, int *max_response, double *avg_response, int *max_turnaround, double *avg_turnaround)
{
    int next_process = 0;
    int heap[count];
    int heap_count = 0;
    int current = 0;
    int time = 0;
    int change = 0;
    while (next_process < count || heap_count > 0)
    {
        if (heap_count < 1)
            change = 0;
        while (next_process < count && processes[next_process].arrival_time <= time)
        {
            heap_insert(STCF, processes, heap, &heap_count, processes[next_process].global_index - 1);
            add_process(processes[next_process], time, &next_process, &change);
        }
        current = heap_minimum(STCF, processes, count, time, heap, &heap_count);
        if ((heap_count < 1 && change == 0) || current < 0)
        {
            time++;
            continue;
        }
        start_process(&processes[current], time, max_response, avg_response);
        if (processes[current].interruptions[processes[current].current_interruption] != -1)
        {
            int dif = processes[current].interruptions[processes[current].current_interruption] - (processes[current].delay_time - processes[current].time_to_end);
            if (dif <= quantum)
            {
                io_operation(&processes[current], &time, dif);
                heap_insert(STCF, processes, heap, &heap_count, current);
                continue;
            }
        }
        interrupt_process(&processes[current], quantum, &time);
        if (processes[current].time_to_end < 1)
            end_process(&processes[current], time, max_turnaround, avg_turnaround);
        else
            heap_insert(STCF, processes, heap, &heap_count, current);
    }
    *avg_response /= count;
    *avg_turnaround /= count;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //