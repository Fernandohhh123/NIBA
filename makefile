
programa: src/*.c src/*.h
	gcc -Wall -Wextra src/*.c src/*.h -o /bin/programa

.PHONY : clean
clean :
	-rm bin/
