#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   read.c
*
*
* @brief  busca un empleado e imprime sus datos
* @param  { - }
* @return { int } status
*
*
*/

int read (){

    int legajo;

    t_empleado * emp = malloc(sizeof(t_empleado));

    do {

        system("clear");
        printf("=========================================================================\n");
        printf("                      Buscar Empleado                              \n");
        printf("=========================================================================\n");
        printf("\n");

        legajo = enteroEnRango("[*] Ingrese N° de legajo: ", 0, MAX_LEGAJO);

        if (findById(emp, legajo)==SUCCESS) {

            printEmpleado(emp);

        } else {
            printf("No existe empleado con ese legajo\n");
        }

    } while (confirma("Desea continuar? s/n")==SUCCESS);
    free(emp);
    return 0;
}
