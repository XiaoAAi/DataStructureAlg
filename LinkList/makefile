main:main.o LinkList.o 
	gcc main.o LinkList.o -o main
	./main

main.o:main.c
	gcc -c main.c -o main.o 

LinkList.o:LinkList.c
	gcc -c LinkList.c -o LinkList.o



.PHONY:clean
clean:
	rm -rf *.o main