nada por ahora

Ensamblador para un procesador de 4 bits de arquitectura personalizada

________________________________________________________________
COMANDOS PARA MANEJAR EL ENSAMBLDOR:

Para ejecutar el programa se debe de usar "./" para ejecutar el programa en linux.
ejemplo: ./ensamblador
debe de estar en la carpeta la cual esta ubicado el ejecutable o el binario ya compilado
tambien el archivo a ensamblar debe de estar en el mismo lugar que el ejecutable.
Todo es de manera local

si decide poner el programa en las variables de entorno para ejecutarlo en cualquier lado
no sera necesario agregar "./"

FORMATO PARA COMPILAR UN ARCHIVO FUENTE:

./ensamblador nombre_archivo_fuente -o archivo_binario.bin
    Ensambla el archivo con dogico fuente y crea un binario con "-o"
    
./ensamblador nombre_archivo_fuente
    En caso de no especificar el nombre del archivo de salida o archivo binario
    se creara con el nombre de "a.bin" por defecto

./ensamblador --version
    especifica la version del programa
    
./ensamblador 






DESCRIPCION DEL ENSAMBLDOR
______________________________________________________________________________________--
El Ensamblador al igual que el procesador es muy basico, los programas
se ejecutan directmante en el hardware, sin una capa como un sistema operativo,
BIOS, UEFI.

Esta primera version 0.0.1
es una version de prueba que traduce directamente las instrucciones a binario.
No hay etiquetas para saltos, para crear saltos debes de especificar
explicitamente la direccion de memoria.
para mas informacion acerca de los saltos consulte la documenacion del procesador

la linea en la que esta escrita cada instruccion esta estrechamente ligada a su posicion
de memoria final. Solo que hay que tomar en cuenta de que en la memoria se empieza
a contar desde 0 y en un archivo de texto o de codigo fuente se emiezan a
contar las lineas de codigo desde 1.
De tal forma que la formula seria "n-1"

donde n es la linea del codigo fuente. con esto obtenemos la direccion de la rom

vamos a hacer el ejemplo con un programa para sumar 2 numeros

codigo fuente:
1 LDA, 5
2 ADD, 2
3 OUTB

mismo programa pero en binario, visto en un formato hexadecimal para facilitar
la legilibilidad.

dir  0x00 0x01 0x02 0x3 0x4
0x00 35h  22h  50h  00h 00h

"dir" significa direccion, haciendo referencia a la direccion de memoria
los numeros con notacion hexadecimal "0x00" es la direccion dentro de la rom
mientras que los numero con la notacion "00h" son los datos almacenados.
no tiene diferencia alguna este formato, solo es para diferenciar
visualmente la direccion de los datos



