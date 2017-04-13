#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../includes.h"

int clean (char * cad){
    
    for (int i = 0; i<strlen(cad); i++){
        if (cad[i] < 65 && cad[i] != 32)
            return 1;
        if (cad[i] > 90 && cad[i]< 97)
            return 1;
        if (cad[i] > 122 && cad[i] < 160 && cad[i] != 130)
            return 1;
        if (cad[i] > 165)
            return 1;
    }
    return 0;
}

int cleanString(char * msge, char * cad) {

    do {
        printf("%s", msge);
        fflush( stdin );
        scanf(" %[^\n]", cad);
        getchar();
    } while (clean(cad) == 1);

    return 0;
}