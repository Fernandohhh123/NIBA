
programa: src/*.c src/*.h
	gcc src/*.c src/*.h -o programa

.PHONY : clean
clean :
	-rm programa
