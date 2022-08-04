exec : main.o queue.o list.o
	g++ -o exec main.o queue.o list.o

main.o : main.cpp queue.hpp
	g++ -c main.cpp
list.o : list.cpp list.hpp
	g++ -c list.cpp
queue.o : queue.cpp queue.hpp
	g++ -c queue.cpp
clean :
	rm *.o
run : 
	make; ./exec > ../saida_fila.txt; make clean