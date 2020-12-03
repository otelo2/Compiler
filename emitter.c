#include "global.h"

void emite(t, tval) //Genera la salida de la consola dependiendo de las entradas
//Usa los valores declarados en global.h
    int t, tval;
{
    switch (t)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        printf("%c\n", t);
        break;
    case DIV:
        printf("DIV\n");
        break;
    case MOD:
        printf("MOD\n");
        break;
    case NUM:
        printf("%d\n", tval);
        break;
    case ID:
        printf("%s\n", tablasimb[tval].aplex);
        break;
    //modification
    case MET:
        printf("mete %d\n", tval);
        break;
    case CONI:
        printf("sifalsovea endif\n");
        break;
    case CONE:
        printf("endif\n");
        break;
    case TEST:
        printf("prueba\n");
        break;
    case TEST+1:
        printf("vea prueba\n");
        break;
    case LOOPI:
        printf("sifalsovea endloop\n");
        break;
    case LOOPE:
        printf("endloop\n");
        break;
    case PROCI:
        printf("process:\n");
        break;
    case PROCE:
        printf("end\n");
        break;
    case LES:
        printf("LessThan\n");
        break;
    case LESE:
        printf("LessEqualThan\n");
        break;
    case BIG:
        printf("BiggThan\n");
        break;
    case BIGE:
        printf("BiggEqualThan\n");
        break;
    case EQ:
        printf("EqualTo\n");
        break;
    case NEQ:
        printf("DifferentFrom\n");
        break;
    case VALI:
        printf("valori %s\n", tablasimb[tval].aplex);
        break;
    case METD:
        printf("meted %s\n", tablasimb[tval].aplex);
        break;
    case VALD:
        printf("valord %s\n", tablasimb[tval].aplex);
        break;
    case ASI:
      printf(":=\n");
    break;
    default:
        printf("complex %d, valcomplex %d\n", t, tval);
    }
}
