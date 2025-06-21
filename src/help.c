#include <stdio.h>
#include "help.h"

void show_help(){
    printf("\n");
    printf("Modo de uso.\n");
    printf("Ensamblador nombre_archivo.asm\n");
    printf("Ensamblador /ruta/a/archivo.asm\n");
    printf("Ensamblador archivo.asm -o nombre_de_archivo_de_salida\n");
    printf("\n");
    printf("EJEMPLO.\n");
    printf("Ensamblador main.asm -o programa\n");
}
