#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

/**
*
* @file
*
*
* @brief
* @param
* @return
*
*
*/
/*
int read (int legajo){

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
                return SUCCESS;
            }
            fgetpos(fp, pos);
        }
        fclose(fp);
        free(emp);
        return FAILED;
    } else {
      printf("No existe archivo\n");
      free(emp);
      return FAILED;
    }
}
*/
