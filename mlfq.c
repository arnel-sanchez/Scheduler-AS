// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // //
//  MLFQ LIBRARY: //
// // // // // // //

#include "mlfq.h"

void mlfq(int quantum, int time_to_reset, int queues, const int allotment[], process processes[], int count, int *max_response, double *avg_response,
        int *max_turnaround, double *avg_turnaround)
{
    int priority[queues][count];
    int f[count];
    int l[count];
    int reset = time_to_reset;
    int current = 0;
    int time = 0;
    for (int j = 0; j < count; j++)
    {
        f[j] = 0;
        l[j] = 0;
    }
    int i = 0;
    int change = 0;
    int delay = 0;
    while (1)
    {
        if (time >= reset)
        {
            for (int j = 1; j < queues; j++)
                for (int k = f[j]; k < l[j]; k++)
                {
                    priority[0][l[0]%count] = priority[j][k%count];
                    l[0]++;
                }
            for (int j = 1; j < count; j++)
            {
                f[j] = 0;
                l[j] = 0;
            }
            reset = time + time_to_reset;
            i = 0;
        }
        if (f[i] == l[i])
            change = 0;
        while (current < count && processes[current].arrival_time <= time)
        {
            priority[0][l[0]%count] = processes[current].global_index - 1;
            processes[current].time_in_queue = time;
            l[0]++;
            i = 0;
            add_process(processes[current], time, &current, &change);
        }
        while (i < queues && f[i] == l[i])
        {
            i++;
        }
        if (i == queues)
        {
            if (current == count)
                break;
            if (change == 0)
            {
                time++;
                if (delay != 0)
                    i = 0;
                continue;
            }
        }
        unsigned int random = random_index(l[i] - f[i], time);
        int temp = priority[i][f[i]%count];
        priority[i][f[i]%count] = priority[i][(f[i] + random)%count];
        priority[i][(f[i] + random)%count] = temp;
        int c = f[i];
        while (1)
        {
            change = 1;
            if (processes[priority[i][c%count]].time_to_ready <= time)
                break;
            c++;
            while (c == l[i])
            {
                i++;
                if (i == queues)
                {
                    change = 0;
                    delay = 1;
                    break;
                }
                c = f[i];
            }
            if (change == 0)
                break;
        }
        if (change == 0)
            continue;
        delay = 0;
        temp = priority[i][f[i]%count];
        priority[i][f[i]%count] = priority[i][c%count];
        priority[i][c%count] = temp;
        start_process(&processes[priority[i][f[i]%count]], time, max_response, avg_response);
        if (processes[priority[i][f[i]%count]].interruptions[processes[priority[i][f[i]%count]].current_interruption] != -1)
        {
            int dif = processes[priority[i][f[i]%count]].interruptions[processes[priority[i][f[i]%count]].current_interruption] -
                    (processes[priority[i][f[i]%count]].delay_time - processes[priority[i][f[i]%count]].time_to_end);
            if (dif <= quantum)
            {
                io_operation(&processes[priority[i][f[i]%count]], &time, dif);
                continue;
            }
        }
        interrupt_process(&processes[priority[i][f[i]%count]], quantum, &time);
        if (processes[priority[i][f[i]%count]].time_to_end < 1)
        {
            end_process(&processes[priority[i][f[i]%count]], time, max_turnaround, avg_turnaround);
            f[i]++;
        }
        else if (i < queues - 1 && time >= processes[priority[i][f[i]%count]].time_in_queue + allotment[i])
        {
            priority[i + 1][l[i + 1]%count] = priority[i][f[i]%count];
            f[i]++;
            l[i + 1]++;
            processes[current].time_in_queue = time;
        }
    }
    *avg_response /= count;
    *avg_turnaround /= count;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //