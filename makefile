all: main.o functions.o
	gcc -o musiclibrary main.c functions.c

main.o: main.c functions.h
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c functions.c

run:
	./musiclibrary

clean:
	rm *.o
	
debug: main.c functions.c functions.h
	gcc -g main.c functions.c

gdb: a.out
	gdb a.out