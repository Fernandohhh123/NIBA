#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cli.h"
#include "archivo.h"
#include "help.h"
#include "info.h"



CLI_Arguments cliArgumentProcess(int argc, char *argumento[], CLI_Arguments cli_arg){

    //comenzamos a reconocer y procesar cada argumento de la cli
    for(int i = 1; i < argc; i++){
        //printf("%s %d\n", argumento[i],i);

        //proceamos el nombre que tengra el archivo de salida
        if(strcmp("-o", argumento[i]) == 0){
            //printf("Archivo de salida %s\n", argumento[i+1]);
            cli_arg.archivo_salida = argumento[i+1];

            /*estamos en "-o" saltamos el argumento que da nombre
            al archivo de salida sumandole 2 al iterador*/
            i = i + 2;
        }

        else if(strcmp("--version", argumento[i]) == 0){
            printf("Version: %s\n", cli_arg.Version);
            exit(0);

        }

        else if(strcmp("--help", argumento[i]) == 0){
            show_help();
            exit(0);
        }
        else{
            //printf("Archivo fuente %s\n", argumento[i]);

            cli_arg.archivo_fuente = argumento[i];

            //printf("Archivo fuente %s\n", cli_arg.archivo_fuente);
        }
    }

    //se terminan de procesar los argumentos pendeintes, como mandar los nombres de
    //los archivos, buscar y leer el archivo fuente y generar el binario
    //printf("Archivo fuente: %s\n", cli_arg.archivo_fuente);
    //printf("Archivo de salida: %s\n", cli_arg.archivo_salida);

    return cli_arg;

}

CLI_Arguments cli_inicialitation(CLI_Arguments cli_arg){
    cli_arg.archivo_salida = archivo_salida_default;
    cli_arg.Version = version;

    return cli_arg;
}
