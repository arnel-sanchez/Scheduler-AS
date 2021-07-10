// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // //
//  STCF LIBRARY: //
// // // // // // //

#ifndef PROJECT_STCF_H
#define PROJECT_STCF_H

#include "heap.h"
#include "process.h"

extern void stcf(int quantum, process processes[], int count, int *max_response, double *avg_response, int *max_turnaround, double *avg_turnaround);

#endif //PROJECT_STCF_H

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //