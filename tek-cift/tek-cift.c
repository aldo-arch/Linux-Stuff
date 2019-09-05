#include <pthread.h>
#include <stdio.h>

const int N = 5, M = 5;
int matrica[ 5 ][ 5 ] = {{1,2,3}, {4,5,6}, {7,8,9},{10,11,12},{13,14,15}};
int shuma;
int numra_tek;
int numra_cift;


//Prototipet e funksioneve
void *shumaElementeve( void *para );
void *elementeTek( void *para );
void *elementeCift( void *para );

int main()
{
	///Deklarimi i thread 1
	pthread_t id_1;
	pthread_attr_t attr_1;

	///Deklarimi i thread 2
	pthread_t id_2;
	pthread_attr_t attr_2;

	//Deklarimi i thread 3
	pthread_t id_3;
	pthread_attr_t attr_3;


	///Thread 1
	pthread_attr_init( &attr_1 );
	pthread_create( &id_1, &attr_1, shumaElementeve, NULL );
	pthread_join( id_1, NULL );

	//Thread 2
	pthread_attr_init( &attr_2 );
	pthread_create( &id_2, &attr_2, elementeTek, NULL );
	pthread_join( id_2, NULL );


	///Thread 3
	pthread_attr_init( &attr_3 );
	pthread_create( &id_3, &attr_3, elementeCift, NULL );
	pthread_join( id_3, NULL );

	printf( "Shuma = %d \n", shuma );
	printf( "Numri i elementeve tek = %d \n", numra_tek );
	printf( "Numri i elementeve cift = %d \n\n", numra_cift );
}



void *shumaElementeve( void *para )
{
	shuma = 0;

	int i,j;

	for( i = 0; i < N; i++ )
	{
		for( j = 0; j < M; j++ )
		{
			shuma += matrica[ i ][ j ];
		}
	}

	pthread_exit( 0 );
}



void *elementeTek( void *para )
{
	numra_tek = 0;
	int i, j;

	for( i = 0; i < N; i++ )
	{
		for( j = 0; j < M; j++ )
		{
			if( matrica[ i ][ j ] % 2 == 1 )
			{
				numra_tek += 1;
			}
		}
	}

	pthread_exit( 0 );
}


void *elementeCift( void *para )
{
	numra_cift = 0;
	int i, j;

	for( i = 0; i < N; i++ )
	{
		for( j = 0; j < M; j++ )
		{
			if( matrica[ i ][ j ] % 2 == 0 )
			{
				numra_cift += 1;
			}
		}
	}

	pthread_exit( 0 );
}