// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // //
// RR LIBRARY: //
// // // // // //

#include "rr.h"

unsigned int random_index(int count, int i)
{
    if (count == 0)
        return 0;
    int next[1];
    i += __timer_t_defined;
    if (i > count)
        i %= count;
    int p = next[i] * 1103515245 + 123456;
    return (unsigned int) (p/65536) % count;
}

void rr(int quantum, process processes[], int count, int *max_response, double *avg_response, int *max_turnaround,
        double *avg_turnaround)
{
    int first = 0;
    int last = 0;
    int time = 0;
    int array[count];
    int change = 0;
    while (first < count)
    {
        if (first == last)
            change = 0;
        while (last < count && processes[last].arrival_time <= time)
        {
            array[last%count] = processes[last].global_index - 1;
            add_process(processes[last], time, &last, &change);
        }
        if (first == last && change == 0)
        {
            time++;
            continue;
        }
        unsigned int random = random_index(last - first, time);
        int temp = array[first%count];
        array[first%count] = array[(first + random)%count];
        array[(first + random)%count] = temp;
        int current = first;
        change = 1;
        while (time < processes[array[current%count]].time_to_ready)
        {
            current++;
            if (current == last)
            {
                change = 0;
                time++;
                break;
            }
        }
        if (change == 0)
            continue;
        temp = array[first%count];
        array[first%count] = array[current%count];
        array[current%count] = temp;
        start_process(&processes[array[first%count]], time, max_response, avg_response);
        if (processes[array[first%count]].interruptions[processes[array[first%count]].current_interruption] != -1)
        {
            int dif = processes[array[first%count]].interruptions[processes[array[first%count]].current_interruption] - (processes[array[first%count]].delay_time
                    - processes[array[first%count]].time_to_end);
            if (dif <= quantum)
            {
                io_operation(&processes[array[first%count]], &time, dif);
                continue;
            }
        }
        interrupt_process(&processes[array[first%count]], quantum, &time);
        if (processes[array[first%count]].time_to_end < 1)
        {
            end_process(&processes[array[first%count]], time, max_turnaround, avg_turnaround);
            first++;
        }
    }
    *avg_response /= count;
    *avg_turnaround /= count;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //