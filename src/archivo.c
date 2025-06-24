#include <stdlib.h>
#include <stdio.h>
#include "archivo.h"
#include "cli.h"
#include "info.h"



FILE *buscarArchivo(CLI_Arguments cli_arg){
    FILE *archivo = fopen(cli_arg.archivo_fuente, "r");
    if(!archivo){
        return NULL;
    }else{
        return archivo;
    }
}

FILE *crear_archivo_binario(CLI_Arguments cli_arg){
    FILE *archivo_binario = fopen(cli_arg.archivo_salida, open_type_binary_write);
    if(!archivo_binario){
        return NULL;
    } else{
        return archivo_binario;
    }
}
