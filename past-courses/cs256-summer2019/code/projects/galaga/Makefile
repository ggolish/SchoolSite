CC = gcc
CARGS = -Wall -g
LIBS = -lm -lncurses
OBJS = main.o galaga.o ship.o bullet.o alien.o
TARGET = galaga

$(TARGET): $(OBJS)
	$(CC) $(CARGS) -o $(TARGET) $(OBJS) $(LIBS)

main.o: main.c galaga.h
	$(CC) $(CARGS) -c main.c

galaga.o: galaga.c galaga.h ship.h
	$(CC) $(CARGS) -c galaga.c

ship.o: ship.c ship.h bullet.h alien.h
	$(CC) $(CARGS) -c ship.c

bullet.o: bullet.c bullet.h
	$(CC) $(CARGS) -c bullet.c

alien.o: alien.c alien.h bullet.h
	$(CC) $(CARGS) -c alien.c

clean:
	rm -f $(OBJS) $(TARGET)
