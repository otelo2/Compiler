#include <stdio.h> /* carga las rutinas de entrada y salida */
#include <ctype.h> /* carga las rutinas de prueba de caracteres */
#include <string.h>
#include <stdlib.h>

#define TAMBUFF 128 /* tamaño del buffer */
#define NINGUNO -1
#define FDC '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
//modification
#define CONI 600 //if
#define CONE 605 //then
#define LOOPI 610 //while
#define LOOPE 615 //do
#define PROCI 620 //begin
#define PROCE 625 //end
#define LES 650
#define LESE 651
#define BIG 652
#define BIGE 653
#define EQ 654
#define NEQ 655
#define FIN 59 //ctrl+Z

extern int valcomplex; /* valor del atributo del componente léxico */
extern int numlinea;

struct entrada { /* forma del elemento de entrada de la tabla de símbolos */
char *aplex;
int complex;
};
extern struct entrada tablasimb[]; /* tabla de símbolos */

//lexer.c
int analex(int caso);

//parser.c
void analsint();
void prop();
void exprbool();
void expr();
void termino();
void terminobool();
void factor();
void factorbool();
void parea(int t);
void prop_list();
void opc_prop();

//emitter.c
void emite (int t,int tval);

//symbol.c
int busca(char *s);
int inserta(char *s, int clex);

//init.c
void inic();

//error.c
void error(char *m);
