minesweeper: minesweeper.o runner.o 
	gcc runner.c minesweeper.o -o minesweeper
minesweeper.o: minesweeper.c minesweeper.h
	gcc -c minesweeper.c

clean:
	rm *.o
