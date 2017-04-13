#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int printEmpleado (t_empleado * emp){

    system("clear");
    printf("===================================================\n");
    printf("=============== Datos del Empleado ================\n");
    printf("===================================================\n");
    printf("\n");
    printf("[*] Legajo: %d\n", emp->legajo);
    printf("[*] Nombre: %s\n", emp->nombre);
    if (emp->cargo == jefe){
        printf("[*] cargo: Jefe\n");
        printf("[*] Oficina: %s\n", emp->jerarquia.d2.nombreOficina);
        printf("[*] Cantidad de empleados: %s\n", emp->jerarquia.d2.cantEmpleados);
    } else {
        printf("[*] cargo: Operario\n");
        printf("[*] Oficina: %s\n", emp->jerarquia.d1.categoria);
    }
    printf("\n");
    return 0;

}



