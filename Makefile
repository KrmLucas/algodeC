CRUD = create.o delete.o update.o
UTILS = src/utils/cleanString.c src/utils/confirma.c src/utils/enteroEnRango.c src/utils/flush_buff.c
EMPLEADO = validateEmp.o printEmpleado.o
LISTS = list.o encabezados.o menuLists.o

IO = insert.o findById.o findAll.o

CFLAGLS = -g -Wall

#Makefile
all: programa clean

#Enlazando para obtener .o
programa: main.o menu.o $(CRUD) $(EMPLEADO) $(IO) $(LISTS)
	gcc $(CFLAGLS) -o programa main.o menu.o $(CRUD) $(EMPLEADO) $(UTILS) $(IO) $(LISTS)

main.o: main.c includes.h
	gcc $(CFLAGLS) -c main.c
########################################
#		crud files
########################################
create.o: src/crud/create.c includes.h
	gcc $(CFLAGLS) -c src/crud/create.c

#read.o: src/crud/read.c includes.h
#	gcc $(CFLAGLS) -c src/crud/read.c

update.o: src/crud/update.c includes.h
	gcc $(CFLAGLS) -c src/crud/update.c

delete.o: src/crud/delete.c includes.h
	gcc $(CFLAGLS) -c src/crud/delete.c

#######################################
#		empleado files
#######################################
validateEmp.o: src/empleado/validateEmp.c includes.h
	gcc $(CFLAGLS) -c src/empleado/validateEmp.c

printEmpleado.o: src/empleado/printEmpleado.c includes.h
	gcc $(CFLAGLS) -c src/empleado/printEmpleado.c

#######################################
#		lists files
#######################################
list.o: src/list/list.c includes.h
	gcc $(CFLAGLS) -c src/list/list.c

encabezados.o: src/list/encabezados.c includes.h
	gcc $(CFLAGLS) -c src/list/encabezados.c

menuLists.o: src/list/menuLists.c includes.h
	gcc $(CFLAGLS) -c src/list/menuLists.c

menu.o: menu.c includes.h
	gcc $(CFLAGLS) -c menu.c
#-------------------
#	conexion files
conexion.o: data/conexion.c includes.h
	gcc $(CFLAGLS) -c data/conexion.c

insert.o: src/io/insert.c includes.h
	gcc $(CFLAGLS) -c src/io/insert.c

findById.o: src/io/findById.c includes.h
	gcc $(CFLAGLS) -c src/io/findById.c

findAll.o: src/io/findAll.c includes.h
	gcc $(CFLAGLS) -c src/io/findAll.c

clean:
	rm *.o
