/*
===========================================================================================
*
* Definir una estructura de datos para almacenar la información del personal de la
* empresa. Por cada empleado se requiere: nombre, fecha nac., cargo (gerente,
* empleado), si es gerente se incluye nombre de la oficina a cargo y cantidad de
* empleados, si es empleado se incluye función que cumple (ej. maquinista, secretario,
* etc). Escribir un programa que recoja la información de la empresa y permita mostrar
* listados de todo el personal, sólo los gerentes o sólo los empleados. Utilizar typedef.
*
===========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

/*=====================================================================
                          PROGRAMA PRINCIPAL
=======================================================================*/

int main(int argc, char *argv[])
{
  int opcion, salir=-1;
  char c;
  while (salir != 0){
    opcion = menu(0, 4);
    switch (opcion) {
    case 0: salir=0; break;
    case 1: create(); break;
    case 2: delete(); break;
    case 3: update(); break;
    case 4: list(); break;
    default:  system("clear");
              printf("MAL\n");
              scanf("%c",&c);
              break;
    }
    //scanf("%c",&c);
  }
  return 0;
}
