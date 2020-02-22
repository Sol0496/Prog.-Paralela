/*
 ============================================================================
 Name        : FactorialThreads.c
 Author      : Sol
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Global variable: */


const long thread_count;
int n;                          // size of fibonacci sequence.
int *fact;                    // arry holds the value of each fibonacci term.
int i;                          // counter for the threads.



pthread_mutex_t mutex;
/* Thread function */
void* Factorial(void *arg);



int main(int argc, char *argv[]) {
	int thread; /* Use long in case of a 64 − bit system */
	pthread_t* thread_handles;
	int n;

	/* Get number of threads from command line */

	 printf("Ingrese valor de n\n");
	 scanf("%d",&n);

	// n = atoi(argv[1]);
	 fact = (int *)malloc(n * sizeof(int));


	// pthread_mutex_init(&mutex, NULL);
	thread_handles = malloc(thread_count * sizeof(pthread_t));
	for (thread = 0; thread < thread_count; thread++)
		pthread_create(&thread_handles[thread],
		NULL,Factorial,(void*) thread);


	for (thread = 0; thread < thread_count; thread++)
		pthread_join(thread_handles[thread],
		NULL);


	 printf("The Fibonacci sequence.:");
	    int k;

	    for (k = 0; k < n; k++)
	    {
	        printf("%d,", fact[k]);
	    }                           // End of printing fibseq.
	    return 0;




}/* main */


void * Factorial(void *arg) {

	if (i == 0)
	    {
	        fact[i] = 0;
	        pthread_exit(0);
	    }                           // first fib term

	    if (i == 1)
	    {
	        fact[i] = 1;
	        pthread_exit(0);
	    }                           // seconed fib term
	    else
	    {
	        fact[0] = 0;
	        fact[1] = 1;

	        int p, pp;

	      //  p = (i - 1);
	      //  pp = (i - 2);
	      //  fibp = fact[p];
	        // printf("fibseq[%d]%d\n",p,fibp);
	      //  fibpp = fact[pp];
	        // printf("fibseq[%d]%d\n",pp,fibpp);
	        fact[i] = fact[i - 1]*fact[i - 2];
	        // printf("fibseq[%d]%d,\n",i,fibseq[i]);

	        pthread_exit(0);
	    }
}

