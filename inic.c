#include "global.h"

struct entrada palsclave[] =
{
    "div", DIV,
    "mod", MOD,
    0, 0
};

void inic() //Carga las palabras clave en la tabla de símbolos
{
    struct entrada *p;
    for (p = palsclave; p->complex; p++)
    {
          inserta(p->aplex, p->complex);
    }
}
