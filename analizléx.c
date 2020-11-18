#include "global.h"

char buflex[TAMBUFF];
int numlínea = 1;
int valcomplex = NINGUNO;

int análex() //Analizador léxico
{
    int t;
    while (1)
    {
        t = getchar();
        if (t == ' ' || t == '\t')
        {
            ; //Elimina espacios en blanco
        }
        else if (t == '\n')
        {
            numlínea++;
        }
        else if (isdigit(t)) //t es un dígito
        {
            ungetc(t, stdin);
            scanf("&d", &valcomplex);
            return NUM;
        }
        else if (isalpha(t)) //t es una letra
        {
            int p, b = 0;
            while (isalnum(t)) //t es alfanumérico
            {
                buflex[b] = t;
                t = getchar();
                b++;
                if (b >= TAMBUFF)
                    error("error del compilador");
            }
            buflex[b] = FDC;
            if (t != EOF)
                ungetc(t, stdin);
            p = busca(buflex);
            if (p == 0)
                p = inserta(buflex, ID);
            valcomplex = p;
            return tablasimb[p].complex;
        }
        else if (t == EOF)
        {
            return FIN;
        }
        else
        {
            valcomplex = NINGUNO;
            return t;
        }
    }
}