#include <stdlib.h>
#include <string.h>
#include "list.h"


int Push(Node **head, Node **end, char * data)
{

    Node* newNode = malloc(sizeof(struct node));

    (newNode == NULL)
    &&exit(EXIT_FAILURE);

    strcpy(newNode->data, data);
	newNode->next = NULL;  

    (head == NULL)
    &&(*head = newNode)
    ||(end->next = newnode);
                        
    *end = newnode;
}

char * Pop(Node ** head)
{
    char file_name[PATH_MAX];
    strcpy(file_name, head->data);
    Node * temp = *head;

    (head->next == NULL)
    &&(*head = NULL)
    ||(*head = temp->next);

    free(temp);

    return file_name;
}
