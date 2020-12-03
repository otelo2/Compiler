#include "global.h"

//Tabla inicial de valores
struct entrada palsclave[] =
{
    "div", DIV,
    "mod", MOD,
    //modification
    "if", CONI,
    "then", CONE,
    "while", LOOPI,
    "do", LOOPE,
    "begin", PROCI,
    "end", PROCE,
    "<", LES,
    "<=", LESE,
    ">", BIG,
    ">=", BIGE,
    "==", EQ,
    "!=", NEQ,
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
