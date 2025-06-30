#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include "lista.h"

void liberar_lista(Instrucciones *lista){
    Instrucciones *actual;
    while(lista != NULL){
        actual = lista;
        lista = lista->siguiente;
        free(actual);
    }
}



void mostrar_lista(Instrucciones *lista){
    while(lista != NULL){
        printf("Instruccion: %s, ",lista->nemonico);
        printf("operando: %d\n", lista->operando);

        lista = lista->siguiente;
    }
=======
#include "lista.h"

void liberar_lista(){

>>>>>>> version-funcional
}
