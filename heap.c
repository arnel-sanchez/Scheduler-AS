// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // // //
//  PRINTER LIBRARY: //
// // // // // // // //

#include "heap.h"

int compare_to(int algorithm, process processes[], int i, int j)
{
    switch (algorithm)
    {
        case STF:
        case STCF:
            i = processes[i].time_to_end;
            j = processes[j].time_to_end;
            break;
        default:
            break;
    }
    if (i > j)
        return 1;
    if (i < j)
        return -1;
    return 0;
}

void swap(int heap[], int i, int p)
{
    int t = heap[i];
    heap[i] = heap[p];
    heap[p] = t;
}

void heap_insert(int algorithm, process processes[], int heap[], int *heap_count, int value)
{
    heap[*heap_count] = value;
    int i = *heap_count;
    do
    {
        int p = (i - 1) / 2;
        if (compare_to(algorithm, processes, heap[p], heap[i]) < 1)
            break;
        swap(heap, i, p);
        i = p;
    }
    while (i > 0);
    *heap_count += 1;
}

int heap_minimum(int algorithm, process processes[], int count, int time, int heap[], int *heap_count)
{
    int min = -1;
    if (*heap_count < 1)
        return min;
    int *interrupted = (int *)malloc(count * sizeof(int));
    int k = 0;
    do
    {
        min = heap[0];
        heap[0] = heap[*heap_count - 1];
        int i = 0;
        do
        {
            int p = 2 * i + 1;
            if (p >= *heap_count)
                break;
            int m = heap[p];
            int r = p + 1;
            if (r < *heap_count)
            {
                int rc = heap[r];
                if (compare_to(algorithm, processes, m, rc) > 0)
                {
                    m = rc;
                    p = r;
                }
            }
            if (compare_to(algorithm, processes, heap[i], m) < 1)
                break;
            swap(heap, i, p);
            i = p;
        }
        while (i < *heap_count);
        *heap_count -= 1;
        if (processes[min].time_to_ready > time)
        {
            interrupted[k++] = min;
            min = -1;
        }
        else
            break;

    }
    while (*heap_count > 0);
    for (int i = 0; i < k; i++)
        heap_insert(algorithm, processes, heap, heap_count, interrupted[i]);
    free(interrupted);
    return min;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //