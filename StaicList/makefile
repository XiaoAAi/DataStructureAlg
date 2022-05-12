main:main.o StaticList.o 
	gcc main.o StaticList.o -o main
	./main

main.o:main.c
	gcc -c main.c -o main.o 

StaticList.o:StaticList.c
	gcc -c StaticList.c -o StaticList.o


.PHONY:clean
clean:
	rm -rf *.o main