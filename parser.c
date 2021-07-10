// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // // //
//  PARSER LIBRARY:  //
// // // // // // // //

#include "parser.h"

void analyze_line(char *line, int *values)
{
    char *token = strtok(line, " ");
    while (token != NULL)
    {
        *values++ = atoi(token);
        token = strtok(NULL, " ");
    }
    *values++ = -1;
    *values = -1;
}

void make_processes(char *location, process processes[])
{
    printf("LIST OF PROCESSES TO ANALYZE:\n");
    int process_i = 0;
    int lines_size = SIZE;
    int line_i = 0;
    int fd = open(location, O_RDONLY);
    char *line = (char *)malloc(lines_size * sizeof(char));
    int *values = (int *)malloc(lines_size * sizeof(int));
    char buf;
    while (read(fd, &buf, 1))
    {
        line[line_i] = buf;
        if (buf == '\n')
        {
            analyze_line(line, values);
            create_process(&processes[process_i], process_i + 1, values);
            line_i = 0;
            process_i++;
            continue;
        }
        line_i++;
        if (line_i == lines_size)
        {
            lines_size *= lines_size;
            line = realloc(line, lines_size * sizeof(char));
            values = realloc(values, lines_size * sizeof(int));
        }
    }
    free(line);
    free(values);
    close(fd);
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //