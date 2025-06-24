
programa: src/*.c src/*.h
	gcc -Wall -Wextra src/*.c src/*.h -o programa

.PHONY : clean
clean :
	-rm programa
