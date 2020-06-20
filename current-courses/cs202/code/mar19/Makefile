CC = gcc
CARGS = -Wall -g
OBJS = main.o btree.o
TARGET = btree

%.o: %.c
	$(CC) $(CARGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CARGS) -o $@ $^

main.o: main.c btree.h

btree.o: btree.c btree.h

clean:
	rm -f $(TARGET) $(OBJS)
