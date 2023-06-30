#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){

	double credit_interest, debet_interest, money, zustatek = 0; 
	int day, the_prev_day = 0;
	
	
	printf( "%s\n", "Zadejte kreditni urok [%]:" );                //inputs
	if (scanf( "%lf", &credit_interest) != 1 ||
	    credit_interest < 0 ||
	    credit_interest > 1)
	{
		printf( "%s\n", "Nespravny vstup." );		
		return EXIT_FAILURE;
	}
	
	printf( "%s\n", "Zadejte debetni urok [%]:" );
	if (scanf( "%lf", &debet_interest) != 1 ||
	    debet_interest < 0 ||
	    debet_interest > 1)
	{
		printf( "%s\n", "Nespravny vstup." );		
		return EXIT_FAILURE;
	}	
	
	printf( "%s\n", "Zadejte transakce:" );											 //algorithm
	if (scanf( "%d, %lf", &day, &money ) !=2 || day < 0)
	{
		printf( "%s\n", "Nespravny vstup." );
		return EXIT_FAILURE;
	}
	
	money = trunc(money * 100) / 100;
	the_prev_day = day;
	zustatek += money;
		
	if ( money == 0)
	{
		printf("Zustatek: %.2lf\n", zustatek);
		return EXIT_SUCCESS;
	}
	
	while (money != 0)
	{	
		if (scanf("%d, %lf", &day, &money) !=2 || day < the_prev_day)
		{
			printf("%s\n", "Nespravny vstup.");
			return EXIT_FAILURE;	
		}
		money = trunc(money * 100) / 100;
		
		int i = the_prev_day;
		for (; i < day; i ++)
		{
			if (zustatek <= 0)
				zustatek += trunc((zustatek * (debet_interest / 100)) * 100 ) / 100;
			else 
				zustatek += trunc((zustatek * (credit_interest / 100)) * 100 ) / 100;
		}
		zustatek += money;
		the_prev_day = day;		 
	}
	
	printf("Zustatek: %.2lf\n", zustatek);	
}

