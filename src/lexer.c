//en esta parte se extraeran los tokens (caracteres)
// de todo el archivo fuente procesado en ese momento

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include "info.h"
#include "lexer.h"


//funcion para guardar el contenido del archivo en una variable
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

	ListaToken *lista_token = NULL; //lista enlazada para encadenar tokens
	char buffer_token[MAX_LEXEMA]; //buffer para ir guardando los tokens extridos
	Token token_extraido = {TOKEN_DESCONOCIDO," "}; //estructura para facilitar la creacion de la lista enlazada

	//bucle para recorrer el codigo del archivo
	size_t i = 0;

	//imprimir el codigo completo
	//printf("%s\n", codigo);

	int numero_linea = 1; //recoge el numero de la linea de la instruccion

	while(codigo[i] != '\0'){
		//separar el codigo en tokens

		//---------texto---------------------------
		// >texto
		// -numeros
		// -separador
		// -comentarios
		// -extra
	    if(isalpha(codigo[i])){

			//printf("texto: ");

			int j = 0;
    		while(isalpha(codigo[i])){
				buffer_token[j] = codigo[i];
				j ++;
				i ++;
			}
			buffer_token[j] = '\0'; //terminamos el buffer

			//--agregamos el token a la lista enlazada--
			strcpy(token_extraido.lexema, buffer_token); //se copia el token extraido
			token_extraido.num_linea = numero_linea;


			token_extraido.tipo = identificar_token(buffer_token);
			lista_token = insertar_token(lista_token, token_extraido);  //se agrega a la lista


	    }//letras



		//---------numeros-----------------------------------
		// -texto
		// >numeros
		// -separador
		// -comentarios
		// -extra

		else if(isdigit(codigo[i])){
			//printf("digito: ");

			int j = 0;

				while(isdigit(codigo[i])){
					buffer_token[j] = codigo[i];
						j ++;
	                	i ++;
				}

			buffer_token[j] = '\0'; //terminamos el buffer
			strcpy(token_extraido.lexema, buffer_token);
			token_extraido.num_linea = numero_linea;

			token_extraido.tipo = identificar_token(buffer_token);

			//agregamos el token a la lista enlazada
			lista_token = insertar_token(lista_token, token_extraido);

		}//digitos



		//--------separador-------------------------------
		// -texto
		// -numeros
		// >separador
		// -comentarios
		// -extra

	        else if(codigo[i] == ','){
			//printf("separador: ");

			int j = 0;
	            while(codigo[i] == ','){
        	        buffer_token[j] = codigo[i];
	                j ++;
	                i ++;
	            }
	        buffer_token[j] = '\0'; //terminamos el buffer
			strcpy(token_extraido.lexema, buffer_token);
			token_extraido.num_linea = numero_linea;

			token_extraido.tipo = identificar_token(buffer_token);

			//agregamos el token a la lista enlazada
			lista_token = insertar_token(lista_token, token_extraido);



        	} // token separador



			//##### cosas a ignorar ################################

		//---------comentarios----------------------------
		// -texto
		// -numeros
		// -separador
		// >comentarios
		// -extra

	    else if(codigo[i] == ';'){
			//printf("comentarios\n");

        	while(codigo[i] != '\n'){
			    i ++;
				if(codigo[i] == '\0') break;
        	}

		} //comentarios



		//--------cosas extra, espacio, endl, tab...---------
		else if(codigo[i] == ' '){
			//printf("espacio\n");
		    i++;
		}

		else if(codigo[i] == '\n'){
			//printf("endl\n");
			i++;
			numero_linea++;
		}
		else {
			i++;
		}

	} // while(codigo != '\0')

	//mostrar_tokens(lista_token);

	return lista_token;

} //fun extraer token-------------------------------------


//funcion para insertar tokens en la lista enlazada
ListaToken *insertar_token(ListaToken *l_token, Token token){
	ListaToken *nuevo_token = (ListaToken*) malloc(sizeof(ListaToken)); //creamos un nuevo nodo
	ListaToken *aux;

	aux = NULL;

	strcpy(nuevo_token->lexema, token.lexema); //le asignamos el dato al nuevo nodo
	nuevo_token->num_linea = token.num_linea;
	nuevo_token->tipo = token.tipo;

	/**/

	nuevo_token->siguiente = NULL;

	if(l_token == NULL){
		l_token = nuevo_token;
	} else {
		aux = l_token;
		while (aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_token;
	}
	
	return l_token;
}


void mostrar_tokens(ListaToken *lista){
	ListaToken *actual = (ListaToken*) malloc(sizeof(ListaToken));
	actual = lista;

	int linea = actual->num_linea;

	while(actual != NULL){
		actual = actual->siguiente;
	}
}

void liberar_lista_tokens(ListaToken *lista){
	ListaToken *actual = lista;
	ListaToken *siguiente_nodo;

	while(actual != NULL){
		siguiente_nodo = actual->siguiente;
		free(actual);
		actual = siguiente_nodo;
	}
}

TipoToken identificar_token(char *buffer){

	for (int i = 0; buffer[i]; i++){
		buffer[i] = toupper(buffer[i]);
	}

	if(strcmp(buffer, "NOT") == 0){
		return TOKEN_NO_OPERATION;
	}
	else if(strcmp(buffer, "NAND") == 0){
		return TOKEN_INSTRUCCION_CON_OPERANDO;
	}
	else if(strcmp(buffer, "ADD") == 0){
		return TOKEN_INSTRUCCION_CON_OPERANDO;
	}
	else if(strcmp(buffer, "LDA") == 0){
		return TOKEN_INSTRUCCION_CON_OPERANDO;
	}
	else if(strcmp(buffer, "OUTA") == 0){
		return TOKEN_INSTRUCCION_SIN_OPERANDO;
	}
	else if(strcmp(buffer, "OUTB") == 0){
		return TOKEN_INSTRUCCION_SIN_OPERANDO;
	}
	else if(strcmp(buffer, "INA") == 0){
		return TOKEN_INSTRUCCION_SIN_OPERANDO;
	}
	else if(strcmp(buffer, "RD") == 0){
		return TOKEN_INSTRUCCION_SIN_OPERANDO;
	}
	else if(strcmp(buffer, "RA") == 0){
		return TOKEN_INSTRUCCION_SIN_OPERANDO;
	}
	else if(strcmp(buffer, "LDRA") == 0){
		return TOKEN_INSTRUCCION_SIN_OPERANDO;
	}
	else if(strcmp(buffer, "JPI") == 0){
		return TOKEN_INSTRUCCION_CON_OPERANDO;
	}
	else if(strcmp(buffer, "JPC") == 0){
		return TOKEN_INSTRUCCION_CON_OPERANDO;
	}
	else if(strcmp(buffer, "JPZ") == 0){
		return TOKEN_INSTRUCCION_CON_OPERANDO;
	}
	else if(strcmp(buffer, ",") == 0){
		return TOKEN_SEPARADOR;
	}
	else if(es_num_entero(buffer) == 0){
		if(validar_numero(buffer) == 0){
			return TOKEN_OPERANDO;
		} else {
			return TOKEN_DESCONOCIDO;
		}
		
	}
	else{
		return TOKEN_DESCONOCIDO;
	}
	
}

int es_num_entero(char *str){
	int i = 0;
	for(i; str[i]; i++){
		if(!isdigit(str[i])){
			return i;
		}
	}
	return i == 0;
}

int validar_numero(char *str){
	int numero = atoi(str);

	if((numero >= 0) && (numero <= 15)){
		return 0;
	} else {
		return 1;
	}
}
