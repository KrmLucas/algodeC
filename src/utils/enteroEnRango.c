#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   enteroEnRango.c
*
*
* @brief  imprime un mensaje y valida el ingreso de un entero en un rango dado
* @param  { char *, int, int } - mensaje, limite inferior, limite superior
* @return { int } - status
*
*
*/

int enteroEnRango(char * msg, int princ, int fin){

    int num;
    do{
        printf("%s", msg);
        fflush(stdin);
        scanf("%d", &num);
    }while(num < princ || num >fin);

    return num;
}
