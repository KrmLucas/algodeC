#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

void printTotal (t_empleado * emp){

    if (emp->activo == 1){
        if (emp->cargo == jefe){
            printf("%d\t %s\t %s\n", emp->legajo, emp->nombre, "Jerarquico");
        }else{
            printf("%d\t %s\t %s\n", emp->legajo, emp->nombre, "Operario");

        }
    }
}
