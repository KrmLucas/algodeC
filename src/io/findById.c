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
    char * nombre_oficina = malloc(sizeof(emp->jerarquia.d2.nombreOficina));
    char * categoria = malloc(sizeof(emp->jerarquia.d1.categoria));

    flush_buff(nombre);
    flush_buff(nombre_oficina);
    flush_buff(categoria);

    if (((fp = fopen(ARCH_EMP, "rb+"))==NULL) || ((ip = fopen(ARCH_INDEX, "rb+"))==NULL)) {

        printf("Error al abrir archivo\n");
        getchar();
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
            return FAILED;

        } else {

            fseek(fp, pos_f, SEEK_SET);
            if ( tipoReg == JERARQUICO) {

                fscanf(fp, "%d\t %s\t %s\t %d\t %d\t \n", &clave, nombre, nombre_oficina, &cant_empleados, &status);
                emp->cargo = jefe;
                strncpy(emp->jerarquia.d2.nombreOficina, nombre_oficina, strlen(nombre_oficina));
                emp->jerarquia.d2.cantEmpleados = cant_empleados;

            } else {

                fscanf(fp, "%d\t %s\t %s\t %d\t \n", &clave, nombre, categoria, &status);
                emp->cargo = operario;
                strncpy(emp->jerarquia.d1.categoria, categoria, strlen(categoria));
            }
            emp->legajo = clave;
            printf("NOMBRE ANTES: %s", emp->nombre);
            getchar();
            strncpy(emp->nombre, nombre, strlen(nombre));
            emp->activo = status;
            return SUCCESS;
        }

    }

}

