#ifndef PARSER_H
#define PARSER_H

#include "parser.h"
#include "lexer.h"

/*funcion principal para el parser,
solo se procesara la sintaxis, quizas en un futuro se
agregue el analizador semantico*/
void parser(ListaToken*);

/*funcion para diagnosticar el orden de tokens*/
void analizador_sinatico(ListaToken*);

/*esto revisa si el nodo actual esta vacio
si no esta vacio retorna 0*/
int es_nodo_vacio(ListaToken*);

/*Funcion para analizar las instrucciones con operando*/
int process_ico(ListaToken*);

#endif
