#include <stdio.h>
#include "student.h"

void show_records(const struct student *head)
{
    if(head==NULL)
    {
        printf("No student records available.\n");
        return;
    }
    printf("-----------------------------------------------\n");
    printf("%-10s %-30s %s\n","Roll No.", "Name", "Percentage");
    printf("-----------------------------------------------\n");
    while(head != NULL)
    {
        show_one(head);
        head = head->next;
    }
    printf("-----------------------------------------------\n");
}