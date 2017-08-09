#include <fcntl.h>
#include <errno.h>
#include "twins.h"

int sd()
{
    unsigned size = 0;
    FILE *list_dir;
    FILE *list_zero;
    file_def *p;
    int i = 0;

    list_dir = fopen(reestr, "r");
    if (list_dir == NULL)
    {
        fprintf(stderr, "%s: %s (%s %d) : fopen(%s, %d) failed: %s\n",
            argv0, __func__, __FILE__, __LINE__, reestr, O_RONLY, strerror(errno));
        return 1;
    }

    list_dir = fopen(list.zero, "a+");
    if (list_dir == NULL)
    {
        fprintf(stderr, "%s: %s (%s %d) : fopen(%s, %d) failed: %s\n",
            argv0, __func__, __FILE__, __LINE__, reestr, O_RONLY, strerror(errno));
        return 1;
    }

// Count quantity of rows in reestr
    while (! feof(list_dir))
    {
        if (fgetc(list_dir) == '\n')
            size++;
    }

    (size != 0)
    &&(size++);

    file_def P **p = malloc(lines_count * sizeof(file_def));
 
    (p == NULL)
    &&(exit(EXIT_FAILURE));
    
    while (! feof(list_dir))
    {
        fscanf(list_dir, "%ld", p[i]->size);
        fscanf(list_dir, "%lu", p[i]->st_ino);
        fscanf(list_dir, "%s\n", p[i]->file_name);

        i++;
    }

while(size > 0)
{
    while(p[0]->size == 0)
    {
        del_row(p[0], p[size-1], file_zero);
        size--;
    }

    i = 1;
        
    while (i < size)
    {
        if (p[i]->size == 0)
        {
            del_row(p[i], p[size-1], file_zero);
            size--;
            i--;
        }
        else if ((p[0]->size == p[i]->size)
                &&(p[0]->st_ino == p[i]->st_ino)
                &&(compare(p[0]->filename, p[i]->filename) == 0)
        {
            fprintf(file_double, "%ld ", p->size);
            fprintf(file_double, "%lu ", p->st_ino);
            fprintf(file_double, "%s\n", p->file_name);

            del_row(p[i], p[size-1], file_double);
            size--;
            i--;
        }
        i++;
    }
    
    del_row(p[0], p[size-1], file_none);
    size--;
}

    return 0;
}
