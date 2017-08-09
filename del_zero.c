#include <fcntl.h>
#include <errno.h>
#include "twins.h"

int del_zero(file_def * p, file_def * end, FILE * file)
{
        fprintf(file, "%ld ", p->size);
        fprintf(file, "%lu ", p->st_ino);
        fprintf(file, "%s\n\n", p->file_name);

        file_def *temp = p;
        p = end;
        free(temp);
    return 0;
}
