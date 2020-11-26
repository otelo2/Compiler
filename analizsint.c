#include "global.h"

int preanalisis;

void analsint() //Analiza sintácticamente y traduce la lista de la expresión
{
    preanalisis = analex();
    while (preanalisis != FIN)
    {
        expr();
        parea(';');
    }

}

void expr()
{
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
    switch (preanalisis)
    {
    case '(':
        parea('(');
        expr();
        parea(')');
        break;
    case NUM:
        emite(NUM, valcomplex);
        parea(NUM);
        break;
    case ID:
        emite(ID, valcomplex);
        parea(ID);
        break;
    default:
        error("error de sintaxis");
    }
}

void parea(t)
    int t;
{
    if (preanalisis == t)
    {
        preanalisis = analex();
    }
    else
    {
        error("error de sintaxis");
    }

}
