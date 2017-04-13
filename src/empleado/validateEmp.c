#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../includes.h"


int validateEmp(t_empleado * emp, int key){
    char input[MAX_BUFF];
    int opcion;

    //Nro Legajo
    //opcion = enteroEnRango("[*] Legajo: [Debe ser un entero positivo]\n", 0, MAX_LEGAJO);
    emp->legajo = key;

    //Nombre
    cleanString("[*] Nombre: [No debe contener caracteres especiales ni numeros]\n", input);
    strncpy(emp->nombre, input, strlen(input));

    //Cargo
    fflush(stdin);
    opcion = enteroEnRango("[*] Cargo: [1-> Jerarquico - 2-> Operario]\n", 1, 2);

    if (opcion == 1) {
        //Jerarquico
        emp->cargo = jefe;

        //Nombre oficina
        cleanString("[*] Nombre de la oficina: \n", input);
        strcpy(emp->jerarquia.d2.nombreOficina, input);

        //Cantidad de empleados
        fflush(stdin);
        opcion = enteroEnRango("[*] Cantidad de empleados: [Debe ser un entero]\n", 0, 10000);
        sprintf(emp->jerarquia.d2.cantEmpleados, "%d", opcion);
    } else {
        //Operario
        emp->cargo = operario;

        //Categoria
        fflush(stdin);
        cleanString("[*] Categoría: [No debe contener caracteres especiales ni numeros]\n", input);
        strcpy(emp->jerarquia.d1.categoria, input);
    }
    emp->activo = 1;
    //strcpy(emp->activo, ACTIVO);
    return 0;
}
