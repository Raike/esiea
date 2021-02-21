all: PROJET EXCUTION

PROJET: main.c graphe.h graphe.c
	gcc -c -Wall main.c -Werror
	gcc -c -Wall graphe.c -Werror
	gcc -o EXEC main.o graphe.o

EXCUTION: EXEC
	rm -rf *.o
	./EXEC