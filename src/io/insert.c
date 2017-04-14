#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
* @file   insert.c
*
* @brief  inserta registro en archivo de empleados en coherencia con archivo de indices
* @param  { t_empleado *, int } - puntero a empleado y mode (insercion o baja).
* @return { int } - status
*
*/

int insert(t_empleado * emp, int mode){

    FILE * fp; /*   file pointer    */
    FILE * ip; /*   index pointer   */
    int clave, status, tipoReg, flag;
    long unsigned pos_f, pos_i;

    if (((fp = fopen(ARCH_EMP, "ab"))==NULL) || ((ip = fopen(ARCH_INDEX, "rb+"))==NULL)) {

        printf("Error al abrir archivo\n");
        return FAILED;

    } else {
        flag = FALSE;
        pos_i = ftell(ip);

        /*  Recorremos archivo de indices para verificar si existe el empleado  */
        while (!feof(ip)) {

            fscanf(ip, "%d\t" "%d\t" "%d\t" "%lu\t \n", &clave, &status, &tipoReg, &pos_f);
            if ((clave == emp->legajo) && (status == ACTIVO)) {
                //Empleado existe
                flag = TRUE;
                break;
            }
            pos_i = ftell(ip);
        }
        if (flag == FALSE){
            /*  No existe empleado, insertamos normalmente*/
            if (emp->cargo == jefe){
                tipoReg = JERARQUICO;

                //datos
                pos_f = ftell(fp);
                fprintf(fp, "%d\t %s\t %s\t %s\t %d\t %d\t \n", emp->legajo, emp->nombre, "jerarquico", emp->jerarquia.d2.nombreOficina, emp->jerarquia.d2.cantEmpleados, emp->activo);

            } else {
                tipoReg = NO_JERARQUICO;
                //datos
                pos_f = ftell(fp);
                fprintf(fp, "%d\t %s\t %s\t %s\t %d\t \n", emp->legajo, emp->nombre, "operario", emp->jerarquia.d1.categoria, emp->activo);

            }
            //insertamos en el archivo de indices
            fseek(ip, pos_i, SEEK_SET);
            fprintf(ip, "%d\t" "%d\t" "%d\t" "%lu\t \n", emp->legajo, ACTIVO, tipoReg, pos_f);

        } else {
            /*  Existe empleado - Tipo de insercion depende del parametro options */

            if (mode == B){
                /*  options en modo baja modifico solo el arch de indices  */
                fseek(ip, pos_i, SEEK_SET);
                fprintf(ip, "%d\t" "%d\t" "%d\t" "%lu\t \n", clave, BAJA, tipoReg, pos_f);

            } else {

                /*  options en modo modificacion es necesario modificar ambos archivos  */
                if (emp->cargo == jefe){
                    tipoReg = JERARQUICO;
                    /*  Arch de datos  */
                    pos_f = ftell(fp); //Posicion de comienzo del registro
                    fprintf(fp, "%d\t %s\t %s\t %s\t %d\t %d\t \n", emp->legajo, emp->nombre, "jerarquico", emp->jerarquia.d2.nombreOficina, emp->jerarquia.d2.cantEmpleados, emp->activo);

                } else {
                    tipoReg = NO_JERARQUICO;
                    /* Arch de datos*/
                    pos_f = ftell(fp);
                    fprintf(fp, "%d\t %s\t %s\t %s\t %d\t \n", emp->legajo, emp->nombre, "operario", emp->jerarquia.d1.categoria, emp->activo);

                }
                /*  Arch de indices  */
                fseek(ip, pos_i, SEEK_SET); //debo
                fprintf(ip, "%d\t %d\t %d\t %lu\t\n", emp->legajo, ACTIVO, tipoReg, pos_f);

            }

        }
        fclose(fp);
        fclose(ip);
        return SUCCESS;
    }

}
