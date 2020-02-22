/*
 ============================================================================
 Name        : ThreadFibonacci.c
 Author      : Sol
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int thread_count;
int m;                          // size of fibonacci sequence.
//int *fibseq;                    // arry holds the value of each fibonacci term.
int i; // counter for the threads.

double GLOBAL_MUTEX_SUM = 0;

pthread_mutex_t mutex;

int fibonacci(int x);
void *Fibonacci(void *arg);
//void Usage(char* prog_name);

//void Print_vector(char* title, double y[], double m);

int main(int argc, char *argv[]) {

	long thread;
	pthread_t* thread_handles;

	//if (argc != 2)
	//Usage(argv[0]);

	thread_count = strtol(argv[1],NULL,m);
	thread_handles = malloc(thread_count * sizeof(pthread_t));

	printf("Enter m \n");
	scanf("%d", &m);
//	fibseq  = malloc(m *sizeof(int));
	//pthread_t *threads = (pthread_t *) malloc(m * sizeof(pthread_t));
	//pthread_attr_t attr;        // set of thread attribute

	//pthread_attr_init(&attr);

	for (thread = 0; thread <thread_count; thread++) {
		pthread_create(&thread_handles[thread], NULL,Fibonacci, NULL);
	}                           // End of creating threads.



	for (thread = 0; thread < thread_count; thread++) {
		pthread_join(thread_handles[thread], NULL);
	}

	free(thread_handles);
    pthread_mutex_destroy(&mutex);



	// End of wating the threads to exit.

	// printing fibseq.
	printf("MUTEX\n");

	printf("With n = %d\n ", m);
	    printf("Fibonacci es :%f\n",
	       GLOBAL_MUTEX_SUM);

	// End of printing fibseq.


	return 0;
}
// End of main.

//void Usage(char* prog_name) {
	//fprintf(stderr, "usage: %s <thread_count>\n", prog_name);
	//exit(0);
//}

void *Fibonacci(void *rank) {

	long my_rank = (long) rank;
	long long i;
	int local_m = m / thread_count;
	int my_first_row = my_rank * local_m;
	int my_last_row = (my_rank + 1) * local_m - 1;
	int  local_sum=0;


	for (i = my_first_row; i <= my_last_row; i++) {

	 	   local_sum += fibonacci(i);
	}		    // End of else

	 pthread_mutex_lock(&mutex);
	  GLOBAL_MUTEX_SUM += local_sum;
	  pthread_mutex_unlock(&mutex);


	return NULL;
}                               // End of run.

int fibonacci (int x)
{
    if (x <= 1) {
        return 1;
    }
    return fibonacci(x-1) + fibonacci(x-2);
}

