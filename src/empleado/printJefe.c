#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"


void printJefe(t_empleado * emp){

  char nombOficina[MAX_BUFF];
  char cantEmpleados[MAX_BUFF];


  if (emp->activo == 1) {
      strcpy(nombOficina, emp->jerarquia.d2.nombreOficina);
      strcpy(cantEmpleados, emp->jerarquia.d2.cantEmpleados);
      printf("%d\t %s\t\n", emp->legajo, emp->nombre);
  }
}
