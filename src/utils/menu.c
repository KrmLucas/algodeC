#include <stdio.h>
#include "../../includes.h"

void printMenu () {
  system("clear");
  printf("INGRESE OPCION\n");
  printf("Altas -> 1\n");
  printf("Bajas -> 2\n");
  printf("Modificaciones -> 3\n");
  printf("Listados -> 4\n");
  printf("Salir -> 0\n");
}

void menu (int *opcion) {

  printMenu();
  scanf("%d", opcion);
  while ((0 >= *opcion && *opcion >= 4)){
    printf("Error. Opción incorrecta\n");
    //printMenu();
    scanf("%d", opcion);
  }
}