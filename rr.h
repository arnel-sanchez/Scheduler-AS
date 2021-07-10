// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // //
// RR LIBRARY: //
// // // // // //

#ifndef PROJECT_RR_H
#define PROJECT_RR_H

#include <stdlib.h>

#include "process.h"

extern unsigned int random_index(int count, int i);

extern void rr(int quantum, process processes[], int count, int *max_response, double *avg_response, int *max_turnaround, double *avg_turnaround);

#endif //PROJECT_RR_H

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //