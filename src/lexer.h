//en esta parte se extraeran los tokens (caracteres)
// de todo el archivo fuente procesado en ese momento

#ifndef LEXER_H
#define LEXER_H
#include "archivo.h"


//se empieza a enumerar desde 0
typedef enum{
    TOKEN_DESCONOCIDO,
    TOKEN_INSTRUCCION_CON_OPERANDO, // ->ADD<-, 5
    TOKEN_INSTRUCCION_SIN_OPERANDO, // OUTB
    TOKEN_OPERANDO, //ADD, ->5<-
    TOKEN_SEPARADOR, //ADD ->,<- 5
    TOKEN_ETIQUETA //NO DISPONIBLE AUN
}TipoToken;
//etiquetas aun no estan disponibles



//------------------------
//estructura para crear la lista de tokens
#define MAX_LEXEMA 8 //8 caracteres
typedef struct Nodo{
    TipoToken tipo;
    char lexema[MAX_LEXEMA];
    struct ListaToken *siguiente;
}ListaToken;



//--------------------------
//lexema es el token representado en caracter
typedef struct{
    TipoToken tipo;
    char lexema[MAX_LEXEMA];
}Token;



//guarda todo el codigo de el archivo fuente en un puntero char
char *leer_archivo_fuente(FILE *archivo_fuente);



//esta funcion escanea los caracteres y separa los tonek y crea una lista enlazada
//retorna la lista de tokens
ListaToken *extraer_token(char *codigo);



#endif //LEXER_H
