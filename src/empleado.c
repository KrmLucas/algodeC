#include <stdio.h>
#include <stdlib.h>
#include "../includes.h"

/*=======================================================================================
                EMPLEADO 
========================================================================================*/
int f_empleado () {

    #define MAX 50
    typedef  enum {
        empleado,jefe
    } t_tipoempleado;

    typedef struct { 
        char categoria[MAX];
    } t_empleado_nojerarquico;

    typedef struct {
        char nombreOficina[MAX];
        int  cantEmpleados;
    } t_empleado_jerarquico;

    typedef union {
            t_empleado_nojerarquico d1;
            t_empleado_jerarquico d2;
    } templeado;

    typedef struct {
        char legajo[MAX];
        char nombre[MAX];
        t_tipoempleado cargo;
        templeado jerarquia;
    }t_empleado;

    t_empleado * emp = malloc(sizeof(t_empleado));
    
    if (emp == NULL) {
        printf("No hay memoria"); 
        return 1;
    }

    printf("Ingrese Empleado\n");
    
    printf("Legajo: \n");
    scanf("%s", emp->legajo); 
    
    printf("Nombre: \n");
    scanf("%s", emp->nombre);
    
    printf("Cargo: \n");
    scanf("%s", emp->cargo);

    if (emp->cargo == jefe) {
        printf("Oficina: \n");
        scanf("%s", emp->jerarquia.d2.nombreOficina);

        printf("Cantidad de empleados: \n");
        scanf("%s", emp->jerarquia.d2.cantEmpleados);
    } else {
        printf("Categoría\n: ");
        scanf("%d", emp->jerarquia.d1.categoria);
    }

    free(emp);
    char c;
    scanf("%c", &c);
    return 0;
}

