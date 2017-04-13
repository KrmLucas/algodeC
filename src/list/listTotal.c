#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int listTotal (){

    FILE * fp;
    t_empleado * emp = malloc(sizeof(t_empleado));
    char cad[MAX_LINE];

    if ((fp = fopen(ARCH_EMP, "r"))!= NULL){
        system("clear");
        printf("======================================\n");
        printf("        Listado Total                 \n");
        printf("======================================\n");
        printf("\n");
        printf("Legajo \t Nombre \t Cargo\t \n");
        printf("--------------------------------------\n");
        while (fgets(cad, sizeof(cad), fp) != NULL ){

            strcpy(emp->nombre, "            \0");

            empToStruct(emp, cad);
            printTotal(emp);

        }
        getchar();
        fclose(fp);
    } else {
        printf("Archivo no existe\n");
        getchar();
        free(emp);
        return 1;
    }
    free(emp);
    getchar();
    return 0;
}
