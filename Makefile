#######################################################################

#   Makefile principal de la aplicacion
#   @Author:  Lucas Krmpotic
#   @Date:    abril 2017

#   Esta aplicación se hizo con el objetivo de ejercitar conceptos
#   del lenguaje ANSI C, como el manejo de punteros, estructuras , archivos,
#   memoria, entrada-salida, archivos cabecera, etc.-

#######################################################################


# Macros

CC= gcc
CFLAGLS = -g -Wall


# Dependencias

CRUD = create.o delete.o update.o read.o
EMPLEADO = validateEmp.o printEmpleado.o
LISTS = list.o encabezados.o menuLists.o
IO = insert.o findById.o findAll.o
UTILS = cleanString.o confirma.o enteroEnRango.o fechas.o


# Main rule
all: programa clean


# Linking modues

programa: main.o menu.o $(CRUD) $(EMPLEADO) $(IO) $(LISTS) $(UTILS)
	$(CC) $(CFLAGLS) -o programa main.o menu.o $(CRUD) $(EMPLEADO) $(UTILS) $(IO) $(LISTS)

main.o: main.c menu.o includes.h
	$(CC) $(CFLAGLS) -c main.c

menu.o: menu.c includes.h
	$(CC) $(CFLAGLS) -c menu.c



#	crud files

create.o: src/crud/create.c includes.h
	$(CC) $(CFLAGLS) -c src/crud/create.c

read.o: src/crud/read.c includes.h
	$(CC) $(CFLAGLS) -c src/crud/read.c

update.o: src/crud/update.c includes.h
	$(CC) $(CFLAGLS) -c src/crud/update.c

delete.o: src/crud/delete.c includes.h
	$(CC) $(CFLAGLS) -c src/crud/delete.c


#	empleado files

validateEmp.o: src/empleado/validateEmp.c includes.h
	$(CC) $(CFLAGLS) -c src/empleado/validateEmp.c

printEmpleado.o: src/empleado/printEmpleado.c includes.h
	$(CC) $(CFLAGLS) -c src/empleado/printEmpleado.c


#	lists files

list.o: src/list/list.c includes.h
	$(CC) $(CFLAGLS) -c src/list/list.c

encabezados.o: src/list/encabezados.c includes.h
	$(CC) $(CFLAGLS) -c src/list/encabezados.c

menuLists.o: src/list/menuLists.c includes.h
	$(CC) $(CFLAGLS) -c src/list/menuLists.c


#	io files


insert.o: src/io/insert.c includes.h
	$(CC) $(CFLAGLS) -c src/io/insert.c

findById.o: src/io/findById.c includes.h
	$(CC) $(CFLAGLS) -c src/io/findById.c

findAll.o: src/io/findAll.c includes.h
	$(CC) $(CFLAGLS) -c src/io/findAll.c

# utils files

fechas.o: src/utils/fechas.c includes.h
	$(CC) $(CFLAGLS) -c src/utils/fechas.c

enteroEnRango.o: src/utils/enteroEnRango.c includes.h
	$(CC) $(CFLAGLS) -c src/utils/enteroEnRango.c

cleanString.o: src/utils/cleanString.c includes.h
	$(CC) $(CFLAGLS) -c src/utils/cleanString.c

confirma.o: src/utils/confirma.c includes.h
	$(CC) $(CFLAGLS) -c src/utils/confirma.c

clean:
	rm *.o
