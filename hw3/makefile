#
#Nathaniel Callahan
#hw3
#
#
#
#
eval: runner.o stack.o calculator.o
	gcc runner.o stack.o calculator.o -g -Wall -o eval

runner.o: runner.c calculator.h
	gcc runner.c -c -g -Wall

stack.o: stack.c stack.h
	gcc stack.c -c -g -Wall

calculator.o: calculator.c calculator.h stack.h
	gcc calculator.c -c -g -Wall

clean:
	rm *.o eval
