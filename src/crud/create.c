/*=====================================================================
                          MOSTRAR EMPLEADO
=======================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h"

int create (){
  char c;
  FILE * fp;

  system("clear");
  if ((fp = fopen("data/datos.csv", "r"))!= NULL){

    int c; 
    while ((c = getc(fp)) != EOF) {
      putc(c, stdout);
    }

  } else {
    printf("Archivo no existe\n");
    scanf("%c", &c);
    return 1;
  }

  fclose(fp);
  scanf("%c", &c);
  return 0;
}