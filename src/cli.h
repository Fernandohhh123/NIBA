#ifndef CLI_H
#define CLI_H

typedef struct {
    const char *archivo_fuente;
    const char *archivo_salida;
    char *Version;
}CLI_Arguments;

//funcion para procesar los argumentos de main
CLI_Arguments cliArgumentProcess(int argc, char *argumento[], CLI_Arguments cli_arg);

//aqui se inicalizaran los miembros de la variable de tipo CLI_Arguments
//
CLI_Arguments cli_inicialitation(CLI_Arguments cli_arg);

#endif
