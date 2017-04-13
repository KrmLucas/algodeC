#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

int listJefes (){

    FILE * fp;
    t_empleado * emp = malloc(sizeof(t_empleado));
    char cad[MAX_LINE];


    if ((fp = fopen(ARCH_EMP, "r"))!= NULL){
        system("clear");
        printf("==============================================================================\n");
        printf("                      Listado Personal Jerarquico                      \n");
        printf("==============================================================================\n");
        printf("\n");
        printf("Legajo\t\t Nombre\t\t Oficina\t\t  Cantidad Empleados\t\n");
        printf("------------------------------------------------------------------------------\n");

        while (fgets(cad, sizeof(cad), fp) != NULL ){

            empToStruct(emp, cad);
            if (emp->cargo == jefe)
                printJefe(emp);

        }
        fclose(fp);
    } else {
        printf("Archivo no existe\n");
        free(emp);
        getchar();
        return 1;
    }
    free(emp);
    getchar();
    return 0;
}
