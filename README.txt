COMPOSICION DEL PROYECTO:
main.c -> Donde se reciben los parametros y se ordena la ejecucion atendiendo a estos
algorithm.c algorithm.h -> Donde se decide y ordena ejecutar el algoritmo deseado
heap.c heap.h -> Donde se simula el funcionamiento de un heap
fifo_stf.c fifo_stf.h -> Donde se ejecutan los algoritmos FIFO y STF
mlfq.c mlfq.h -> Donde se ejecuta el algoritmo MLFQ
parser.c parser.h -> Donde se convierten los datos a la gramatica deseada
process.c process.h -> Donde se definen las caracteristicas de los procesos a ejecutar
rr.c rr.h -> Donde se ejecuta el algoritmo RR
stcf.c stcf.h -> Donde se ejecuta el algoritmo STCF

PARA COMPILARLO:
gcc main.c algorithm.c heap.c fifo_stf.c mlfq.c parser.c process.c rr.c stcf.c

PARA EJECUTARLO:
./a.out Test.txt MLFQ 10 100 3 10 20 30

