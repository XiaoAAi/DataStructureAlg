main:main.o LinkList.o LinkStack.o
	gcc main.o LinkStack.o LinkList.o -o main
	./main

main.o:main.c
	gcc -c main.c -o main.o 

LinkStack.o:LinkStack.c
	gcc -c LinkStack.c -o LinkStack.o	

LinkList.o:LinkList.c
	gcc -c LinkList.c -o LinkList.o



.PHONY:clean
clean:
	rm -rf *.o main