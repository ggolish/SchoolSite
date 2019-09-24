ceasar: main.o options.o ceasar.o
	gcc -o ceasar main.o options.o ceasar.o

main.o: main.c options.h ceasar.h
	gcc -c main.c

options.o: options.c options.h
	gcc -c options.c

ceasar.o: ceasar.c ceasar.h
	gcc -c ceasar.c

clean:
	rm -f *.o ceasar
