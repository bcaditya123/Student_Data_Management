#include <stdio.h>
#include <ctype.h>
#include "student.h"

int main(void)
{
    struct student *head=NULL;
    char choice,subchoice;
    /* Load records when program starts */
    head=load_records();
    while(1)
    {
        printf("\n******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        getchar();

        switch(tolower((unsigned char)choice))
        {
            case 'a':
                add_record(&head);
                break;

            case 'd':
                delete_record(&head);
                break;

            case 's':
                show_records(head);
                break;

            case 'm':
                modify_record(head);
                break;

            case 'v':
                save_records(head);
                break;

            case 't':
                printf("N/n : Sort with name\n");
                printf("P/p : Sort with percentage\n");
                printf("Enter choice: ");
                scanf(" %c", &subchoice);
                getchar();

                if (tolower((unsigned char)subchoice)=='n')
                    sort_records(&head);

                else if (tolower((unsigned char)subchoice)=='p')
                    sort_by_percentage(&head);

                else
                    printf("Invalid sorting choice.\n");

                break;

            case 'l':
                delete_all(&head);
                printf("All records deleted successfully.\n");
                break;

            case 'r':
                reverse_records(&head);
                printf("List reversed successfully.\n");
                break;

            case 'e':
                printf("S/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter choice: ");
                scanf(" %c", &subchoice);
                if (tolower((unsigned char)subchoice) == 's')
                    save_records(head);

                else if (tolower((unsigned char)subchoice) != 'e')
                {
                    printf("Invalid choice.\n");
                    break;
                }
                delete_all(&head);
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid menu choice.\n");
        }
    }
    delete_all(&head);
    return 0;
}