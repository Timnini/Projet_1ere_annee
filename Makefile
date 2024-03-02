prog: main.o deroulement.o introduction.o ecriture.o afficher.o plateau.o verif.o

	gcc -o prog main.o deroulement.o introduction.o ecriture.o afficher.o plateau.o verif.o

main.o : main.c afficher.h deroulement.h ecriture.h plateau.h verif.h
	gcc -c main.c -o main.o

deroulement.o : deroulement.c deroulement.h ecriture.h plateau.h verif.h

	gcc -c deroulement.c -o deroulement.o


ecriture.o : ecriture.c ecriture.h

	gcc -c ecriture.c -o ecriture.o
	
introduction.o : introduction.c introduction.h verif.h afficher.h
	gcc -c introduction.c -o introduction.o


afficher.o : afficher.c afficher.h

	gcc -c afficher.c 

plateau.o : plateau.c plateau.h verif.h

	gcc -c plateau.c -o plateau.o

verif.o : verif.c verif.h

	gcc -c verif.c -o verif.o
