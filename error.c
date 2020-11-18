#include "global.h"

error(m) //Genera todos los mensajes de error
    char *m;
{
    fprintf(stderr, "línea %d: %s\n", numlínea, m);
    exit(1); //Teminación sin éxito
}