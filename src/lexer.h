#ifndef LEXER_H
#define LEXER_H

#include "archivo.h"
#include "lista.h"

Instrucciones *extraer_instrucciones(FILE *archivo_fuente);

void extraer_nemonico(Inst_aux **instrucciones_auxiliar, char *linea);

void extraer_operando(Inst_aux **instrucciones_auxiliar, char *linea);

void agregar_instruccion_lista(Instrucciones **lista_instrucciones, Inst_aux **instrucciones_auxiliar);

#endif
