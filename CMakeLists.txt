cmake_minimum_required(VERSION 3.12)
project(project C)

set(CMAKE_C_STANDARD 99)

add_executable(project main.c parser.c parser.h process.c process.h algorithm.h algorithm.c fifo_stf.h fifo_stf.c stcf.h stcf.c rr.h rr.c mlfq.h mlfq.c heap.h heap.c)