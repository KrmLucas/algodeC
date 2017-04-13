/*=====================================================================
                          BAJAS
=======================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int delete (){

    int legajo;
    char cad[MAX_LINE];

    t_empleado * emp = malloc(sizeof(t_empleado));
    FILE * fp;
    fpos_t pos;

    do {

        system("clear");
        printf("=========================================================================\n");
        printf("                            Eliminar Empleado                            \n");
        printf("=========================================================================\n");
        printf("\n");

        legajo = enteroEnRango("[*] Ingrese N° de legajo: ", 0, MAX_LEGAJO);

        if ((read(legajo, &pos)) != 0){
            printf("No existe empleado con ese legajo\n");

        } else {

            if ((fp = fopen(ARCH_EMP, "rb+"))!=NULL) {

                //fseek(fp, pos, SEEK_SET);

                fsetpos(fp, &pos);
                fgets(cad, sizeof(cad), fp);
                empToStruct(emp, cad);
                printEmpleado(emp);

                if(confirma("desea eliminar el empleado? s/n\n")==TRUE){

                    emp->activo = 0;
                    //fseek(fp, pos, SEEK_SET);
                    fsetpos(fp, &pos);
                    if (emp->cargo == jefe){
                          sprintf(cad, "%d\t %s\t %s\t %s\t %s\t %d\t \n", emp->legajo, emp->nombre, "jefe", emp->jerarquia.d2.nombreOficina, emp->jerarquia.d2.cantEmpleados, emp->activo);
                          fputs(cad, fp);
                    } else {
                          sprintf(cad, "%d\t %s\t %s\t %s\t %d\t \n", emp->legajo, emp->nombre, "operario", emp->jerarquia.d1.categoria, emp->activo);
                          fputs(cad, fp);
                    }
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
