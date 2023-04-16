ftc: ftc.o list_of_files.o util.o ctc.o name.o size.o date.o
	gcc ftc.o name.o list_of_files.o ctc.o date.o size.o util.o -o ftc 

ftc.o: src/ftc.c
	gcc -c -Wall src/ftc.c 

date.o: src/date.c
	gcc -c -Wall src/date.c

size.o: src/size.c
	gcc -c -Wall src/size.c

ctc.o: src/ctc.c
	gcc -c -Wall src/ctc.c

name.o: src/name.c
	gcc -c -Wall src/name.c

list_of_files.o: src/list_of_files.c
	gcc -c -Wall src/list_of_files.c

util.o : src/util.c
	gcc -c -Wall src/util.c
