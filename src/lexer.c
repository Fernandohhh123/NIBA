#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lexer.h"
#include "info.h"

#define MAX_LINEA 128

Instrucciones extraer_instrucciones(FILE *archivo_fuente){
    //se crea una lista elazada para guardar las instrucciones
    //2- se lee el archivo fuente
    //3- cada linea extraida es dividida entre instruccion y operando, en caso de tenrlo
    // "LDA, 5" -> "LDA" - "," - "espacio" - "5" - "\n" -> "LDA" "5"


    Instrucciones lista_instrucciones;

    //extraemos linea por linea y la procesamos
    char linea[128];
    while(fgets(linea, sizeof(linea), archivo_fuente)){
        //printf("%s", linea);

        int i = 0;
        char instruccion[15] = {0};
        while(linea[i] != '\0' && linea[i] != ',' && linea[i] != ' '){
            instruccion[i] = linea[i];
            i++;
        }

        instruccion[i] = '\0';
        printf("instruccion: %s\n", instruccion);

        //extraemos los numeros/operandos
        for(int i = 0; linea[i] != '\0'; i++){
            char c = linea[i];
            if(isdigit(c)){
                printf("operando: %c\n", c);
                lista_instrucciones.operando = c - '0';
            }
        }
    }

    return lista_instrucciones;
}
