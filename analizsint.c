#include "global.h"

int preanálisis;

análsint() //Analiza sintácticamente y traduce la lista de la expresión
{
    preanálisis = análex();
    while (preanálisis != FIN)
    {
        expr();
        parea(';');
    }
    
}

expr()
{
    int t;
    término();
    while(1)
        switch (preanálisis)
        {
        case '+': 
        case '-':
            t = preanálisis;
            parea (preanálisis);
            término();
            emite(t, NINGUNO);
            continue;
        default:
            return;
        }
}

termino()
{
    int t;
    factor();
    while (1)
        switch (preanálisis)
        {
        case '*':
        case '/':
        case DIV:
        case MOD:
            t = preanálisis;
            parea(preanálisis);
            factor();
            emite(t, NINGUNO);
            continue;
        default:
            return;
        }
}

factor()
{
    switch (preanálisis)
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

parea(t)
    int t;
{
    if (preanálisis == t)
    {
        preanálisis = análex();
    }
    else
    {
        error("error de sintaxis");
    }
    
}