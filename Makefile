CRUD = create.o read.o update.o delete.o
UTILS = src/utils/menu.c

CFLAGLS = -g -Wall

#Makefile
all: programa clean

#Enlazando para obtener .o 
programa: main.o empleado.o $(CRUD)
	gcc $(CFLAGLS) -o programa main.o $(CRUD) empleado.o $(UTILS)

main.o: main.c includes.h
	gcc $(CFLAGLS) -c main.c

create.o: src/crud/create.c includes.h
	gcc $(CFLAGLS) -c src/crud/create.c

read.o: src/crud/read.c includes.h
	gcc $(CFLAGLS) -c src/crud/read.c

update.o: src/crud/update.c includes.h
	gcc $(CFLAGLS) -c src/crud/update.c

delete.o: src/crud/delete.c includes.h
	gcc $(CFLAGLS) -c src/crud/delete.c

empleado.o: src/empleado.c includes.h
	gcc $(CFLAGLS) -c src/empleado.c

clean: 
	rm *.o
 