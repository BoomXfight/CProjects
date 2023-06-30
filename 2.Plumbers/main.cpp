#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ( void )
{
	int rm, x1, y1, z1, x2, y2, z2, dp = 0, odves1 = 0, odves2 = 0;
	double dh = 0;
	
	// zadanie a osetrenie rozmeru mistnosti
	
	printf( "Rozmer mistnosti:\n" );
	if (scanf( "%d", &rm ) !=1 
			|| rm < 40 ) 
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}
	
	// zadanie a osetrenie 1. bodu
	
	printf( "Bod #1:\n" );
	if (scanf( "%d %d %d", &x1, &y1, &z1 ) !=3  // basic osetrenia
			|| x1 > rm
			|| y1 > rm
			|| z1 > rm 
			|| z1 == 0
			|| z1 == rm
			)
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}	
	if ( x1 != 0 && y1 !=0  && x1 != rm && y1 != rm )  // ostrenie ci je 1. bod v stene
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}
	if ( (x1 == 0 || x1 == rm) && ((y1 < 20 || y1 > (rm -20)) || (z1 < 20 || z1 > (rm -20))) )  // osetrenie 20 pre y a z
	{ 
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}
	if ( (y1 == 0 || y1 == rm) && ((x1 < 20 || x1 > (rm -20)) || (z1 < 20 || z1 > (rm -20))) )  // osetrenie 20 pre x a z
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}
	
	// zadanie a osetrenie 2. bodu	
	
	printf( "Bod #2:\n" );
	if (scanf( "%d %d %d", &x2, &y2, &z2 ) !=3  // basic osetrenia
			|| x2 > rm
			|| y2 > rm
			|| z2 > rm 
			|| z2 == 0
			|| z2 == rm)
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}	
	if ( x2 != 0 && y2 !=0 && x2 != rm && y2 != rm )  // ostrenie ci je 2. bod v stene
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}
	if ( (x2 == 0 || x2 == rm) && ((y2 < 20 || y2 > (rm -20)) || (z2 < 20 || z2 > (rm -20))) )  // osetrenie 20 pre y a z
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}
	if ( (y2 == 0 || y2 == rm) && ((x2 < 20 || x2 > (rm -20)) || (z2 < 20 || z2 > (rm -20))) )  // osetrenie 20 pre x a z
	{
		printf( "Nespravny vstup.\n");
		return EXIT_FAILURE;
	}

	
	// ALGORITMUS NA VYPOCTY POTRUBIA A HADICE
	
	// A) susedne steny
	
	if ( ((x1 == 0 || x1 == rm) && (y2 == rm || y2 == 0)) || ((x2 == 0 || x2 == rm) && (y1 == rm || y1 == 0)) || ((y1 == 0 || y1 == rm) && (x2 == 0 || x2 == rm)) || ((y2 == 0 || y2 == rm) && (x1 == 0 || x1 == rm)))
	{
		if ( x1 >= x2 )
		{
			dp += (x1 - x2);
			odves1 += (x1 - x2);
		}
		else 
		{
			dp += (x2 - x1);
			odves1 += (x2 - x1);
		}
		if ( y1 >= y2 )
		{
			dp += (y1 - y2);
			odves1 += (y1 - y2);
		}
		else 
		{
			dp += (y2 - y1);
			odves1 += (y2 - y1);
		}
		if ( z1 >= z2 )
		{
			dp += (z1 - z2);
			odves2 += (z1 - z2);
		}
		else 
		{
			dp += (z2 - z1);
			odves2 += (z2 - z1);
		}
		dh = sqrt(pow(odves1,2)+pow(odves2,2));
		printf("Delka potrubi: %d\n", dp);
		printf("Delka hadice: %lf\n", dh);
	}
		
	// B) Predna a zadna stena
	
	if ((y1 == 0 && y2 == rm) || (y2 == 0 && y1 == rm))
	{
		if ( x1 + x2 < (rm - x1 + rm - x2))   // najdenie rychlesej cesty
		{
			dp += (x1 + x2);
			odves1 += (x1 + x2);
			if (y1 >= y2)
			{
				dp += (y1 - y2);
				odves1 += (y1 - y2);
			}
			else 
			{
				dp += (y2 - y1);
				odves1 += (y2 - y1);
			}
			if (z1 >= z2)
			{
				dp += (z1 - z2);
				odves2 += (z1 - z2);
			}
			else
			{
				dp += (z2 - z1);
				odves2 += (z2 - z1);
			}
			dh = sqrt(pow(odves1,2)+pow(odves2,2));
			printf("Delka potrubi: %d\n", dp);
			printf("Delka hadice: %lf\n", dh);
		}
		else                                 // najdenie rychlejsej cesty
		{
			dp += (rm - x1 + rm - x2);
			odves1 += (rm - x1 + rm - x2);
			if (y1 >= y2)
				{
					dp += (y1 - y2);
					odves1 += (y1 - y2);
				}
				else 
				{
					dp += (y2 - y1);
					odves1 += (y2 - y1);
				}
				if (z1 >= z2)
				{
					dp += (z1 - z2);
					odves2 += (z1 - z2);
				}
				else
				{
					dp += (z2 - z1);
					odves2 += (z2 - z1);
				}
				dh = sqrt(pow(odves1,2)+pow(odves2,2));
				printf("Delka potrubi: %d\n", dp);
				printf("Delka hadice: %lf\n", dh);
		}
	}
	
	// C) Bocna a bocna stena 
	
	if ( (x1 == rm && x2 == 0) || (x1 == 0 && x2 == rm))
	{
		if ( y1 + y2 < (rm - y1 + rm - y2))   // najdenie rychlesej cesty
		{
			dp += (y1 + y2);
			odves1 += (y1 + y2);
			if (x1 >= x2)
			{
				dp += (x1 - x2);
				odves1 += (x1 - x2);
			}
			else 
			{
				dp += (x2 - x1);
				odves1 += (x2 - x1);
			}
			if (z1 >= z2)
			{
				dp += (z1 - z2);
				odves2 += (z1 - z2);
			}
			else
			{
				dp += (z2 - z1);
				odves2 += (z2 - z1);
			}
			dh = sqrt(pow(odves1,2)+pow(odves2,2));
			printf("Delka potrubi: %d\n", dp);
			printf("Delka hadice: %lf\n", dh);
		}
		else                                  // najdenie rychlesej cesty       
		{
			dp += (rm - y1 + rm - y2);
			odves1 += (rm - y1 + rm - y2);
			if (x1 >= x2)
			{
				dp += (x1 - x2);
				odves1 += (x1 - x2);
			}
			else 
			{
				dp += (x2 - x1);
				odves1 += (x2 - x1);
			}
			if (z1 >= z2)
			{
				dp += (z1 - z2);
				odves2 += (z1 - z2);
			}
			else
			{
				dp += (z2 - z1);
				odves2 += (z2 - z1);
			}
			dh = sqrt(pow(odves1,2)+pow(odves2,2));
			printf("Delka potrubi: %d\n", dp);
			printf("Delka hadice: %lf\n", dh);
		}
	}	
	
	// D) Rovnaka stena 
	
	if ( (x1 == 0 && x2 == 0) || (x1 == rm && x2 == rm) || (y1 == 0 && y2 == 0) || (y1 == rm && y2 == rm))
	{
		if ( x1 >= x2)
		{
		dp += (x1 - x2);
		odves1 += (x1 - x2);
		}
		else
		{
		dp += (x2 - x1);
		odves1 += (x2 - x1);
		}
		if ( y1 >= y2)
		{
		dp += (y1 - y2);
		odves1 += (y1 - y2);
		}
		else
		{
		dp += (y2 - y1);
		odves1 += (y2 - y1);
		}
		if ( z1 >= z2)
		{
		dp += (z1 - z2);
		odves2 += (z1 - z2);
		}
		else
		{
		dp += (z2 - z1);
		odves2 += (z2 - z1);
		}
		dh = sqrt(pow(odves1,2)+pow(odves2,2));
		printf("Delka potrubi: %d\n", dp);
		printf("Delka hadice: %lf\n", dh);
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

