#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

static int delete_by_roll(struct student **head, int roll)
{
    struct student *temp=*head;
    struct student *prev=NULL;
    while(temp!=NULL && temp->rollno!=roll)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        return 0;
    if(prev==NULL)
        *head=temp->next;
    else
        prev->next=temp->next;
    free(temp);
    return 1;
}

void delete_record(struct student **head)
{
    char choice;
    char name[NAME_SIZE];
    struct student *temp;
    int roll;
    int found=0;
    printf("R/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    if(tolower((unsigned char)choice)=='r')
    {
        roll=read_int("Enter roll number: ");
        if(delete_by_roll(head, roll))
            printf("Record deleted successfully.\n");
        else
            printf("Roll number not found.\n");
    }

    else if(tolower((unsigned char)choice) == 'n')
    {
        read_name("Enter name: ", name);
        printf("\nRoll No. Name Percentage\n");

        for(temp=*head; temp!=NULL; temp=temp->next)
        {
            if(strcmp(temp->name, name)==0)
            {
                show_one(temp);
                found++;
            }
        }
        if (found==0)
        {
            printf("Name not found.\n");
            return;
        }
        roll=read_int("Enter roll number to delete: ");
        if(delete_by_roll(head, roll))
            printf("Record deleted successfully.\n");
        else
            printf("Invalid roll number.\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }
}