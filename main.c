// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // //
//  MAIN LIBRARY: //
// // // // // // //

#include <stdio.h>
#include <stdlib.h>use

#include "algorithm.h"
#include "parser.h"

int main(int argc, char** argv)
{
    printf("\nSELECTED PARAMS:\n");
    printf("    FILE: %s\n", argv[1]);
    printf("    ALGORITHM: %s\n", argv[2]);
    int algorithm = select_algorithm(argv[2]);
    int quantum = -1;
    int time_to_reset = -1;
    int queues = 1;
    int allotment[queues];
    if (algorithm > 2)
    {
        printf("    QUANTUM: %s\n", argv[3]);
        quantum = atoi(argv[3]);
        if (algorithm > 4)
        {
            printf("    TIME TO RESET: %s\n", argv[4]);
            printf("    QUEUES: %s\n", argv[5]);
            printf("    ALLOTMENT:");
            time_to_reset = atoi(argv[4]);
            queues = atoi(argv[5]);
            allotment[queues];
            int i = 0;
            while (i < queues)
            {
                printf(" %s", argv[6 + i]);
                allotment[i] = atoi(argv[6 + i]);
                i++;
            }
            printf("\n");
        }
    }
    printf("\n");
    int count = 0;
    int fd = open(argv[1], O_RDONLY);
    //int fd = open("/home/samuel/Projects/SO/Scheduler(AS)/project/Test.txt", O_RDONLY);
    char buf;
    while (read(fd, &buf, 1))
    {
        if (buf == '\n')
            count++;
    }
    close(fd);
    process processes[count];
    make_processes(argv[1], processes);
    //make_processes("/home/samuel/Projects/SO/Scheduler(AS)/project/Test.txt", processes);
    int max_response = 0;
    double avg_response = 0;
    int max_turnaround = 0;
    double avg_turnaround = 0;
    execute_algorithm(algorithm, quantum, time_to_reset, queues, allotment, processes, count, &max_response, &avg_response, &max_turnaround, &avg_turnaround);
    //allotment[0] = 10;
    //allotment[1] = 20;
    //allotment[2] = 30;
    //execute_algorithm(5, 10, 100, 3, allotment, processes, count, &max_response, &avg_response, &max_turnaround, &avg_turnaround);
    printf("LIST OF ENDED PROCESSES:\n");
    int i = 0;
    while (i < count)
    {
        print_process(processes[i++], 1, 1);
    }
    printf("\n");
    printf("MAXIMUM RESPONSE TIME: %i\n", max_response);
    printf("AVERAGE RESPONSE TIME: %f\n", avg_response);
    printf("MAXIMUM TURNAROUND TIME: %i\n", max_turnaround);
    printf("AVERAGE TURNAROUND TIME: %f\n\n", avg_turnaround);
    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //