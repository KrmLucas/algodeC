#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   update.c
*
*
* @brief  actualizacion de un empleado { usa insert() y findById() - ver src/io/.. }
* @param  { - }
* @return { int } status
*
*
*/

int update (){

    int legajo;

    t_empleado * emp = malloc(sizeof(t_empleado));

    do {

        system("clear");
        printf("=========================================================================\n");
        printf("                            Modificar Empleado                            \n");
        printf("=========================================================================\n");
        printf("\n");

        legajo = enteroEnRango("[*] Ingrese N° de legajo: ", 0, MAX_LEGAJO);

        if (findById(emp, legajo)==SUCCESS) {

            printEmpleado(emp);
            if (confirma("Desea modificar el empleado? s/n")==SUCCESS){

                validateEmp(emp, legajo);
                insert(emp, -1);
            }

        } else {
            printf("No existe un empleado con ese legajo\n");
        }

    } while (confirma("Desea continuar? s/n")==SUCCESS);
    free(emp);
    return 0;
}
