program: main.o funkcje.o magazyn.o
   gcc -o main main.o funkcje.o magazyn.o	

main.o: main.c funkcje.h
   gcc -c main.c	

funkcje.o: funkcje.c funkcje.h magazyn.h
   gcc -c funkcje.c	

magazyn.o: magazyn.c magazyn.h
   gcc -c magazyn.c	

clean:
    -rm -f main.o
    -rm -f funkcje.o
    -rm -f magazyn.o
    -rm -f main
