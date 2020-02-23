/*
 ============================================================================
 Name        : OpenMP_Sum_elementos.c
 Author      : Sol
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]) {

	int A[20];

	int i;
	int sum=0;
	for (i = 0; i < 20; i++) {

		A[i]=rand()%100;
	}

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int nt = omp_get_num_threads();
		int size = (int) 20 / nt;
		int ini = id * size;
		int fin = ini + size - 1;
		int j;

		for (j = ini; j <= fin; j++) {
			sum = sum + A[j];
		}
	}

		printf("Suma de los elementos : %d\n",sum);


	return 0;
}

