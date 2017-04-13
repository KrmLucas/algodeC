/*=====================================================================
                          MOSTRAR EMPLEADO
=======================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

int read (int legajo, fpos_t * pos){

    char cad[MAX_LINE];
    int key;

    FILE * fp;
    t_empleado * emp = malloc(sizeof(t_empleado));

    if ((fp = fopen(ARCH_EMP, "rb+"))!= NULL){
        //aux = ftell(fp);
        fgetpos(fp, pos);
        while (fgets(cad, sizeof(cad), fp)!= NULL){

            empToStruct(emp, cad);
            key = emp->legajo;

            if ((key == legajo) && (emp->activo == ACTIVO)){

                fclose(fp);
                free(emp);
                return 0;
            }
            fgetpos(fp, pos);
        }
        fclose(fp);
        free(emp);
        return 1;
    } else {
      printf("No existe archivo\n");
      free(emp);
      return 1;
    }
}
