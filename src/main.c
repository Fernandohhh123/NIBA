#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "archivo.h"
#include "cli.h"
#include "error.h"
#include "lexer.h"


int main(int argc, char *argv[]){

    //aqui se guardaran los argumentos de cli
    //en este caso solo se guardara el nombre de los archivos
    //solo archivos de entrada y salida
    CLI_Arguments cli_arg = cli_inicialitation(cli_arg);

    //procesar los argumentos de cli
    cli_arg = cliArgumentProcess(argc, argv, cli_arg);

    Archivos lista_archivos;
    //Buscar el archivo fuente
    //Se comprueba la existencia del archivo con el codigo fuente

    lista_archivos.archivo_fuente = buscarArchivo(cli_arg);
    if(!lista_archivos.archivo_fuente){
        return code_error(archivo_fuente_no_encontrado, cli_arg);
    }



    //extraemos el codigo fuente del archivo
    char *caracteres = leer_archivo_fuente(lista_archivos.archivo_fuente);
    fclose(lista_archivos.archivo_fuente);

    //separamos el codigo en tokens
    //creamos una lista para que recoja el principio de la lista enlazada
    ListaToken *listado_tokens = extraer_token(caracteres);
    mostrar_tokens(listado_tokens);


    //una vez leido y validado el codigo fuente
    //se crea un archivo binario vacio
    lista_archivos.archivo_binario = crear_archivo_binario(cli_arg);
    if(!lista_archivos.archivo_binario){
        return code_error(archivo_binario_no_creado, cli_arg);
    }

    //liberamos la memoria que reservamos para los tokens
    liberar_lista_tokens(listado_tokens);

    //fclose(lista_archivos.archivo_fuente);
    fclose(lista_archivos.archivo_binario);

    //mostrar_lista(lista_instrucciones);


    return 0;
}
