#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   findById.c
*
*
* @brief  busca registro de empleado segun clave ( legajo )
* @param  {t_empleado *, int } - puntero a registro, clave ( legajo )
* @return { int } - status
*
*
*/

int findById (t_empleado * emp, int legajo){

    FILE * fp; /*   file pointer    */
    FILE * ip; /*   index pointer   */
    int clave, status, tipoReg, cant_empleados, flag;
    long unsigned pos_f;
    char * nombre = malloc(sizeof(emp->nombre));
    char * fecha = malloc(sizeof(emp->fecha));
    char * nombre_oficina = malloc(sizeof(emp->jerarquia.d2.nombreOficina));
    char * categoria = malloc(sizeof(emp->jerarquia.d1.categoria));
    char * strCargo = malloc(strlen("jerarquico"));

    if (((fp = fopen(ARCH_EMP, "rb+"))==NULL) || ((ip = fopen(ARCH_INDEX, "rb+"))==NULL)) {

        printf("Error al abrir archivo\n");
        getchar();
        if (fp == NULL) fclose(fp);
        if (ip == NULL) fclose(fp);
        return FAILED;

    } else {
        flag = FALSE;
        while (!feof(ip)) {

            fscanf(ip, "%d\t" "%d\t" "%d\t" "%lu\t\n", &clave, &status, &tipoReg, &pos_f);
            if ((clave == legajo) && (status == ACTIVO)) {
                flag = TRUE;
                break;
            }
        }
        if (flag == FALSE){
            fclose(fp);
            fclose(ip);
            return FAILED;

        } else {

            fseek(fp, pos_f, SEEK_SET);
            if ( tipoReg == JERARQUICO) {

                fscanf(fp, "%d\t %s\t %s\t %s\t %s\t %d\t \n", &clave, nombre, fecha, strCargo, nombre_oficina, &cant_empleados);
                emp->cargo = jefe;
                strncpy(emp->jerarquia.d2.nombreOficina, nombre_oficina, strlen(nombre_oficina));
                emp->jerarquia.d2.cantEmpleados = cant_empleados;

            } else {

                fscanf(fp, "%d\t %s\t %s\t %s\t %s\t \n", &clave, nombre, fecha, strCargo, categoria);
                emp->cargo = operario;
                strncpy(emp->jerarquia.d1.categoria, categoria, strlen(categoria));
            }
            emp->legajo = clave;
            strncpy(emp->nombre, nombre, strlen(nombre));
            strncpy(emp->fecha, fecha, strlen(fecha));
            fclose(fp);
            fclose(ip);
            return SUCCESS;
        }

    }

}

