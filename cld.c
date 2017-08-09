#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h> 
#include <sys/stat.h>
#include <unistd.h>

#include "twins.h"

char *reestr="file.list";

int create_list_dir(Node * head, Node * end)
{
    DIR *dp;
    struct stat stbuf;
    struct dirent *ent;
    char file_name[PATH_MAX];
    char dir_name[PATH_MAX];
    FILE *list_dir;

    (head == NULL)
    && (return 0);

    strcpy(dir_name, head->data);

    chdir(dir_name);

// Open directory
    if ((dp = opendir(dir_name)) == NULL)
    {
        fprintf(stderr, "%s: %s: cannot open for reading: %s\n", 
            argv0, dir_name, strerror(errno));
        return 1 ;
    }

// Open file to register files
    list_dir = fopen(reestr, "a+");

    if (list_dir == NULL)
    {
        fprintf(stderr, "%s: %s (%s %d) : fopen(%s, %d) failed: %s\n",
            argv0, __func__, __FILE__, __LINE__, reestr, O_WRONLY, strerror(errno));
        return 1;
    }

    while ((ent = readdir(dp)) != NULL)
    {
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        if (stat(ent->d_name, &stbuf) < 0)
        {
            fprintf(stderr, "%s: stat: %s\n", ent->d_name, strerror(errno));
            continue;
        }

//    Add file to the reestr
        if(S_ISREG(stbuf.st_mode))
        {
            strcat(file_name, dir_name);
            strcat(file_name, "/\0");
            strcat(file_name, ent->d_name);

            fprintf(list_dir, "%ld ", stbuf.st_size);
            fprintf(list_dir, "%lu ", stbuf.st_ino);
            fprintf(list_dir, "%s\n", file_name);
        }

//  Add directory to the list
        if(S_ISDIR(stbuf.st_mode))
        {
            strcat(file_name, dir_name);
            strcat(file_name, "/\0");
            strcat(file_name, ent->d_name);

            push(head, end, file_name);
        }
    }

// CLOSE REESTR FILE

    if (fclose(list_dir) == EOF)
    {
        fprintf(stderr, "%s: %s (%s %d) : fclose(%s) failed: %s\n",
            argv0, __func__, __FILE__ , __LINE__ , reestr, strerror(errno));
        return 1;
    }

    if (closedir(dp) != 0)
    {
        fprintf(stderr, "%s: %s: closedir: %s\n",
            argv0, dir_name, strerror(errno));
        return 1;
    }

    if (errno != 0)
    {        
        fprintf(stderr, "%s: %s: reading directory entries: %s\n",
            argv0, dir_name, strerror(errno));
        return 1;
    }

// Recursive call to check the next directory
    create_list_dir(file_name);

    return 0;
}
