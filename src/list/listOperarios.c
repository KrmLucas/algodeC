#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

int listOperarios (){

    FILE * fp;
    t_empleado * emp = malloc(sizeof(t_empleado));
    char cad[MAX_LINE];

    if ((fp = fopen(ARCH_EMP, "r"))!= NULL){
        system("clear");
        printf("=======================================\n");
        printf("           Listado Operarios           \n");
        printf("=======================================\n");
        printf("\n");
        printf("Legajo \t Nombre \t Categoria\t\n");
        printf("----------------------------------------------------\n");

        while (fgets(cad, sizeof(cad), fp) != NULL ){

            empToStruct(emp, cad);
            printOperario(emp);
        }
        getchar();
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
