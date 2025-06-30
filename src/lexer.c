#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "lexer.h"
#include "info.h"
#include "lista.h"

<<<<<<< HEAD
#define MAX_LINEA 128


=======
>>>>>>> version-funcional
Instrucciones *extraer_instrucciones(FILE *archivo_fuente){
    //se crea una lista elazada para guardar las instrucciones
    //2- se lee el archivo fuente
    //3- cada linea extraida es dividida entre instruccion y operando, en caso de tenrlo
    // "LDA, 5" -> "LDA" - "," - "espacio" - "5" - "\n" -> "LDA" "5"

<<<<<<< HEAD
    //creamos una lista para guardar las instrucciones
    Instrucciones *lista_instrucciones = malloc(sizeof(Instrucciones));


    //estructura auxiliar
    Inst_aux *instrucciones_auxiliar = malloc(sizeof(Inst_aux));

    //extraemos linea por linea y la procesamos
    char linea[MAX_LINEA]; //aqio se guarda la linea comleta
=======
    Instrucciones *lista_instrucciones = malloc(sizeof(Instrucciones));
    if(lista_instrucciones == NULL){
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
>>>>>>> version-funcional
    while(fgets(linea, sizeof(linea), archivo_fuente)){
        //printf("%s", linea);

        //extraemos a instruccion sin operando
        extraer_nemonico(&instrucciones_auxiliar, linea);

        //extraemos los numeros/operandos
        extraer_operando(&instrucciones_auxiliar, linea);

<<<<<<< HEAD
        //agregamos la estructura a la lista
        agregar_instruccion_lista(&lista_instrucciones, &instrucciones_auxiliar);

    }

    //printf("Instruccion: %s\n", lista_instrucciones->nemonico);
    //printf("Operando: %d\n", lista_instrucciones->operando);

    //retornamos el primer elmento de la lista
=======
        printf("entrando a agregar_instruccion_lista\n");
        //agregamos la estructura a la lista
        agregar_instruccion_lista(&lista_instrucciones, &instrucciones_auxiliar);
    }


    free(instrucciones_auxiliar);
>>>>>>> version-funcional
    return lista_instrucciones;
}


<<<<<<< HEAD



void extraer_nemonico(Inst_aux **instrucciones_auxiliar, char *linea){
    //extraemos a instruccion sin operando
    int i = 0;

    //variable para guardar el nemonico extraido
    char nemonico[MAX_NEMONICO] = {0};
    while(linea[i] != '\0' && linea[i] != ',' && linea[i] != ' '){
        nemonico[i] = linea[i];
        i++;
    }

    //terminamos correctamente la instruccion
    nemonico[i] = '\0';
    //printf("Instruccion: %s", nemonico);

    //copiamos la cadena en la estructura
    strcpy((*instrucciones_auxiliar)->nemonico, nemonico);
}


//Constante simbolica para asignar a un operando invalido
// o a una instruccion sin operando
//Aun que en el codigo no necesite operando, en la rom habra espacio para un operando
// sin importar la instruccion, pero el procesador ignorará ese operando
#define OPERANDO_DEFAULT 0
=======
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



>>>>>>> version-funcional

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

<<<<<<< HEAD

void agregar_instruccion_lista(Instrucciones **lista_instrucciones, Inst_aux **instrucciones_auxiliar){
    Instrucciones *nuevo_nodo = malloc(sizeof(Instrucciones));
    if(!nuevo_nodo) return;

    nuevo_nodo = NULL;
=======
void agregar_instruccion_lista(Instrucciones **lista_instrucciones, Inst_aux **instrucciones_auxiliar){

    Instrucciones *nuevo_nodo = malloc(sizeof(Instrucciones));
    if(!nuevo_nodo) return;

    nuevo_nodo->siguiente = NULL;
>>>>>>> version-funcional

    strcpy(nuevo_nodo->nemonico, (*instrucciones_auxiliar)->nemonico);
    nuevo_nodo->operando = (*instrucciones_auxiliar)->operando;

    nuevo_nodo->siguiente = NULL;

    if(*lista_instrucciones == NULL){
        *lista_instrucciones = nuevo_nodo;
    }else{
        Instrucciones *actual = *lista_instrucciones;

        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
}
