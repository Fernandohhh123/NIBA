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



FILE *generar_archivo_binario(FILE *archivo_fuente){
     FILE *archivo_binario = crear_archivo_binario(archivo);

     return archivo_binario;
}



FILE *crear_archivo_binario(FILE *archivo){
    //creamos un archivo binario
    FILE *archivo_binario = fopen(archivo, open_type_binary_write);

    if(!archivo_binario){
        printf("Algo ha fallado al crear el archivo binario\n");
        exit(2);
    }
    return archivo_binario;
}

void leer_archivo_fuente(CLI_Arguments cli_arg){

}
