all: main.o functions.o library.o
	gcc -o musiclibrary main.c functions.c library.c

main.o: main.c functions.h library.h
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c functions.c

library.o: library.c functions.h library.h
	gcc -c library.c
	
run:
	./musiclibrary

clean:
	rm *.o
	
debug: main.c functions.c functions.h
	gcc -g main.c functions.c

gdb: a.out
	gdb a.out