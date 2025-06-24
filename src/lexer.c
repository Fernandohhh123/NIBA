#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "info.h"

#define MAX_LINEA 128

Instrucciones extraer_instrucciones(FILE *archivo_fuente){
    //se crea una lista elazada para guardar las instrucciones
    //2- se lee el archivo fuente
    //3- cada linea extraida es dividida entre instruccion y operando, en caso de tenrlo
    // "LDA, 5" -> "LDA" - "," - "espacio" - "5" - "\n" -> "LDA" "5"


    Instrucciones lista_instrucciones;

    char linea[128];
    while(fgets(linea, sizeof(linea), archivo_fuente)){
        printf("%s", linea);
    }

    return lista_instrucciones;
}
