/*
 ============================================================================
 Name        : FactorialOficial.c
 Author      : Sol
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate Pi in MPI
 ============================================================================
 */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>


 sem_t  semaphore;

const long thread_count ;

//long int n;



void * factorial(int n)
{
  int result;

  if(n==0 || n==1)
  {
    result = 1;
  }
  else
  {
    int i;
    int array[n];
    array[0]=1;
    array[1]=1;

    for(i=2; i<=n; i++)
    {
      array[i] = array[i-1] * i;
    }
    result = array[n];
  }



  sem_wait(&semaphore);
  printf("answer: %d\n", result);
  sem_post(&semaphore);

 pthread_exit(0);

}


int main(void) {


	  printf("Enter  n\n");

	  scanf("%ld",&thread_count);




	

	  pthread_t* thread_handles;

	      // create thread handles and initialize semaphore
	    sem_init(&semaphore, 0, 1);
	    thread_handles = malloc( thread_count * sizeof(pthread_t));

	    // create the pthreads on semaphore trapezoid function
	    long thread;
	    for( thread=0; thread < thread_count; thread++)
	      pthread_create( &thread_handles[thread], NULL,factorial,
	         thread);

	    // join all the thread handles
	    for( thread=0; thread < thread_count; thread++)
	      pthread_join( thread_handles[thread], NULL);

	    // free thread handles and semaphore
	    free(thread_handles);
	    sem_destroy(&semaphore);



	  return 0;



}
