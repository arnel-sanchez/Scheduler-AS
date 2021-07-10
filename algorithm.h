// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // // // //
//  ALGORITHM LIBRARY:  //
// // // // // // // // //

#ifndef PROJECT_ALGORITHM_H
#define PROJECT_ALGORITHM_H

#include <string.h>

#include "fifo_stf.h"
#include "mlfq.h"
#include "rr.h"
#include "stcf.h"

typedef enum algorithm
{
    error,
    FIFO,
    STF,
    STCF,
    RR,
    MLFQ
} algorithm;

extern int select_algorithm(char *string);

extern void execute_algorithm(int algorithm, int quantum, int time_to_reset, int queues, int allotment[], process processes[], int count, int *max_response,
        double *avg_response, int *max_turnaround, double *avg_turnaround);

#endif //PROJECT_ALGORITHM_H

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //