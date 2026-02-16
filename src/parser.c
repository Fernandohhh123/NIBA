#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"

#define PARSER_ERROR 1

//punto de entrada del parser
void parser(ListaToken *lista){
    analizador_sinatico(lista);  
}

//esto solo analiza la estructura de los tokens
void analizador_sinatico(ListaToken *lista){
    ListaToken *cabeza = (ListaToken*) malloc(sizeof(ListaToken));
    cabeza = lista;

    int num_linea = 0;

    while(es_nodo_vacio(cabeza) == 0){
        switch(cabeza->tipo){
            case TOKEN_INSTRUCCION_CON_OPERANDO:
                
                if(cabeza->num_linea == num_linea){
                    printf("Error: %d\n", cabeza->num_linea);
                    exit(1);
                }
    
                num_linea = cabeza->num_linea;
                
                if(process_ico(cabeza) != 0){
                    printf("Error linea: %d\n", cabeza->num_linea);
                    exit(1);
                }
    
            break;
            
            case TOKEN_INSTRUCCION_SIN_OPERANDO:
                if(cabeza->num_linea == num_linea){
                    printf("Error: %d\n", cabeza->num_linea);
                    exit(1);
                }
                
            break;

        }//switch
        
        cabeza = cabeza->siguiente;
        
    }//while

    //free(cabeza);
    
}//analizador sintatico

/*esto revisa si el nodo actual esta vacio
si no esta vacio retorna 0*/
int es_nodo_vacio(ListaToken *cabeza){
    if(cabeza == NULL){
        return 1;
    }
    return 0;
}


int es_sig_nodo_vacio(ListaToken *cabeza){
    if(cabeza->siguiente == NULL){
        return 1;
    }
    return 0;
}


/*esta funcion analizara la sintaxis de una Instruccion Con Operando (ICO)*/
int process_ico(ListaToken *lista){
    int status = 0;
    
    ListaToken *actual = (ListaToken*) malloc(sizeof(ListaToken));
    
    actual = lista;
    actual = actual->siguiente;
    if(es_nodo_vacio(actual) != 0){
        printf("Error: %d\n", actual->num_linea);
        exit(1);
    }

    if(actual->tipo != TOKEN_SEPARADOR){
        status = PARSER_ERROR;
    }
    actual = actual->siguiente;
    if(es_nodo_vacio(actual) != 0){
        printf("Error: %d\n", actual->num_linea);
        exit(1);
    }

    if(actual->tipo != TOKEN_OPERANDO){
        status = PARSER_ERROR;
    }
    
    //free(actual);
    
    return status;
}
