//en esta parte se extraeran los tokens (caracteres)
// de todo el archivo fuente procesado en ese momento

#ifndef LEXER_H
#define LEXER_H
#include <stdio.h>
//#include "archivo.h"


//se empieza a enumerar desde 0
typedef enum {
    TOKEN_DESCONOCIDO,
    TOKEN_INSTRUCCION_CON_OPERANDO, // ->ADD<-, 5
    TOKEN_INSTRUCCION_SIN_OPERANDO, // OUTB
    TOKEN_OPERANDO, //ADD, ->5<-
    TOKEN_SEPARADOR, //ADD ->,<- 5
    TOKEN_NO_OPERATION, //NOT
    TOKEN_ETIQUETA //NO DISPONIBLE AUN
}TipoToken;
//etiquetas aun no estan disponibles



//------------------------
#define MAX_LEXEMA 255 //255 caracteres

//estructura para crear la lista de tokens
typedef struct Nodo{
    TipoToken tipo;
    char lexema[MAX_LEXEMA];
    int num_linea;
    struct Nodo *siguiente;
}ListaToken;



//--------------------------
//lexema es el token representado en caracter
typedef struct {
    TipoToken tipo;
    char lexema[MAX_LEXEMA];
    int num_linea;
}Token;



//guarda todo el codigo de el archivo fuente en un puntero char
char *leer_archivo_fuente(FILE *archivo_fuente);



//esta funcion escanea los caracteres y separa los tonek y crea una lista enlazada
//retorna la lista de tokens
ListaToken *extraer_token(char *codigo);


//funcion para insertar tokens en la lista enlazasa
ListaToken *insertar_token(ListaToken *, Token);

//funcion para mostrar los tokens, se usa como dpurador
void mostrar_tokens(ListaToken *lista);

//funcion para liberar la lista
void liberar_lista_tokens(ListaToken *lista);

TipoToken identificar_token(char *buffer);

//como saber si la cadena representa un numero entero
int es_num_entero(char *str);

int validar_numero(char *str);

#endif //LEXER_H
