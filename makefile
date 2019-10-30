all: main.o functions.o
	gcc -o linkedlist main.c functions.c

main.o: main.c functions.h
	gcc -c main.c

functions.o: functions.c functions.h
	gcc -c functions.c

run:
	./linkedlist

clean:
	rm *.o
