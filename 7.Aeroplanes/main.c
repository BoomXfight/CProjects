#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <time.h>


#define NAME_MAX 200


typedef struct {
    double coor_a;
    double coor_b;
    char name[NAME_MAX];
} PLANE;


typedef struct {
    double dist;
    char name1[NAME_MAX];
    char name2[NAME_MAX];
} DISTANCE;


double vector_distance ( PLANE * p, int i, int j )
{
    double distance;
    distance = sqrt( (p[j].coor_a - p[i].coor_a)*(p[j].coor_a - p[i].coor_a) + (p[j].coor_b - p[i].coor_b)*(p[j].coor_b - p[i].coor_b) );
    return distance;
}  


unsigned long long size_plane = 10;
unsigned long long size_distance = 10;


int main ( void )
{
    PLANE *planes;
    DISTANCE *pairs;
    unsigned long long cnt = 0;

    //-------------------------------- VSTUPY
    printf( "Pozice letadel:\n" );
    planes = (PLANE *) malloc ( size_plane * sizeof(*planes) );
    while ( scanf( "%lf , %lf : %199s", &planes[cnt].coor_a, &planes[cnt].coor_b, planes[cnt].name ) == 3 )
    {
        cnt ++; 

        // Dynamic array realocation;
        if ( cnt >= size_plane -1 )
        {
            size_plane = cnt * 2;
            planes = (PLANE *) realloc ( planes, size_plane * sizeof ( PLANE ) );
        }
    }   
    if ( ! feof (stdin ))
    {
        printf( "Nespravny vstup.\n" );
        free (planes);
        return EXIT_FAILURE;
    }
    if ( cnt < 2 )
    {
        printf( "Nespravny vstup.\n" );
        free (planes);
        return EXIT_FAILURE;
    }


    // Dynamic array for distance
    pairs = ( DISTANCE * ) malloc ( size_distance * sizeof( *pairs ) );

    //------------------------------ DISTANCE BETWEEN PLANES

    unsigned long long sum = 0; 
    double min_distance = 0;
    for ( unsigned long long i = 0; i < cnt; i ++ )
    {   
        for ( unsigned long long j = i + 1 ; j < cnt; j ++ )
        {
            
            double curr_dist = vector_distance (planes, i, j );
            if ( i == 0 && j ==1 )
                min_distance = curr_dist;
            //printf ("%.50lf\n", curr_dist);

            if ( fabs (curr_dist - min_distance) <= 1e-8 * fabs(curr_dist + min_distance) )
            {
                if ( sum > size_distance -1 )
                {
                    size_distance *= 2;
                    pairs = ( DISTANCE *) realloc ( pairs, size_distance * sizeof ( DISTANCE ));
                }
                strcpy(pairs[sum].name1, planes[i].name);
                strcpy(pairs[sum].name2, planes[j].name);
                sum ++;
            }

            else if ( curr_dist < min_distance )
            {
                min_distance = curr_dist;
                free(pairs);
                size_distance = 10;
                sum = 0;
                pairs = ( DISTANCE * ) malloc ( size_distance * sizeof( *pairs ) );
                strcpy(pairs[sum].name1, planes[i].name);
                strcpy(pairs[sum].name2, planes[j].name);
                sum++;
            }

            
        }
    }

    // Free the dynamically allocated memory
    free ( planes ); 


    printf( "Vzdalenost nejblizsich letadel: %lf\n", min_distance );
    printf( "Nalezenych dvojic: %lld\n", sum );


    for ( unsigned long long int i = 0; i < sum; i ++ )
    {
        printf ( "%s - %s\n", pairs[i].name1, pairs[i].name2 );
    }

    free ( pairs );
}
