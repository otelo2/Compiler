#include "global.h"

int preanalisis;

void analsint() //Analiza sintácticamente y traduce la lista de la expresión
{
    preanalisis = analex();
    //printf("analsint %i\n", preanalisis);
    while (preanalisis != FIN)
    {
        expr();
        parea(';');
    }

}

void expr()
{
    //printf("expr\t");
    int t;
    termino();
    while(1)
        switch (preanalisis)
        {
        case '+':
        case '-':
            t = preanalisis;
            parea (preanalisis);
            termino();
            emite(t, NINGUNO);
            continue;
        default:
            return;
        }
}

void termino()
{
    //printf("termino\t");
    int t;
    factor();
    while (1)
        switch (preanalisis)
        {
        case '*':
        case '/':
        case DIV:
        case MOD:
            t = preanalisis;
            parea(preanalisis);
            factor();
            emite(t, NINGUNO);
            continue;
        default:
            return;
        }
}

void factor()
{
    //printf("factor\t%d\n", preanalisis);
    switch (preanalisis)
    {
    case '(':
        parea('(');
        expr();
        parea(')');
        break;
    case NUM:
      //printf("NUM\n");
        emite(NUM, valcomplex);
        parea(NUM);
        break;
    case ID:
        emite(ID, valcomplex);
        parea(ID);
        break;
    default:
        error("1. error de sintaxis");
    }
}

void parea(t)
    int t;
{
  //printf("match\n");

    //printf("%i\t%i\n", t, preanalisis);
    if (preanalisis == t)
    {
        preanalisis = analex();
    }
    else
    {
        error("2. error de sintaxis");
    }

}
