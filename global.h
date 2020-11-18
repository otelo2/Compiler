#include <stdio.h> //Carga las rutinas de entrada y salida
#include <ctype.h> //Carga las rutinas de prueba de caracteres

#define TAMBUFF 128 //Tamaño del buffer
#define NINGUNO -1
#define FDC '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 159
#define FIN 260

int valcomplex; //Valor del atributo del componente léxico

int numlínea;

struct entrada //Forma del elemento de entrada de la tabla de símbolos
{
    char *aplex;
    int complex;
};

struct entrada tablasimb[]; //Tabla de símbolos