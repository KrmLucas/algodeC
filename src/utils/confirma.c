#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

/**
*
* @file   confirma.c
*
*
* @brief  imprime un mensaje de confirmacion y valida la entrada por si o no
* @param  { char * } - mensaje
* @return { int } - status
*
*
*/

int confirma(char * msg){
    char * input = malloc(MAX_BUFF);
    do{
        printf("%s\n", msg);
        fflush(stdin);
        scanf("%s", input);
    } while (!strcmp(input, "N") && !strcmp(input, "n") && !strcmp(input, "S") && !strcmp(input, "s"));

    if (strcmp(input, "N")==0 || strcmp(input, "n")==0){
        free(input);
        return FAILED;
    }
    free(input);
    return SUCCESS;
}

