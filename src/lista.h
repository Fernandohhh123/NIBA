#ifndef LISTA_H
#define LISTA_H

<<<<<<< HEAD
#define MAX_NEMONICO 8

typedef struct nodo{
    char nemonico[MAX_NEMONICO];
    int operando;
    int linea_original; //ubicacion en el codigo fuente
    struct nodo *siguiente;
}Instrucciones;

typedef struct aux{
    char nemonico[MAX_NEMONICO];
    int operando;
}Inst_aux;

void liberar_lista(Instrucciones *lista);

void mostrar_lista(Instrucciones *lista);

#endif
=======
void liberar_lista();

#endif //LISTA_H
>>>>>>> version-funcional
