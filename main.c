#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

/** @mainpage
 *
 * Esta aplicación se hizo con el objetivo de ejercitar conceptos del
 * lenguaje ANSI C, como el manejo de punteros, archivos, memoria, entrada-salida,
 * archivos cabecera, etc.-
 *
 * @author Lucas Krmpotic
 * @date abril 2017
 * @version 1.0
 *
 */

int main(int argc, char *argv[])
{
  int opcion, salir=-1;
  while (salir != 0){
    opcion = menu(0, 5);
    switch (opcion) {
        case 0: salir=0; break;
        case 1: create(); break;
        case 2: delete(); break;
        case 3: update(); break;
        case 4: read(); break;
        case 5: list(); break;
        default: break;
    }
  }
  return 0;
}
