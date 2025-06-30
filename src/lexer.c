#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"
#include "info.h"

Instrucciones *extraer_instrucciones(FILE *archivo_fuente){
    //se crea una lista elazada para guardar las instrucciones
    //2- se lee el archivo fuente
    //3- cada linea extraida es dividida entre instruccion y operando, en caso de tenrlo
    // "LDA, 5" -> "LDA" - "," - "espacio" - "5" - "\n" -> "LDA" "5"

    Instrucciones *lista_instrucciones;
    if(instrucciones_auxiliar == NULL){
        printf("No se pudo crear la lista de instrucciones en lexer\n");
        exit(1);
    }

    Inst_aux *instrucciones_auxiliar = malloc(sizeof(Inst_aux));
    if(instrucciones_auxiliar == NULL){
        printf("No se pudo crear la estructura auxiliar\n");
        exit(1);
    }

    instrucciones_auxiliar->operando = 0;

    char linea[MAX_LINEA];
    while(fgets(linea, sizeof(linea), archivo_fuente)){
        //printf("%s", linea);

        //extraemos a instruccion sin operando
        extraer_nemonico(&instrucciones_auxiliar, linea);

        //extraemos los numeros/operandos
        extraer_operando(&instrucciones_auxiliar, linea);

        //agregamos la estructura a la lista

    }


    free(instrucciones_auxiliar);
    return lista_instrucciones;
}


void extraer_nemonico(Inst_aux **instrucciones_auxiliar, char *linea){
    int i = 0;
    char instruccion[MAX_NEMONICO] = {0};
    while(linea[i] != '\0' && linea[i] != ',' && linea[i] != ' '){
        instruccion[i] = linea[i];
        i++;
    }

    instruccion[i] = '\0';

    strcpy((*instrucciones_auxiliar)->nemonico,instruccion);
}




void extraer_operando(Inst_aux **instrucciones_auxiliar, char *linea){

    int i = 0; //iterador que nos ayuda a procesar los caracteres de la linea del codigo
    char c = toupper(linea[i]);
    int operando_aux = -1;

    //recorremos la cadena hasta encontrar una coma o hasta el final
    while(linea[i] != '\0' && linea[i] != ',') i++;
    if(linea[i] == ','){
        i++; //saltamos la coma
        while(linea[i] == ' ') i++; //saltamos los espacios

        //se copia la cadena en mayusculas
        c = toupper(linea[i]);
        operando_aux = -1;


        if(c >= '0' && c <= '9'){
            operando_aux = c - '0';
        } else if(c >= 'A' && c <= 'F'){
            operando_aux = 10 + (c - 'A');
        }else{
            //si el operando es invalido se asignara 0 por defecto
            //printf("operador invalido.\n");
            (*instrucciones_auxiliar)->operando = OPERANDO_DEFAULT;
        }
        //printf("operando: %d\n", operando_aux);
        (*instrucciones_auxiliar)->operando = operando_aux;
    }
}
