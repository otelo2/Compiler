#include "global.h"

char buflex[TAMBUFF];
int numlinea = 1;
int valcomplex = NINGUNO;

int analex(int caso) //Analizador léxico
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
            numlinea++;
        }
        else if (isdigit(t)!=0) //t es un dígito
        {
            //ungetc(t, stdin);
            //scanf("&d", &valcomplex);
            valcomplex=t-'0';
            //while(isdigit(t)!=0)
            //  valcomplex=(valcomplex*10)+(t-'0');
            //printf("valcomplex %d\n", valcomplex );
            return NUM;
        }
        else if (isalpha(t)!=0) //t es una letra
        {
            int p, b = 0;
            while (isalnum(t)!=0) //t es alfanumérico
            {
                //printf("%c\n", (char)t);
                buflex[b] = t;
                t = getchar();
                b++;
                if (b >= TAMBUFF)
                    error("error del compilador");
            }
            buflex[b] = FDC;
            //printf("%s\n", buflex);
            if (t != EOF) //EOF?
                ungetc(t, stdin);
            p = busca(buflex);
            if (p == 0)
                p = inserta(buflex, ID);
            valcomplex = p;
            //printf("valcomplex %d\n", tablasimb[valcomplex]);
            return tablasimb[p].complex;
        }
        else if (t == 59)
        {
            //printf("FIN\n");
            return FIN;
        }
        else if((((t<63)&&(t>59))||(t==33))&&(caso!=2))
        {
          //printf("caso %d\n", caso);
          int p, b = 0;
          while ((t<63)&&(t>59)||(t==33)) //t es alfanumérico
          {
              //printf("%d", t);
              buflex[b] = t;
              t = getchar();
              b++;
              if (b >= TAMBUFF)
                  error("error del compilador");
          }
          buflex[b] = FDC;
          //printf("%s\n", buflex);
          if (t != EOF) //EOF?
              ungetc(t, stdin);
          p = busca(buflex);
          if (p == 0)
              p = inserta(buflex, ID);
          valcomplex = p;
          //printf("valcomplex %d\n", tablasimb[valcomplex]);
          return tablasimb[p].complex;
          //switch(t)

        }
        else
        {
            //printf("NINGUNO");
            valcomplex = NINGUNO;
            return t;
        }
    }
}
