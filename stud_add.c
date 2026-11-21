#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void add_record(struct student **head)
{
    struct student *newnode;
    struct student *temp;
    int roll=1;
    newnode=malloc(sizeof(struct student));
    if(newnode==NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    /* Find smallest available roll number */
    while(find_roll(*head, roll) != NULL)
        roll++;
    newnode->rollno=roll;
    read_name("Enter student name: ", newnode->name);
    do
    {
        newnode->percentage=read_float("Enter percentage (0-100): ");

        if(newnode->percentage < 0 || newnode->percentage > 100)
        {
            printf("Invalid percentage.\n");
        }

    } while (newnode->percentage < 0 || newnode->percentage > 100);
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        temp=*head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next=newnode;
    }
    printf("Record added successfully.\n");
    printf("Assigned Roll Number: %d\n", roll);
}