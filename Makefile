CC = gcc
CFLAGS = -Wall

all: process_creation exercise2 exercise3 exercise4 output_program simple_program

process_creation: process_creation.c
	$(CC) $(CFLAGS) -o process_creation process_creation.c

exercise2: exercise2.c
	$(CC) $(CFLAGS) -o exercise2 exercise2.c

exercise3: exercise3.c
	$(CC) $(CFLAGS) -o exercise3 exercise3.c

exercise4: exercise4.c
	$(CC) $(CFLAGS) -o exercise4 exercise4.c

output_program: file1.c file2.c
	$(CC) $(CFLAGS) file1.c file2.c -o output_program

simple_program: simple_program.c
	$(CC) $(CFLAGS) -o simple_program simple_program.c

clean:
	rm -f process_creation exercise2 exercise3 exercise4 output_program simple_program *.exe
