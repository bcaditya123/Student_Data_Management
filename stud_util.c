#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "student.h"
static void clear_input_line(void)
{
    int ch;
    while((ch = getchar())!='\n' && ch!=EOF);
}

int read_int(const char *prompt)
{
    char line[100];
    char *end;
    long value;
    while (1)
    {
        printf("%s", prompt);
        if(fgets(line, sizeof(line), stdin)==NULL)
            return 0;

        /* Skip empty input */
        if (line[0] == '\n')
            continue;
        value=strtol(line, &end, 10);
        while(isspace((unsigned char)*end))
            end++;
        if(end!=line && *end=='\0' && value>= -2147483648L && value<=2147483647L)
            return (int)value;
        printf("Invalid integer. Try again.\n");
    }
}

float read_float(const char *prompt)
{
    char line[100];
    char *end;
    float value;
    while (1)
    {
        printf("%s", prompt);
        if(fgets(line, sizeof(line), stdin) == NULL)
            return -1.0f;
        /* Skip empty input */
        if(line[0] == '\n')
            continue;
        value=strtof(line, &end);
        while(isspace((unsigned char)*end))
            end++;
        if(end!=line && *end=='\0')
            return value;
        printf("Invalid number. Try again.\n");
    }
}

void read_name(const char *prompt, char name[])
{
    size_t len;
    while (1)
    {
        printf("%s", prompt);
        if(fgets(name, NAME_SIZE, stdin) == NULL)
        {
            name[0]='\0';
            return;
        }
        len=strlen(name);
        /* Skip empty input */
        if(len==1 && name[0]=='\n')
            continue;
        if(len>0 && name[len - 1]=='\n')
            name[len - 1]='\0';
        else
            clear_input_line();

        /* Remove leading spaces */
        while(name[0]==' ')
            memmove(name, name + 1, strlen(name));

        len=strlen(name);
        /* Remove trailing spaces */
        while(len>0 && name[len - 1]==' ')
            name[--len]='\0';
        if(len != 0)
            return;
        printf("Name cannot be empty.\n");
    }
}

struct student *find_roll(struct student *head, int rollno)
{
    while(head != NULL)
    {
        if(head->rollno == rollno)
            return head;

        head=head->next;
    }
    return NULL;
}

void show_one(const struct student *node)
{
    if(node!=NULL)
    {
        printf("%-10d %-30s %8.2f\n",node->rollno,node->name,node->percentage);
    }
}