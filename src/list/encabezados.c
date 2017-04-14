#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

/**
*
* @file   encabezados.c
*
*
* @brief  imprime encabezados de listados { llamados por "findAll()" ver src/io/fincAll.c }
* @param  { - }
* @return { - }
*
*
*/

void enc_jefes (){

    system("clear");
    printf("==============================================================================\n");
    printf("                      Listado Personal Jerarquico                      \n");
    printf("==============================================================================\n");
    printf("\n");
    printf("Legajo\t Nombre\t\t Fecha Nac\t Oficina\t  Cantidad Empleados\t\n");
    printf("------------------------------------------------------------------------------\n");

}

void enc_operarios (){

    system("clear");
    printf("==========================================================================\n");
    printf("                           Listado Operarios                              \n");
    printf("==========================================================================\n");
    printf("\n");
    printf("Legajo \t\t Nombre \t Fecha Nac\t Categoria\t\t\n");
    printf("--------------------------------------------------------------------------\n");

}

void enc_total (){

    system("clear");
    printf("==========================================================================\n");
    printf("                            Listado Total                                 \n");
    printf("==========================================================================\n");
    printf("\n");
    printf("Legajo \t\t Nombre \t Fecha Nac\t Cargo\t\t \n");
    printf("--------------------------------------------------------------------------\n");

}

