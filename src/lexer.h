#ifndef LEXER_H
#define LEXER_H
#include "archivo.h"

#define MAX_NEMONICO 8
#define MAX_LINEA 128
#define OPERANDO_DEFAULT 0

typedef struct nodo{
    char nemonico[MAX_NEMONICO];
    int operando;
    int linea_original; //ubicacion en el codigo fuente
    struct nodo *siguiente;
}Instrucciones;

typedef struct ins_aux{
    char nemonico[MAX_NEMONICO];
    int operando;
}Inst_aux;

Instrucciones *extraer_instrucciones(FILE *archivo_fuente);
void extraer_nemonico(Inst_aux **instrucciones_auxiliar, char *linea);
void extraer_operando(Inst_aux **instrucciones_auxiliar, char *linea);
void agregar_instruccion_a_lista();

#endif
