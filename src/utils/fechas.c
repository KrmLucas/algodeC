#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../includes.h"

/**
*
* @file   fechas.c
* @brief  valida el ingreso de una fecha
*
*/


/**
* @brief  valida la correccion de la fecha por año bisiesto
* @param  { int*, int*,int* } - dia, mes y año
* @return { int } - status
*/
int validateFecha (int * dia, int * mes, int * anio){

    *anio = enteroEnRango("[*] Ingrese año: ", 0, *anio);
    *mes =  enteroEnRango("[*] Ingrese mes: ", 1, 12);

    switch (*mes) {
        case 4: case 6: case 9: case 11:
            *dia = enteroEnRango("[*] Ingrese dia: ", 0, 30);
            break;
        case 2:
            if (((*anio%4==0) && (*anio%100!=0)) || *anio%400==0){

                *dia = enteroEnRango("[*] Ingrese dia: ", 0, 29);

            } else {

                *dia = enteroEnRango("[*] Ingrese dia: ", 0, 28);
            }
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                *dia = enteroEnRango("[*] Ingrese dia: ", 0, 31);
            break;
    }
    return 0;

}

/**
* @brief  inicializa estructuras y variables para fecha
* @param  { char * } - puntero al arreglo que pretende la fecha valida
* @return { int } - status
*/
int getFecha (char * input){

    struct tm * fecha;

    time_t sisTime;
    time(&sisTime);
    fecha=localtime(&sisTime);

    int dia, mes, anio;

    dia=fecha->tm_mday;
    mes=fecha->tm_mon;
    anio=(fecha->tm_year)+1900;
    printf("[*] Fecha de nacimiento\n");
    validateFecha(&dia, &mes, &anio);

    sprintf(input, "%d/%d/%d", dia, mes, anio);
    getchar();

    return 0;
}
