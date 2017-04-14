#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   delete.c
*
*
* @brief  baja de un empleado { usa insert() y findById() - ver src/io/.. }
* @param  { - }
* @return { int } status
*
*
*/

int delete (){

    int legajo;

    t_empleado * emp = malloc(sizeof(t_empleado));

    do {

        system("clear");
        printf("=========================================================================\n");
        printf("                      Eliminar Empleado                            \n");
        printf("=========================================================================\n");
        printf("\n");

        legajo = enteroEnRango("[*] Ingrese N° de legajo: ", 0, MAX_LEGAJO);

        if (findById(emp, legajo)==SUCCESS) {

            printEmpleado(emp);
            if(confirma("desea eliminar el empleado? s/n\n")==SUCCESS){
              insert(emp, B);
            }

        } else {
            printf("No existe empleado con ese legajo\n");
        }

    } while (confirma("Desea continuar? s/n")==SUCCESS);
    free(emp);
    return 0;
}
