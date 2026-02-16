#ifndef CODE_GENERATE_H
#define CODE_GENERATE_H

#include <stdlib.h>
#include <stdint.h>
#include "lexer.h"

//estructura para guardar el codigo binario
typedef struct {
    uint8_t* data; //puntero al codigo
    size_t use_space; //espacio usado en el buffer
    size_t total_space; //espacio total del buffer
}Binary_code;

void buffer_init(Binary_code*);

void buffer_push(Binary_code*, uint8_t);

void buffer_free(Binary_code*);

void instruction_converter(ListaToken*,Binary_code*);

uint8_t converter_ico(char*); //ico = instrucción con operando

uint8_t converter_iso(char*); //iso = instrucción sin operando

uint8_t get_operand(char*);

uint8_t juntar_opcode_operando(uint8_t, uint8_t);

#endif
