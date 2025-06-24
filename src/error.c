#include <stdio.h>
#include "error.h"


int code_error(int error_code, CLI_Arguments cli_arg){
    switch(error_code){

        //codigo 1 significa que el archivo fuente no fue encontrado
        //el archivo fuente se necesita para la lectura del codigo ensamblador
        case archivo_fuente_no_encontrado:
            printf("Archivo %s para lectura no encontrado.\n", cli_arg.archivo_fuente);
            printf("Codigo de error: %d\n", archivo_fuente_no_encontrado);
            return archivo_fuente_no_encontrado;
            break;

        case archivo_binario_no_creado:
            printf("Archivo binario no ha podido ser creado.\n");
            printf("Codigo de error: %d\n", archivo_binario_no_creado);
            return archivo_binario_no_creado;
            break;
    }

    return 0;
}
