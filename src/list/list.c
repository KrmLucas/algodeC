#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

/**
*
* @file   list.c
*
*
* @brief  enrutador de listados
* @param  { - }
* @return { int } - status
*
*
*/

int list(){

    static int opcion, salir = -1;

    do {
        opcion = menuList();
        switch (opcion) {
            case 0: salir=0; break;
            case 1: findAll(LIST_JERARQUICOS); break;
            case 2: findAll(LIST_NO_JERARQUICOS); break;
            case 3: findAll(LIST_ALL); break;
            default: break;
        }
        getchar();
    } while (salir != 0);

    return 0;
}
