#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int enteroEnRango(char * msg, int princ, int fin){

    int num;
    do{
        printf("%s", msg);
        scanf("%d", &num)
        //while (scanf("%d", &num)==0)
            ;
    }while(num < princ || num >fin);

    return num;
}
