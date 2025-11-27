lda, 5 ;cargamos 5 en el acumulador
add, 2 ;sumamos 2
outb ;lo mostramos en la salida b
ra ;guardamos el valor en el registro a
not ;delay
ldra ;el valor del registro a lo cargamos al acumulador
add 7 ;sumamos 7
outa ;mostramos el valor en el puerto a
