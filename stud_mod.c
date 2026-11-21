#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "student.h"

static void update_student(struct student *node)
{
    char name[NAME_SIZE];
    float percentage;
    printf("\nCurrent details:\n");
    show_one(node);
    read_name("Enter updated name: ", name);
    do
    {
        percentage=read_float("Enter updated percentage (0-100): ");
        if(percentage < 0 || percentage > 100)
            printf("Invalid percentage.\n");

    } while(percentage < 0 || percentage > 100);
    strcpy(node->name, name);
    node->percentage = percentage;
    printf("Record modified successfully.\n");
}

void modify_record(struct student *head)
{
    char choice;
    char name[NAME_SIZE];
    struct student *temp;
    struct student *match = NULL;
    int roll;
    int count=0;
    float percentage;
    if(head==NULL)
    {
        printf("No student records available.\n");
        return;
    }
    printf("Enter which record to search for modification\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &choice);
    getchar();
    switch(tolower((unsigned char)choice))
    {
        case 'r':
            roll=read_int("Enter roll number: ");
            match=find_roll(head, roll);
            if(match==NULL)
                printf("Roll number not found.\n");
            else
                update_student(match);

            break;

        case 'n':
            read_name("Enter name: ", name);
            for(temp=head; temp!=NULL; temp=temp->next)
            {
                if(strcmp(temp->name, name)==0)
                {
                    show_one(temp);
                    match=temp;
                    count++;
                }
            }
            if(count==0)
            {
                printf("Name not found.\n");
            }
            else
            {
                roll=read_int("Enter roll number of record to modify: ");
                match=find_roll(head, roll);
                if(match==NULL || strcmp(match->name, name)!=0)
                {
                    printf("Selected record does not match.\n");
                }
                else
                {
                    update_student(match);
                }
            }
            break;
        case 'p':
            percentage=read_float("Enter percentage to search: ");
            for(temp=head; temp!=NULL; temp=temp->next)
            {
                if(temp->percentage==percentage)
                {
                    show_one(temp);
                    match=temp;
                    count++;
                }
            }
            if(count==0)
            {
                printf("Percentage not found.\n");
            }
            else
            {
                roll=read_int("Enter roll number of record to modify: ");
                match=find_roll(head, roll);
                if(match==NULL || match->percentage!=percentage)
                {
                    printf("Selected record does not match.\n");
                }
                else
                {
                    update_student(match);
                }
            }
            break;
        default:
            printf("Invalid modification choice.\n");
    }
}