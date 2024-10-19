CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -g

all: writer

writer: writer.o
	$(CC) -o $@ $^

writer.o: writer.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f writer writer.o
