all: main.o rubro_negra.o
	gcc main.o rubro_negra.o -o t3 -Wall -pedantic
run: t3
	./t3
main.o: main.c rubro_negra.h
	gcc -c main.c -o main.o -Wall -pedantic
rubro_negra.o: rubro_negra.c rubro_negra.h
	gcc -c rubro_negra.c -o rubro_negra.o -Wall -pedantic
clean:
	rm -rf main *o