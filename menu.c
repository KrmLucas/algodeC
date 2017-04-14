#include <stdio.h>
#include <stdlib.h>
#include "includes.h"

/**
*
* @file   menu.c
*
*
* @brief  imprime el menu principal de la aplicacion
* @param  { - }
* @return { - }
*
*
*/

void printMenu () {
  system("clear");
  printf("============================================================================\n");
  printf("                              MENU PRINCIPAL                                \n");
  printf("============================================================================\n");
  printf("\n");
  printf("[*] Altas -> 1\n");
  printf("[*] Bajas -> 2\n");
  printf("[*] Modificaciones -> 3\n");
  printf("[*] Busqueda -> 4\n");
  printf("[*] Listados -> 5\n");
  printf("\n");
  printf("Salir -> 0\n");
}

int menu (int princ, int fin) {

    int opcion;
    printMenu();
    return opcion = enteroEnRango(" ", princ, fin);

}
