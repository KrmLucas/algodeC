/*=====================================================================
                          BAJAS
=======================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int update (){

    int legajo;
    char cad[MAX_LINE];

    t_empleado * emp = malloc(sizeof(t_empleado));
    FILE * fp;
    fpos_t pos;

    do {

        system("clear");
        printf("=========================================================================\n");
        printf("                            Modificar Empleado                            \n");
        printf("=========================================================================\n");
        printf("\n");

        legajo = enteroEnRango("[*] Ingrese N° de legajo: ", 0, MAX_LEGAJO);

        if ((read(legajo, &pos)) != 0){
            printf("No existe empleado con ese legajo\n");

        } else {

            if ((fp = fopen(ARCH_EMP, "rb+"))!=NULL) {

                fsetpos(fp, &pos);
                fgets(cad, sizeof(cad), fp);
                empToStruct(emp, cad);
                printEmpleado(emp);

                if(confirma("desea modificar el empleado? s/n\n")==TRUE){

                    validateEmp(emp, legajo);
                    fsetpos(fp, &pos);

                    fputs(cad, fp);

                }
                fclose(fp);

            } else {
                printf("Error al abrir el archivo de datos\n");
                free(emp);
                return 1;
            }
        }

    } while (confirma("Desea continuar? s/n")==TRUE);
    free(emp);
    return 0;
}
