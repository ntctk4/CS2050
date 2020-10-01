list: list.o runner.o
	gcc runner.o list.o -o list -g
list.o: list.c list.h
	gcc -c list.c -g 

clean:
	rm *.o
