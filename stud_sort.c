#include <stdio.h>
#include <string.h>
#include "student.h"

void sort_records(struct student **head)
{
    struct student *i;
    struct student *j;
    int swapped;
    int roll;
    float percentage;
    char name[NAME_SIZE];
    if (*head==NULL || (*head)->next==NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }
    do
    {
        swapped=0;
        for (i=*head; i->next!=NULL; i=i->next)
        {
            j=i->next;
            if(strcmp(i->name, j->name) > 0)
            {
                roll=i->rollno;
                i->rollno=j->rollno;
                j->rollno=roll;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);

                percentage=i->percentage;
                i->percentage=j->percentage;
                j->percentage=percentage;

                swapped=1;
            }
        }

    } while (swapped);
    printf("Sorted alphabetically by name.\n");
}

void sort_by_percentage(struct student **head)
{
    struct student *i;
    struct student *j;
    int swapped;
    int roll;
    float percentage;
    char name[NAME_SIZE];
    if (*head==NULL || (*head)->next==NULL)
    {
        printf("Not enough records to sort.\n");
        return;
    }
    do
    {
        swapped=0;

        for(i=*head; i->next!=NULL; i=i->next)
        {
            j=i->next;
            if(i->percentage < j->percentage)
            {
                roll=i->rollno;
                i->rollno=j->rollno;
                j->rollno=roll;

                strcpy(name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, name);

                percentage=i->percentage;
                i->percentage=j->percentage;
                j->percentage=percentage;
                swapped=1;
            }
        }

    } while (swapped);
    printf("Sorted by percentage in descending order.\n");
}