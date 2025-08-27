//en esta parte se extraeran los tokens (caracteres)
// de todo el archivo fuente procesado en ese momento

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "info.h"
#include "lexer.h"

char *leer_archivo_fuente(FILE *archivo_fuente){

    //mueve el cursor de lectura al final del archivo para
    // saber su tamaño
    fseek(archivo_fuente, 0, SEEK_END);

    //extrae el tamaño total del archivo
    long longitud_archivo = ftell(archivo_fuente);
    rewind(archivo_fuente);

    //reservamos el espacio y un byte mas para indicar el final
    char *buffer = malloc(longitud_archivo + 1);

    if(!buffer){
        fprintf(stderr,"No se pudo asignar memoria para el buffer de lexer\n");
        exit(1);
    }

    //guardando los caracteres
    size_t leidos = fread(buffer, 1,longitud_archivo, archivo_fuente);
    buffer[leidos] = '\0';

    return buffer;
}


ListaToken *extraer_token(char *codigo){
    printf("%s", codigo);

    ListaToken *lista_token = NULL;

    char *buffer_token[MAX_LEXEMA];

    int i = 0;
    while(codigo[i] != '\0'){
        //separar palabras
        if(isalpha(codigo[i])){
            int j = 0;
            while(isalpha(codigo[i])){
                buffer_token[j] = &codigo[i];
                j ++;
                i ++;
            }
            buffer_token[j] = '\0'; //terminamos el buffer

            //agregamos el token a la lista enlazada
	    
	    printf("%s");

        } // letras
        else if(isdigit(codigo[i])){
            int j = 0;
            while(isalpha(codigo[i])){
                buffer_token[j] = &codigo[i];
                j ++;
                i ++;
            }
            buffer_token[j] = '\0'; //terminamos el buffer

            //agregamos el token a la lista enlazada

        }//digitos
        else if(codigo[i] == ','){
            int j = 0;
            while(isalpha(codigo[i])){
                buffer_token[j] = &codigo[i];
                j ++;
                i ++;
            }
            buffer_token[j] = '\0'; //terminamos el buffer

            //agregamos el token a la lista enlazada


        } // token separador
        else if(codigo[i] == ';'){
            while(codigo[i] != '\n'){
                i ++;
            }
        } //comentarios

    } // while(codigo != '\0')

} //fun extraer token







