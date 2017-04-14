#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   cleanString.c
*
*
* @brief  valida una cadena por ausencia de caracteres especiales y numeros
* @param  { char * } - puntero a cadena de entrada
* @return { int } - status
*
*
*/

int clean (char * cad){

    for (int i = 0; i<strlen(cad); i++){
        if (cad[i] < 65 && cad[i] != 32)
            return 1;
        if (cad[i] > 90 && cad[i]< 97)
            return 1;
        if (cad[i] > 122 && cad[i] < 160 && cad[i] != 130)
            return 1;
        if (cad[i] > 165)
            return 1;
    }
    return 0;
}

int cleanString(char * msge, char * cad) {

    do {
        printf("%s", msge);
        scanf(" %[^\n]", cad);
        strcat(cad, "\0");
    } while (clean(cad) == 1);

    return 0;
}
