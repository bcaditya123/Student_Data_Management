#ifndef STUDENT_H
#define STUDENT_H
#define NAME_SIZE 50
struct student
{
    int rollno;
    char name[NAME_SIZE];
    float percentage;
    struct student *next;
};
/* Common functions */
int read_int(const char *prompt);
float read_float(const char *prompt);
void read_name(const char *prompt, char name[]);
struct student *find_roll(struct student *head, int rollno);
void show_one(const struct student *node);
/* Project functions */
void add_record(struct student **head);
void delete_record(struct student **head);
void show_records(const struct student *head);
void modify_record(struct student *head);
void save_records(const struct student *head);
struct student *load_records(void);
void sort_records(struct student **head);
void sort_by_percentage(struct student **head);
void delete_all(struct student **head);
void reverse_records(struct student **head);
#endif