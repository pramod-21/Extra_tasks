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
void *ticket_cancel(void* arg){
	int seat_no = *((int *)arg);
	pthread_mutex_lock(&mutex);
	int found = 0;
	for(int i=0; i<5; i++){
		if(ticket[i] == 1){
			ticket[i] = 0; //marking seat as available
			cancelled_seats++;
			available_seats++;
			printf("Seat number %d cancelled successfully!\n", i+1);
			found = 1;
			break;
		}
	}
	if(!found){
		printf("No booked seats to cancel.\n");
	}
	return NULL;
}

int main(){
	pthread_t threads[5];
	pthread_mutex_init(&mutex, NULL);
	int choice;
	for(int i=0; i<5; i++){
		printf("Enter 1 to book a ticket or 2 to cancel a ticket: ");
		scanf("%d", &choice);
		if(choice == 1){
			pthread_create(&threads[i], NULL, ticket_book, NULL);
		}
		else if(choice == 2){
			pthread_create(&threads[i], NULL, ticket_cancel, NULL);
		}
		else{
			printf("Invalid choice, enter 1 to book or 2 to cancel.\n");
			i--; //to repeat the iteration for valid input
			continue;
		}
		pthread_join(threads[i], NULL);
	}
	printf("Status of the seats:\n");
	printf("Total booked seats: %d\n", booked_seats);
	printf("Total cancelled seats: %d\n", cancelled_seats);
	printf("Available seats: %d\n", available_seats);
	pthread_mutex_destroy(&mutex);
	return 0;
}


