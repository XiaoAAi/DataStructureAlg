main:main.o SeqList.o 
	gcc main.o SeqList.o -o main
	./main

main.o:main.c includes.h SeqList.h
	gcc -c main.c -o main.o 

SeqList.o:SeqList.c SeqList.h includes.h
	gcc -c SeqList.c -o SeqList.o



.PHONY:clean
clean:
	rm -rf *.o main