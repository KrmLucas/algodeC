#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   create.c
*
*
* @brief  alta de empleados { usa insert() y findById() - ver src/io/.. }
* @param  { - }
* @return { int } status
*
*
*/

int create (){

    int legajo;
    t_empleado * emp = malloc(sizeof(t_empleado));

    do {

        system("clear");
        printf("=========================================================================\n");
        printf("                            Ingresar Empleado                            \n");
        printf("=========================================================================\n");
        printf("\n");
        legajo = enteroEnRango("[*] Legajo: [Debe ser un entero positivo]\n", 0, MAX_LEGAJO);

        if (findById(emp, legajo)==SUCCESS) {

            printf("Ya existe un empleado con ese legajo\n");

        } else {

            validateEmp(emp, legajo);
            printEmpleado(emp);

            if (confirma("Desea agregar el empleado? s/n")==SUCCESS)
                insert(emp, -1)
                ;
        }

    } while(confirma("Desea continuar? s/n")==SUCCESS);
    free(emp);
    getchar();
    return 0;
}
