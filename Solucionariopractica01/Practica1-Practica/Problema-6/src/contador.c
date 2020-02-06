/*
 ============================================================================
 Name        : contador.c
 Author      : Sol
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate Pi in MPI
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <sys/time.h>


#define DIM 10

MPI_Status status;


void leer(double B[DIM],double *y)
{
	for(int i=0;i<DIM;i++)
	{
		B[i]=rand()%100;
		printf("%.0f\t",B[i]);
	}

	printf("Ingrese el elemento a buscar\n");
	scanf("%d",y);


}


int main(int argc, char **argv) {

	double A[DIM],Aloc[DIM];
	double x;
	int  cont ,cont_loc;
	int p ,rank;


	 MPI_Init(&argc, &argv);
	 MPI_Comm_size(MPI_COMM_WORLD,&p);
	 MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank==0)
		leer(A,&x);


	MPI_Bcast(&x,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
	MPI_Scatter(A,DIM/p*DIM,MPI_DOUBLE,Aloc,DIM/p*DIM,MPI_DOUBLE,0,MPI_COMM_WORLD);

     cont_loc=0;

	for(int i=0;i<DIM/p;i++)

			if(Aloc[i]==x)
				cont_loc ++;



	MPI_Reduce(&cont_loc,&cont,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

	if(rank==0)
		printf("%d ocurrencias\n",cont);


	MPI_Finalize();
	return 0;

}



