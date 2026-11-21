#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void delete_all(struct student **head)
{
    struct student *temp;
    while(*head != NULL)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    *head=NULL;
}

void reverse_records(struct student **head)
{
    struct student *prev=NULL;
    struct student *current=*head;
    struct student *next;
    while (current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
}