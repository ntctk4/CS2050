plane: lib.o runner.o
	gcc runner.o lib.o -o plane -g
lib.o: lib.c lib.h
	gcc -c lib.c -g

clean:
	rm *.o
