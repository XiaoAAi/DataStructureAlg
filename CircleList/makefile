main:main.o CircleList.o 
	gcc main.o CircleList.o -o main
	./main

main.o:main.c 
	gcc -c main.c -o main.o

CircleList.o:CircleList.c
	gcc -c CircleList.c -o CircleList.o

.PHONY:clean
clean:
	rm -rf *.o main 