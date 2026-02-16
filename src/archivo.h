#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include "cli.h"
#include "code_generate.h"
#include "lexer.h"

typedef struct {
    FILE *archivo_fuente;
    FILE *archivo_binario;
}Archivos;

FILE *buscarArchivo(CLI_Arguments cli_arg);

FILE *crear_archivo_binario(CLI_Arguments cli_arg);

void escribir_binario(FILE*, Binary_code*);

#endif
