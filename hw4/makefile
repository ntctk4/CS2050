#
#Nathaniel Callahan
#ntctk4
#hw4
#lab E
#
#
hw4: runner.o stackQueue.o traversal.o
	gcc runner.o stackQueue.o traversal.o -g -Wall -o hw4
runner.o: runner.c traversal.h
	gcc runner.c -c -g -Wall
stackQueue.o: stackQueue.c stackQueue.h
	gcc stackQueue.c -c -g -Wall
traversal.o: traversal.c traversal.h stackQueue.h
	gcc traversal.c -c -g -Wall
clean:
	rm *.o eval
