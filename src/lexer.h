#ifndef LEXER_H
#define LEXER_H
#include "archivo.h"

typedef struct nodo{
    const char instruccion;
    int operando;
    int linea_original; //ubicacion en el codigo fuente
    int *siguiente;
}Instrucciones;


Instrucciones extraer_instruccion(Instrucciones lista_instrucciones, Archivos lista_archivos);


#endif
