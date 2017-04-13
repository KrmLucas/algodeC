/*=====================================================================
                          CREAR EMPLEADO
=======================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int create (){
    FILE * fp;
    int key;
    char linea[MAX_LINE];
    t_empleado * emp = malloc(sizeof(t_empleado));
    fpos_t pos;

    do {
        system("clear");
        printf("=========================================================================\n");
        printf("                            Ingresar Empleado                            \n");
        printf("=========================================================================\n");
        printf("\n");
        key = enteroEnRango("[*] Legajo: [Debe ser un entero positivo]\n", 0, MAX_LEGAJO);

        if ((read(key, &pos)) != 0){
            getchar();
            validateEmp(emp, key);
            printEmpleado(emp);

            if (confirma("Desea agregar el empleado? s/n")==TRUE){

                if ((fp = fopen(ARCH_EMP, "ab"))!= NULL){
                      if (emp->cargo == jefe){
                          //fwrite(emp, sizeof(emp), 1, fp);

                          sprintf(linea, "%d\t %s\t %s\t %s\t %s\t %d\t \n", emp->legajo, emp->nombre, "jefe", emp->jerarquia.d2.nombreOficina, emp->jerarquia.d2.cantEmpleados, emp->activo);
                          fputs(linea, fp);

                      } else {
                          //fwrite(emp, sizeof(emp), 1, fp);

                          sprintf(linea, "%d\t %s\t %s\t %s\t %d\t \n", emp->legajo, emp->nombre, "operario", emp->jerarquia.d1.categoria, emp->activo);
                          fputs(linea, fp);



                      }
                    fclose(fp);
                } else {
                    printf("Archivo no existe\n");
                    free(emp);
                    return 1;
                }
            }
        } else {
            printf("Ya existe un empleado con ese legajo\n");
        }
    } while(confirma("Desea continuar? s/n")==TRUE);
    free(emp);
    getchar();
    return 0;
}
