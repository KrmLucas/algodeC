CRUD = create.o read.o update.o delete.o
UTILS = src/utils/menu.c src/utils/cleanString.c src/utils/confirma.c src/utils/enteroEnRango.c
EMPLEADO = validateEmp.o empToStruct.o printEmpleado.o printJefe.o printOperario.o printTotal.o
LISTS = list.o listJefes.o listOperarios.o listTotal.o menuLists.o

CFLAGLS = -g -Wall

#Makefile
all: programa clean

#Enlazando para obtener .o
programa: main.o $(CRUD) $(EMPLEADO) $(LISTS)
	gcc $(CFLAGLS) -o programa main.o $(CRUD) $(EMPLEADO) $(LISTS) $(UTILS)

main.o: main.c includes.h
	gcc $(CFLAGLS) -c main.c
########################################
#		crud files
########################################
create.o: src/crud/create.c includes.h
	gcc $(CFLAGLS) -c src/crud/create.c

read.o: src/crud/read.c includes.h
	gcc $(CFLAGLS) -c src/crud/read.c

update.o: src/crud/update.c includes.h
	gcc $(CFLAGLS) -c src/crud/update.c

delete.o: src/crud/delete.c includes.h
	gcc $(CFLAGLS) -c src/crud/delete.c

#######################################
#		empleado files
#######################################
validateEmp.o: src/empleado/validateEmp.c includes.h
	gcc $(CFLAGLS) -c src/empleado/validateEmp.c

empToStruct.o: src/empleado/empToStruct.c includes.h
	gcc $(CFLAGLS) -c src/empleado/empToStruct.c

printEmpleado.o: src/empleado/printEmpleado.c includes.h
	gcc $(CFLAGLS) -c src/empleado/printEmpleado.c

printJefe.o: src/empleado/printJefe.c includes.h
	gcc $(CFLAGLS) -c src/empleado/printJefe.c

printOperario.o: src/empleado/printOperario.c includes.h
	gcc $(CFLAGLS) -c src/empleado/printOperario.c

printTotal.o: src/empleado/printTotal.c includes.h
	gcc $(CFLAGLS) -c src/empleado/printTotal.c
#######################################
#		lists files
#######################################
list.o: src/list/list.c includes.h
	gcc $(CFLAGLS) -c src/list/list.c

listJefes.o: src/list/listJefes.c includes.h
	gcc $(CFLAGLS) -c src/list/listJefes.c

listOperarios.o: src/list/listOperarios.c includes.h
	gcc $(CFLAGLS) -c src/list/listOperarios.c

listTotal.o: src/list/listTotal.c includes.h
	gcc $(CFLAGLS) -c src/list/listTotal.c

menuLists.o: src/list/menuLists.c includes.h
	gcc $(CFLAGLS) -c src/list/menuLists.c

#-------------------
#	conexion files
conexion.o: data/conexion.c includes.h
	gcc $(CFLAGLS) -c data/conexion.c

clean:
	rm *.o
