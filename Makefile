CC=gcc
CFLAGS=-Wall -Wextra -std=c11
TARGET=student
OBJS=stud_main.o stud_util.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_save.o stud_sort.o stud_list.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o: %.c student.h
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(OBJS) $(TARGET)
.PHONY: clean