#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

void printOperario(t_empleado * emp){
    if (emp->activo == 1)
      printf("%d\t %s\t %s\t\n", emp->legajo, emp->nombre, emp->jerarquia.d1.categoria);
}
