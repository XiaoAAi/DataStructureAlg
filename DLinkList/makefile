main:main.o DLinkList.o 
	gcc main.o DLinkList.o -o main
	./main

main.o:main.c
	gcc -c main.c -o main.o 

DLinkList.o:DLinkList.c
	gcc -c DLinkList.c -o DLinkList.o



.PHONY:clean
clean:
	rm -rf *.o main