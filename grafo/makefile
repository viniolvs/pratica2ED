exec : main.o modulo.o
	gcc -o exec main.o modulo.o

main.o : main.c modulo.h
	gcc -c main.c
modulo.o : modulo.c modulo.h
	gcc -c modulo.c
clean :
	rm main.o modulo.o
run : 
	make; ./exec > ../saida_grafo.txt; make clean