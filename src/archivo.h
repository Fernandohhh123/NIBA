#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include "cli.h"

FILE *buscarArchivo(CLI_Arguments cli_arg);

FILE *generar_archivo_binario(FILE *archivo);

FILE *crear_archivo_binario(FILE *archivo);

void leer_archivo_fuente(CLI_Arguments cli_arg);

#endif
