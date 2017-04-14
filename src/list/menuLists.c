#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

/**
*
* @file   menuLists.c
*
*
* @brief  imprime menu de listados
* @param  { - }
* @return { - }
*
*
*/

void printMenuLists () {
  system("clear");
  printf("==========================================\n");
  printf("              MENU DE LISTADOS            \n");
  printf("==========================================\n");
  printf("\n");
  printf("[*] Listado de jerárquicos -> 1\n");
  printf("[*] Listado de operarios -> 2\n");
  printf("[*] Listado total -> 3\n");
  printf("\n");
  printf("Salir -> 0\n");
}

int menuList () {

    static int opcion;
    printMenuLists ();
    return opcion = enteroEnRango(" ", 0, 3);

}
