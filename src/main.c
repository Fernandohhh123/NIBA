#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "archivo.h"
#include "cli.h"
#include "error.h"
#include "lexer.h"
#include "parser.h"
#include "code_generate.h"


int main(int argc, char *argv[]){

    CLI_Arguments cli_arg = cli_inicialitation(cli_arg);

    cli_arg = cliArgumentProcess(argc, argv, cli_arg);

    Archivos lista_archivos;

    lista_archivos.archivo_fuente = buscarArchivo(cli_arg);
    if(!lista_archivos.archivo_fuente){
        return code_error(archivo_fuente_no_encontrado, cli_arg);
    }

    char *caracteres = leer_archivo_fuente(lista_archivos.archivo_fuente);
    fclose(lista_archivos.archivo_fuente);

    ListaToken *listado_tokens = extraer_token(caracteres);
    //mostrar_tokens(listado_tokens);

    //parser
    parser(listado_tokens);

    //traduccion a binario, listo para ejecutar
    Binary_code b_code;
    buffer_init(&b_code);
    instruction_converter(listado_tokens, &b_code);

    lista_archivos.archivo_binario = crear_archivo_binario(cli_arg);
    if(!lista_archivos.archivo_binario){
        return code_error(archivo_binario_no_creado, cli_arg);
    }

    // for(size_t i = 0; i < b_code.use_space; i++){
    //     printf("%02X,", b_code.data[i]);
    // }

    escribir_binario(lista_archivos.archivo_binario, &b_code);

    liberar_lista_tokens(listado_tokens);
    buffer_free(&b_code);
    
    //fclose(lista_archivos.archivo_fuente);
    fclose(lista_archivos.archivo_binario);

    return 0;
}
