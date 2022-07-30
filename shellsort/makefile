exec : main.o modulo.o
	gcc -o exec main.o modulo.o

main.o : main.c modulo.h
	gcc -c main.c
modulo.o : modulo.c modulo.h
	gcc -c modulo.c
clean :
	rm exec main.o modulo.o
run : 
	./exec > saida.txt