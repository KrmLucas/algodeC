#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../includes.h"

/**
*
* @file   validateEmp.c
*
*
* @brief  valida el ingreso de datos para un registro de tipo empleado
* @param  {t_empleado *, int} - puntero a registro empleado - clave registro
* @return { int } - status
*
*
*/


int validateEmp(t_empleado * emp, int key){
    char * input = malloc(sizeof(MAX_BUFF));
    int opcion;
    flush_buff(input);
    emp->legajo = key;

    //Nombre
    cleanString("[*] Nombre: [No debe contener caracteres especiales ni numeros]\n", input);
    strncpy(emp->nombre, input, strlen(input));

    //Cargo
    opcion = enteroEnRango("[*] Cargo: [1-> Jerarquico - 2-> Operario]\n", 1, 2);

    if (opcion == 1) {
        //Jerarquico
        emp->cargo = jefe;

        //Nombre oficina
        cleanString("[*] Nombre de la oficina: \n", input);
        strcpy(emp->jerarquia.d2.nombreOficina, input);

        //Cantidad de empleados
        opcion = enteroEnRango("[*] Cantidad de empleados: [Debe ser un entero]\n", 0, 10000);
        emp->jerarquia.d2.cantEmpleados = opcion;

    } else {
        //Operario
        emp->cargo = operario;

        //Categoria
        cleanString("[*] Categoría: [No debe contener caracteres especiales ni numeros]\n", input);
        strcpy(emp->jerarquia.d1.categoria, input);

    }
    emp->activo = 1;
    free(input);
    return 0;
}
