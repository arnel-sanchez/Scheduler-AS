// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // //
//  MLFQ LIBRARY: //
// // // // // // //

#ifndef PROJECT_MLFQ_H
#define PROJECT_MLFQ_H

#include "process.h"
#include "rr.h"

extern void mlfq(int quantum, int time_to_reset, int queues, const int allotment[], process processes[], int count, int *max_response, double *avg_response,
        int *max_turnaround, double *avg_turnaround);

#endif //PROJECT_MLFQ_H

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //