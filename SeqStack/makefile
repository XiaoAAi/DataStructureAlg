main:main.o SeqStack.o  SeqList.o 
	gcc main.o  SeqList.o SeqStack.o -o main
	./main

main.o:main.c
	gcc -c main.c -o main.o 

SeqList.o:SeqList.c
	gcc -c SeqList.c -o SeqList.o


SeqStack.o:SeqStack.c
	gcc -c SeqStack.c -o SeqStack.o



.PHONY:clean
clean:
	rm -rf *.o main