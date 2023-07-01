#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ARRAY_MAX 2000

int array[ARRAY_MAX];    
int *array_sum;
int sum_size = 5;

int main ( void )
{
	
	int num;
	int start = 0;

	//---------------------------------------------------------------- INPUTS
	int len = 0;
	int rly;

	printf ( "Posloupnost:\n" );
	while ( (rly = scanf( "%d", &num )) != EOF)
	{	
		if (rly != 1)
		{
			printf ( "Nespravny vstup.\n" );
			return EXIT_FAILURE;
		} 
		array[len] = num;
		len ++;
		if ( len > ARRAY_MAX )
		{
			printf ( "Nespravny vstup.\n" );
			return EXIT_FAILURE;
		}
	}
	if ( len == 0  )
	{
		printf ( "Nespravny vstup.\n" );
		return EXIT_FAILURE;
	}
	
	//-------------------------------------------------------- SUMA DO ARRAY
	array_sum = (int *) malloc (sum_size * sizeof(int));

	int iter = 0;
	while (start < (len-1))
	{	
		int end = len;
		while (end - 1 > start)
		{
			int sum = 0;
			for (int i = start; i < end ; i++)
			{
				sum += array[i];
			}
			if ( iter > sum_size -1 )
			{
				sum_size *= 2;
				array_sum = (int *) realloc( array_sum, sum_size * sizeof(int) );
			}
			array_sum[iter] = sum;
			iter += 1;
			end --;
		}
		start ++;
	}

	//------------------------------------------------------- VYPOCET POCTU DVOJIC 

	int num_of_pairs = 0;
	for ( int begin = 0; begin < iter; begin++)
	{
		for ( int from = begin + 1; from < iter; from ++ )
		{
			if ( array_sum[begin] == array_sum[from] )
				num_of_pairs += 1;
		}
	}

	free (array_sum);
	printf ("Pocet dvojic: %d\n", num_of_pairs);
}

