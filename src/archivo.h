#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <stdio.h>
#include "cli.h"
#include "archivo.h"

typedef struct {
    FILE *archivo_fuente;
    FILE *archivo_binario;
}Archivos;

FILE *buscarArchivo(CLI_Arguments cli_arg);

FILE *crear_archivo_binario(CLI_Arguments cli_arg);

FILE *generar_binario(Archivos lista_archivos);

#endif
