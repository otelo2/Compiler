#include "global.h"
#define MAXLEX 999 //Tamaño de la matriz de lexemas
#define MAXSIMB 100 //Tamaño de tablasimb

char lexemas[MAXLEX];
int ultcar = -1; //Ultima posición usada en los lexemas
struct entrada tablasimb[MAXSIMB];
int ultent = 0; //Ultima posición usada en tablasimb

int busca(s) //Devuelve la posición del elemento de entrada de s
    char s[];
{
    int p;
    for (p = ultent; p > 0; p--)
    {
        if (srtcmp(tablasimb[p].aplex, s) == 0)
        {
            return p;
        }
        return 0;
    }
    
}

int inserta(s, clex) //Devuelve la posición del elemento de entrada de s
    char s[];
    int clex;
{
    int lon;
    lon = strlen(s); //strlen evalúa la longitud de s
    if (ultent + 1 >= MAXSIMB)
    {
        error("tabla de símbolos llena");
    }
    if (ultcar + lon + 1 >= MAXLEX)
    {
        error("matriz de lexemas llena");
    }
    ultent++;
    tablasimb[ultent].complex = clex;
    tablasimb[ultent].aplex = &lexemas[ultcar+1];
    ultcar = ultcar + lon + 1;
    strcpy(tablasimb[ultent].aplex, s);
    return ultent;
}
