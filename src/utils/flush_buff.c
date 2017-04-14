#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   flush_buff.c
*
*
* @brief  vacia un las posiciones de memoria asignadas a un puntero a char
* @param  { char * } - puntero a cadena
* @return { - }
*
*
*/

void flush_buff(char * s) {

    while (*s!='\0'){
        s = '\0';
        s++;
    }
}
