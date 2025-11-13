#include<stdio.h>
#include<pthread.h>  //for threads
#include<stdlib.h>

int available_seats = 5;
int booked_seats = 0;
int cancelled_seats = 0;

int ticket[5] = {0}; //0 for empty_seat, 1 for booked_seat

pthread_mutex_t mutex;  //Forlock and unlocking the critical section 

//function for ticket booking
void *ticket_book(){
	return NULL;
}

//function for ticket cancelling
void ticket_cancel(){
	return NULL;
}

int main(){
	return 0;
}


