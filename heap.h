// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // // //
//  PRINTER LIBRARY: //
// // // // // // // //

#ifndef PROJECT_HEAP_H
#define PROJECT_HEAP_H

#include <stdio.h>

#include "algorithm.h"
#include "process.h"

extern void heap_insert(int algorithm, process processes[], int heap[], int *current, int value);

extern int heap_minimum(int algorithm, process processes[], int count, int time, int heap[], int *heap_count);

#endif //PROJECT_HEAP_H

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //