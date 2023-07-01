#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <assert.h>
#endif /* __PROGTEST__ */


int nextPalindrome(unsigned long long from, int radix, unsigned long long * next)
{
  unsigned long long help_from = from;
  int count = 0;
  unsigned long long field1 [65];
  unsigned long long field2 [65];
  int is_pal = 0;

  if ( radix < 2 || radix > 36 )
		return 0;
  
  if ( from == ULONG_MAX )
  	return 0;
  
  while ( 1 )
	{
		from += 1;  
	  help_from = from;
	  	
	  	while ( help_from != 0 )               // converting to a different base
	  	{
	  		int converted;
	  		converted = ( help_from % radix );
	  		help_from = help_from / radix;
	  		field1[count] = converted;
				count += 1;
	  	}
	  	
	  	for ( int i = 0; i < count; i++ )    // reversing an array
	  		field2[count -i -1] = field1[i];
	  	
	  	for ( int i = 0; i < count; i++ )    // comparing an array
	  	{
	  		if ( field1[i] != field2[i]  )
	  		{
	  			is_pal = 0;
	  			break;
	  		}
	  		else 
	  			is_pal = 1;
	  	}
		count = 0;
		if ( is_pal == 1 )
		{
			* next = from;
			break;  
		}
	}
	return 1;
}
  

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  unsigned long long next;

  assert ( nextPalindrome ( 123, 10, &next ) == 1
           && next == 131 );
  assert ( nextPalindrome ( 188, 10, &next ) == 1
           && next == 191 );
  assert ( nextPalindrome ( 1441, 10, &next ) == 1
           && next == 1551 );
  assert ( nextPalindrome ( 95, 15, &next ) == 1
           && next == 96 ); /* 96 = 66 (radix 15) */
  assert ( nextPalindrome ( 45395, 36, &next ) == 1
           && next == 45431 ); /* 45431 = z1z (radix 36) */
  assert ( nextPalindrome ( 1027, 2, &next ) == 1
           && next == 1057 ); /* 1057 = 10000100001 (radix 2) */
  assert ( nextPalindrome ( 1000, 100, &next ) == 0
           && next == 1057 );
  assert ( nextPalindrome ( 18446744073709551614LLu, 2, &next ) == 1
           && next == 18446744073709551615LLu ); /* 18446744073709551615 = 1111111111111111111111111111111111111111111111111111111111111111 (radix 2) */
  assert ( nextPalindrome ( 18446744073709551615LLu, 2, &next ) == 0
           && next == 18446744073709551615LLu );
  return 0;
}
#endif /* __PROGTEST__ */

