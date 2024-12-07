all : standart_lib

own_lib : main.o string.o
	cc -DFLAG -o mainMyString main.c string.c -w

standart_lib : main.c
	cc -o mainStdString main.c -lreadline

main.o : main.c
	cc -DFLAG -c main.c -o main.o -lreadline -w

string.o : string.c
	cc -DFLAG -c string.c -o string.o -w

clean : 
	rm -f main.o string.o mainMyString mainStdString

