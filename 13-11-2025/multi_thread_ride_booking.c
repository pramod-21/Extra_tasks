#include<stdio.h>
#include<pthread.h>  //for threads
#include<stdlib.h>

int available_seats = 5;
int booked_seats = 0;
int cancelled_seats = 0;

int ticket[5] = {0}; //0 for empty_seat, 1 for booked_seat

pthread_mutex_t mutex;  //Forlock and unlocking the critical section 

//function for ticket booking
void *ticket_book(void* arg){
	int seat_no = *((int *)arg);
	pthread_mutex_lock(&mutex);
	 int found = 0;
	for(int i=0; i<5; i++){
		if(ticket[i] == 0){
			ticket[i] = 1; //marking seat as booked
			booked_seats++;
			available_seats--;
			printf("Seat number %d booked successfully!\n", i+1);
			found = 1;
			break;
		}
	}
	if(!found){
		printf("No available seats to book.\n");
	}
	return NULL;
}

//function for ticket cancelling
void *ticket_cancel(){
	return NULL;
}

int main(){
	return 0;
}


