all : standart

main.o : main.c
	cc -DFLAG -c main.c -o main.o -lreadline -w

string.o : string.c
	cc -DFLAG -c string.c -o string.o -w

own : main.o string.o
	cc -DFLAG -o ownMain main.c string.c -w

standart : main.c
	cc -o stdMain main.c -lreadline

clean : 
	rm -f main.o string.o ownMain stdMain

