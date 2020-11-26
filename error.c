#include "global.h"

void error(m) //Genera todos los mensajes de error
    char *m;
{
    fprintf(stderr, "línea %d: %s\n", numlinea, m);
    exit(1); //Teminación sin éxito
}
