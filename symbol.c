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
    for (p = 1; p <= ultent; p++)
    {
        /*debugging
        printf("%s \t %s\n", s, tablasimb[p].aplex);
        printf("len %d\t%d\n", strlen(tablasimb[p].aplex), strlen(s));
        */
        //si el valor actual de la tabla y s son iguales
        if (strcmp(tablasimb[p].aplex, s) == 0)
        {
            //devuelves la posicion de la tabla
            return p;
        }
    }
    //si no encontro s regresa 0
    return 0;
}

int inserta(s, clex) //Devuelve la posición del elemento de entrada de s
char s[];
int clex;
{
    int lon,i;
    lon = strlen(s); //strlen evalúa la longitud de s
    //revisas que haya espacio disponible en la tabla
    if (ultent + 1 >= MAXSIMB)
    {
        error("tabla de símbolos llena");
    }
    //revisas que haya espacio disponible en la matriz de lexemas
    if (ultcar + lon + 1 >= MAXLEX)
    {
        error("matriz de lexemas llena");
    }
    //si hay espacio, insertas el nuevo valor a ambas
    ultent++;
    tablasimb[ultent].complex = clex;
    tablasimb[ultent].aplex = &lexemas[ultcar+1];
    ultcar = ultcar + lon + 1;
    strcpy(tablasimb[ultent].aplex, s);
    //regresas el nuevo valor de ultent
    return ultent;
}
