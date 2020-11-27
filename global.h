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
#define FIN 59 //ctrl+Z

extern int valcomplex; /* valor del atributo del componente léxico */
extern int numlinea;
struct entrada { /* forma del elemento de entrada de la tabla de símbolos */
char *aplex;
int complex;
};
extern struct entrada tablasimb[]; /* tabla de símbolos */

//lexer.c
int analex();

//parser.c
void analsint();
void expr();
void termino();
void factor();
void parea(int t);

//emitter.c
void emite (int t,int tval);

//symbol.c
int busca(char *s);
int inserta(char *s, int clex);

//init.c
void inic();

//error.c
void error(char *m);
