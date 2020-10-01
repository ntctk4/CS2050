/*Nathaniel Callahan
 *Hw2
 *
 *
 *
 *
 **/
#ifndef LIB_H_
#define LIB_H_

typedef struct node_
{
	char* fName;
	char* lName;
	char* origin;
	char* dest;
	int seatNumber;

	struct node_* next;
} Seat;

#define STRING_SIZE 20

Seat* create_seat(char* fName, char* lName, char* origin, char* dest, int num);
void enpty_seat(Seat** seat);
Seat* check_in(Seat* plane, Seat* seat);
Seat* land(Seat* plane, char* location);

#endif
