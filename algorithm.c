// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // // // //
//  ALGORITHM LIBRARY:  //
// // // // // // // // //

#include "algorithm.h"

int select_algorithm(char *string)
{
    algorithm alg = error;
    if (!strcmp(string, "FIFO"))
        alg = FIFO;
    else if (!strcmp(string, "STF"))
        alg = STF;
    else if (!strcmp(string, "STCF"))
        alg = STCF;
    else if (!strcmp(string, "RR"))
        alg = RR;
    else if (!strcmp(string, "MLFQ"))
        alg = MLFQ;
    return alg;
}

void execute_algorithm(int algorithm, int quantum, int time_to_reset, int queues, int allotment[], process processes[], int count, int *max_response,
        double *avg_response, int *max_turnaround, double *avg_turnaround)
{
    printf("\nSTARTING SCHEDULER...\n\n");
    switch (algorithm)
    {
        case 1:
        case 2:
            fifo_stf(algorithm, processes, count, max_response, avg_response, max_turnaround, avg_turnaround);
            break;
        case 3:
            stcf(quantum, processes, count, max_response, avg_response, max_turnaround, avg_turnaround);
            break;
        case 4:
            rr(quantum, processes, count, max_response, avg_response, max_turnaround, avg_turnaround);
            break;
        case 5:
            mlfq(quantum, time_to_reset, queues, allotment, processes, count, max_response, avg_response, max_turnaround, avg_turnaround);
            break;
        default:
            break;
    }
    printf("CLOSING SCHEDULER...\n\n");
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //