CC = gcc
CARGS = -Wall -g
OBJS = main.o htable.o
TARGET = htable-demo

%.o: %.c 
	$(CC) $(CARGS) -o $@ -c $<

$(TARGET): $(OBJS)
	$(CC) $(CARGS) -o $(TARGET) $^

main.o: main.c

htable.o: htable.c htable.h

clean:
	rm -f $(OBJS) $(TARGET)
