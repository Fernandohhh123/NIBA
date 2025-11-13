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

	while(codigo[i] != '\0'){
	        //separar el codigo en tokens



		//imprimir el ciclo
		//printf("ciclo: %d\n", i);


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

		strcpy(token_extraido.lexema, buffer_token);

		//agregamos el token a la lista enlazada

		printf("%s\n", token_extraido.lexema);

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
			printf("%s\n", token_extraido.lexema);

			//agregamos el token a la lista enlazada

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

			//agregamos el token a la lista enlazada

			printf("%s\n", &buffer_token);


        	} // token separador



		//---------comentarios----------------------------
		// -texto
		// -numeros
		// -separador
		// >comentarios
		// -extra

	        else if(codigo[i] == ';'){
			printf("comentarios\n");

        		while(codigo[i] != '\n'){
		                i ++;
				if(codigo[i] == '\0') break;
	        	}

		} //comentarios



		//--------cosas extra, espacio, endl, tab...---------
		else if(codigo[i] == ' '){
			printf("espacio\n");
		    	i++;
		}

		else if(codigo[i] == '\n'){
			printf("endl\n");
			i++;
		}


	} // while(codigo != '\0')

} //fun extraer token

