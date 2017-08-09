/***************************************************************************
            TWINS
This program removes doubles files from the disk. User specifies directories
in which the same files will be searched. 
In case of identical doubles files the user is given a message whith 
suggestion to select file to remove.
****************************************************************************
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "list.h"
#include "twins.h"

//The program gets the directory names for verification
int main(int argc, char *argv[])
{
    int i, j, k=0;
    int errs = 0;
    char *comp;

// List of directory names
    Node* head = NULL;
	Node* end = NULL;

    argv0 = argv[0];

    if (argc < 2)
    {
        fprintf(stderr, "No search directories.\n");
        errs++;
    }
    else
    {
        for (i = 1; i < argc; i++)
        {
// Check for the occurrence of catalogs in each other
           for(j = 1; j < argc, k == 0; j++)
           {
                if ((j != i)&&(comp = strstr(argv[j], argv[i]) == argv[i])
                    k++;
           }
// Add directory name to the list
           if (k == 0)
           {
                push(head, end, argv[i]);
            }
        }

        errs += create_list_dir(head, end);
/*
        (errs == 0) 
        && (errs += search_doubles());
*/
    }

    return (errs != 0);
}
