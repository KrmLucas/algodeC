#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int empToStruct(t_empleado * emp, char * cad) {

    char *token = malloc(MAX_BUFF);
    char *campo = malloc(MAX_BUFF);
    char delim[] = "\t";
    char strJefe[] = "jefe";

    token = strtok(cad, delim);
    emp->legajo = atoi(token);
    //strncpy(emp->legajo, token, strlen(token));

    token = strtok(NULL, delim);
    strncpy(emp->nombre, token, strlen(token));

    token = strtok(NULL, delim);
    strncpy(campo, token, strlen(token));

    if (strcmp(campo, strJefe) == TRUE) {
        emp->cargo = jefe;

        token = strtok(NULL, delim);
        strncpy(emp->jerarquia.d2.nombreOficina, token, strlen(token));

        token = strtok(NULL, delim);
        strncpy(emp->jerarquia.d2.cantEmpleados, token, strlen(token));

    } else {
        emp->cargo = operario;

        token = strtok(NULL, delim);
        strncpy(emp->jerarquia.d1.categoria, token, strlen(token));

    }
    token = strtok(NULL, delim);
    emp->activo = atoi(token);
    //strncpy(emp->activo, token, strlen(token));
    return 0;
}
