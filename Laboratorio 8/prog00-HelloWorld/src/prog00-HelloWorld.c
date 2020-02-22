/*
 ============================================================================
 Name        : prog00-HelloWorld.c
 Author      : Herminio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello PThreads World in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Global variable: */
int thread_count;
int factorial;

/* Thread function */
void* Factorial(void* param);

int main(int argc, char* argv[]) {
	long thread; /* Use long in case of a 64 − bit system */
	pthread_t* thread_handles;
	/* Get number of threads from command line */
	thread_count = strtol(argv[1], NULL, 10);
	thread_handles = malloc(thread_count * sizeof(pthread_t));
	for (thread = 0; thread < thread_count; thread++)
		pthread_create(&thread_handles[thread],
						NULL,
						Factorial,
						(void*) thread);
	printf("Hello from the main thread\n");
	for (thread = 0; thread < thread_count; thread++)
		pthread_join(thread_handles[thread],
						NULL);

	free(thread_handles);

	printf("Factorial = %d\n", factorial,thread_count);

}/* main */

void *Factorial(void *param)
 {
   int i, upper = atoi(param);
   factorial = 1;

   for (i = 1; i <= upper; i++)
	 factorial *= i;

   return NULL;
 }

