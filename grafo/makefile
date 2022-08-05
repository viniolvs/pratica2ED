exec : main.o graph.o list.o data.o
	gcc -o exec main.o graph.o list.o data.o

main.o : main.c graph.h list.h data.h
	gcc -c main.c
list.o : list.c list.h data.h
	gcc -c list.c
graph.o : graph.c graph.h data.h
	gcc -c graph.c
data.o : data.c data.h 
	gcc -c data.c
clean :
	rm *.o
run : 
	make; ./exec > ../saida_fila.txt; make clean