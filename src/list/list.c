#include <stdio.h>
#include <stdlib.h>
#include "../../includes.h" 

int list(){

    static int opcion, salir = -1;

    do {
        opcion = menuList();
        switch (opcion) {
        case 0: salir=0; break;
        case 1: listJefes(); break;
        case 2: listOperarios(); break;
        case 3: listTotal(); break; 
        default:  system("clear");
                printf("MAL\n");
                getchar();
                break;
        }
    } while (salir != 0);

    return 0;
}