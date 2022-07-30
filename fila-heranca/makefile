exec : main.o modulo.o
	g++ -o exec main.o modulo.o

main.o : main.cpp modulo.hpp
	g++ -c main.cpp
modulo.o : modulo.cpp modulo.hpp
	g++ -c modulo.cpp
clean :
	rm main.o modulo.o
run : 
	make; ./exec > ../saida_fila.txt; make clean