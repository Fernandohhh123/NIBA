#include <stdio.h>
#include <string.h>
#include "archivo.h"
#include "cli.h"
#include "error.h"



int main(int argc, char *argv[]){

    //aqui se guardaran los argumentos de cli
    //en este caso solo se guardara el nombre de los archivos
    //solo archivos de entrada y salida
    CLI_Arguments cli_arg = cli_inicialitation(cli_arg);


    //procesar los argumentos de cli
    cli_arg = cliArgumentProcess(argc, argv, cli_arg);

    //Buscar el archivo fuente
    //Se comprueba la existencia del archivo con el codigo fuente
    FILE *archivo_fuente_archivo = buscarArchivo(cli_arg);
    if(!archivo_fuente_archivo){
        return code_error(1, cli_arg);
        printf("Archivo \"%s\" no encontrado\n", cli_arg.archivo_fuente);
        return 1;
    }

    /*
    printf("Archivo fuente: %s\n", cli_arg.archivo_fuente);
    printf("Archivo de salida: %s\n", cli_arg.archivo_salida);
    */

    //si existe, leerlo
    //puede ser algo asi
    // archivo binario = generar_binario(archivo_fuente);

    FILE *archivo_binario = generar_archivo_binario(archivo_fuente_archivo);

    //generar el archivo binario

    fclose(archivo_fuente_archivo);
    fclose(archivo_binario);

    return 0;
}
