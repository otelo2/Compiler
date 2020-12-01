#include "global.h"

int preanalisis;
//temporal variables
int temp, tempval, te;
//id first
int caso;
//infinite pseudo registers
int regnum;

void analsint() //Analiza sintácticamente y traduce la lista de la expresión
{
    preanalisis = analex();
    temp = preanalisis;
    while (preanalisis != FIN)
    {
        caso=0;
        regnum=1;
        prop();
        parea(';');
    }

}

void expr()
{
    //printf("expr\t");
    int t;
    if(caso==1)
    {
      te=preanalisis; //t=+
      preanalisis=temp;
      temp=valcomplex;
      valcomplex=tempval;
      //printf("CASO1\n");
    }
    termino();
    if(caso==1)
    {
      caso=0;
    }
    while(1)
        switch (preanalisis)
        {
        case '+':
        case '-':
            //printf("Expr %d\t%d\n", t, preanalisis);
            t = preanalisis;
            //Revisa que sea el signo correcto
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
  //  printf("termino\t");
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
            //revisa que sea el símbolo correcto
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
  //  printf("factor\t%d\n", preanalisis);
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
        //printf("ID\n");
        emite(ID, valcomplex);
        if(caso!=1)
          parea(ID);
        else
        {
            preanalisis=te;
            valcomplex=temp;
            caso=0;
            //printf("CASO1\n");
        }
        break;
    default:
        error("1. error de sintaxis");
    }
}

void parea(t)
    int t;
{
  //printf("match\n");
  //printf("A %d\t%d\n", t, preanalisis);
    if (preanalisis == t)
    {
        preanalisis = analex();
        //printf("A %d\t%d\n", t, preanalisis);
    }
    else
    {
        if(t==':')
        {
          caso=1;
        }
        else
          error("2. error de sintaxis");
    }
}

//modification
void prop()
{
  int t;
    switch(preanalisis)
    {
      case ID:
        //temp tiene el ID
        temp=preanalisis;
        tempval=valcomplex;
        preanalisis=analex();
        parea(':');
        //preanalisis=+
        if(caso==1)
          expr();
        else
        {
          parea('=');
          //exprbool();
          //falta imprimir la instrucción
          emite(t, NINGUNO);
          preanalisis=analex();
        }
        break;
      case CONI:
        preanalisis=analex();
        //exprbool();
        parea(CONE);
        prop();
      //  preanalisis=analex();
        break;
      case LOOPI:
        preanalisis=analex();
        //exprbool();
        parea(LOOPE);
        prop();
        break;
      case PROCI:
        //opc_prop();
        preanalisis=analex();
        parea(PROCE);
        break;
      default:
        expr();
    }
}

void exprbool()
{
  int t;
  terminobool();
  while(1)
      switch (preanalisis)
      {
      case BIG:
      case BIGE:
      case LES:
      case LESE:
      case EQ:
      case NEQ:
          //printf("Expr %d\t%d\n", t, preanalisis);
          t = preanalisis;
          //Revisa que sea el signo correcto
          parea (preanalisis);
          terminobool();
          emite(t, NINGUNO);
          continue;
      default:
          return;
      }
}

void terminobool()
{
    int t;
    factorbool();
    while (1)
        switch (preanalisis)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case DIV:
        case MOD:
            t = preanalisis;
            //revisa que sea el símbolo correcto
            parea(preanalisis);
            factorbool();
            emite(t, NINGUNO);
            continue;
        default:
            return;
        }
}

void factorbool()
{
  //  printf("factor\t%d\n", preanalisis);
    switch (preanalisis)
    {
    case NUM:
      //printf("NUM\n");
        emite(NUM, valcomplex);
        parea(NUM);
        break;
    case ID:
        //printf("ID\n");
        emite(ID, valcomplex);
        parea(ID);
        break;
    default:
        error("3. error de sintaxis");
    }
    regnum++;
}

void opc_prop()
{
  prop_list();
}

//acepta ; como parte de la expresion
void prop_list()
{
  prop_list();

}
