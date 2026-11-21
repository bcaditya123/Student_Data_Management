#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

struct student_file_record
{
    int rollno;
    char name[NAME_SIZE];
    float percentage;
};
void save_records(const struct student *head)
{
    FILE *fp;
    struct student_file_record record;
    fp=fopen("student.dat", "wb");
    if(fp==NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    while (head!=NULL)
    {
        record.rollno=head->rollno;
        strcpy(record.name, head->name);
        record.percentage = head->percentage;
        if(fwrite(&record, sizeof(record), 1, fp)!=1)
        {
            printf("Error writing records.\n");
            fclose(fp);
            return;
        }
        head=head->next;
    }
    fclose(fp);
    printf("Records saved successfully.\n");
}

struct student *load_records(void)
{
    FILE *fp;
    struct student_file_record record;
    struct student *head = NULL;
    struct student *newnode;
    struct student *tail = NULL;
    fp=fopen("student.dat", "rb");
    if (fp==NULL)
        return NULL;
    while(fread(&record, sizeof(record), 1, fp) == 1)
    {
        if (record.rollno <= 0 ||record.name[0] == '\0' || record.percentage < 0 || record.percentage > 100 || find_roll(head, record.rollno) != NULL)
        {
            continue;
        }
        newnode=malloc(sizeof(struct student));
        if (newnode==NULL)
        {
            printf("Memory allocation failed.\n");
            break;
        }
        newnode->rollno=record.rollno;
        strncpy(newnode->name, record.name, NAME_SIZE - 1);
        newnode->name[NAME_SIZE - 1] = '\0';
        newnode->percentage=record.percentage;
        newnode->next=NULL;
        if (head==NULL)
        {
            head=newnode;
        }
        else
        {
            tail->next=newnode;
        }
        tail=newnode;
    }
    fclose(fp);
    return head;
}