
programa: src/*.c src/*.h
	gcc src/*.c src/*.h -o niba

.PHONY : clean
clean :
	-rm niba
