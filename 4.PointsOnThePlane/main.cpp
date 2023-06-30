#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main ( void ){

	double a1, a2, b1, b2, c1, c2, vekt1, vekt2, c_rovnica;
	
	// Vstupy
	printf( "Bod A:\n" );
	if (scanf( "%lf %lf", &a1, &a2) != 2)
	{
		printf( "Nespravny vstup.\n" ); 
		return EXIT_FAILURE; 
	}
		
	printf( "Bod B:\n" );
	if (scanf( "%lf %lf", &b1, &b2) != 2)
	{
		printf( "Nespravny vstup.\n" );
		return EXIT_FAILURE; 
	}
		
	printf( "Bod C:\n" );
	if (scanf( "%lf %lf", &c1, &c2) != 2)
	{
		printf( "Nespravny vstup.\n" ); 
		return EXIT_FAILURE; 
	}
		
	// Splyvavost bodov	
	if ( (a1 == b1 && a2 == b2) || (a1 == c1 && a2 == c2) || (b1 == c1 && b2 == c2))
	{
		printf( "Nektere body splyvaji.\n" );
		return EXIT_SUCCESS;
	}
			
	// Algoritmus pre priamku	
	vekt1 = b1-a1;          //smerove vektory
	vekt2 = b2-a2;
	
	float temp;             //normalovy vektor
	temp = vekt1;
	vekt1 = (-1)*vekt2;
	vekt2 = temp;

	c_rovnica = (vekt1 * a1) + (vekt2 * a2);
	
	if (c_rovnica == 0 && vekt1*c1 + vekt2 *c2 == 0)
	{
		printf( "Body lezi na jedne primce.\n" );
		
		if (a1 == b1 && a1 == c1)
		{
			if ((a2 > b2 && a2 < c2) || (a2 > c2 && a2 < b2))
			{
				printf( "Prostredni je bod A.\n" );
				return EXIT_SUCCESS;
			}
			
			else if ( (b2 > a2 && b2 < c2) || (b2 > c2 && b2 < a2) )
			{
				printf( "Prostredni je bod B.\n" );
				return EXIT_SUCCESS;
			}
			else 
			{
					printf( "Prostredni je bod C.\n" );
					return EXIT_SUCCESS;
			}
		}		
		else
		{
			if ( ((a1 > b1 && a1 < c1) || (a1 > c1 && a1 < b1)) )
			{
				printf( "Prostredni je bod A.\n" );
				return EXIT_SUCCESS;
			}
			else if ( (b1 > a1 && b1 < c1) || (b1 > c1 && b1 < a1) )
			{
				printf( "Prostredni je bod B.\n" );
				return EXIT_SUCCESS;
			}
			else
			{
				printf( "Prostredni je bod C.\n" );
				return EXIT_SUCCESS;
			}
		}
	}
	
	if ( fabs(vekt1*c1 + vekt2*c2 - c_rovnica) < (100000000000 * DBL_EPSILON * fabs (c_rovnica)) )
	{
		printf( "Body lezi na jedne primce.\n" );
		
		if (a1 == b1 && a1 == c1)
		{
			if ((a2 > b2 && a2 < c2) || (a2 > c2 && a2 < b2))
			{
				printf( "Prostredni je bod A.\n" );
				return EXIT_SUCCESS;
			}
			
			else if ( (b2 > a2 && b2 < c2) || (b2 > c2 && b2 < a2) )
			{
				printf( "Prostredni je bod B.\n" );
				return EXIT_SUCCESS;
			}
			else
			{
				printf( "Prostredni je bod C.\n" );
				return EXIT_SUCCESS;
			}
		}		
		else
		{
			if ( ((a1 > b1 && a1 < c1) || (a1 > c1 && a1 < b1)) )
			{
				printf( "Prostredni je bod A.\n" );
				return EXIT_SUCCESS;
			}
			else if ( (b1 > a1 && b1 < c1) || (b1 > c1 && b1 < a1) )
			{
				printf( "Prostredni je bod B.\n" );
				return EXIT_SUCCESS;
			}
			else
			{
				printf( "Prostredni je bod C.\n" );
				return EXIT_SUCCESS;
			}		
		}
	}		
	else
	{
		printf( "Body nelezi na jedne primce.\n" );
		return EXIT_SUCCESS;
	}	
}

