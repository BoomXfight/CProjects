#ifndef __PROGTEST__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#endif /* __PROGTEST__ */


/* Function checks whetehr a word in dictionary is not a prefix of another word.
 * @param[in] 2D array to be check.
 * @retrun 1 to indicate the found prefix in another word; 0 for success = no prefixes. 
*/
int inpt_check ( const char * array [][2] )
{
  int i = 0;
  int j = 0;

  while ( array[i][0] != NULL )
  {
    j = 0;
    while ( array[j][0] != NULL )
    {
      if ( j == i ) // Prevents from comparing the same word.
      {
        j++;
        if ( array[j][0] == NULL )
          return 0;
      }
      if ( strstr ( array[i][0], array[j][0] ) == array[i][0] )  // Found prefix 
      {
        return 1;
      }
      else
        j++;
    }
    i++;
  }
  return 0;
}


/* Function that manages dynamically allocated memory throughout the program.
 * @param[in] arr_length = current length of the array.
 * @param[in] *arr_capacity = current maximum capacity of the array.
 * @param[in] *array = pointer to an dynamically allocated array.
 * @param[in] str_length = current length of a string that is to be added to the array.
 * @return pointer to the reallocated array
*/
char* memory_management ( int *arr_length, int *arr_capacity, int str_length, char *array )
{
  *arr_length += str_length +1;
  if ( *arr_length + str_length >= *arr_capacity )   // Checks whetehr it is needed to add space to an array
    {
       *arr_capacity += *arr_capacity + str_length + 1;
       array = (char *) realloc ( array, *arr_capacity * sizeof( char ) );
    }
    return array;
}


/* Function that cenzures the text according to the provided dictionary
 * @param[in] text =  uncenzured, original text
 * @param[in] (*replace)[2] = 2D array dictionary, 0th index -> ucenzured word; 1st index -> cenzured word
 * @return pointer to the final cenzured text
*/
char * newSpeak ( const char * text, const char * (*replace)[2] )
{
  if ( inpt_check (replace) == 1)
    return NULL;


  char *final_text = NULL;         
  int length_of_final_text = 0;
  int capacity_of_final_text = 0;
  int i = 0;
  int j = 0;
  int k = 0;


  while ( text[i] )  // Traverses the text by character.
  {
    j = 0;
    while ( replace[j][0] )  // Traverses the 1st row of the 2D array.
    {
        while ( strstr ( &text[i], replace[j][0] ) == &text[i] )  // Looks for a substring in the text.
        {
          int replace_length = strlen( replace[j][1] );
          final_text = memory_management( &length_of_final_text, &capacity_of_final_text, replace_length, final_text );
          strcpy( &final_text[k], replace[j][1] );
          i += strlen( replace[j][0] );
          k += strlen( replace[j][1] );
          j = 0;
        }
        j++;
    }
    final_text = memory_management ( &length_of_final_text, &capacity_of_final_text, 1, final_text );
    final_text[k] = text[i];
    i ++;
    k ++;
  }
  final_text = memory_management ( &length_of_final_text, &capacity_of_final_text, 1, final_text );
  final_text[k] = '\0';
  return final_text;
}

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  char * res;

  const char * d1 [][2] =
  {
    { "murderer", "termination specialist" },
    { "failure", "non-traditional success" },
    { "specialist", "person with certified level of knowledge" },
    { "dumb", "cerebrally challenged" },
    { "teacher", "voluntary knowledge conveyor" },
    { "evil", "nicenest deprived" },
    { "incorrect answer", "alternative answer" },
    { "student", "client" },
    { NULL, NULL }
  };


  const char * d2 [][2] =
  {
    { "fail", "suboptimal result" },
    { "failure", "non-traditional success" },
    { NULL, NULL }
  };


  const char * a2 [][2] =
  {
    { " ", "*" },
    { NULL, NULL }
  };

  const char * a3 [][2] =
  {
    { NULL, NULL }
  };

  res = newSpeak ( "devildevilincorrect answerstudentmurderer", d1 );
  assert ( ! strcmp ( res, "dnicenest depriveddnicenest deprivedalternative answerclienttermination specialist" ) );
  free ( res );

  res = newSpeak ( "      ", a2 );
  assert ( ! strcmp ( res, "******" ) );
  free ( res );

  res = newSpeak ( "Ahoj", a3 );
  assert ( ! strcmp ( res, "Ahoj" ) );
  free ( res );

  res = newSpeak ( "studentevil", d1 );
  assert ( ! strcmp ( res, "clientnicenest deprived" ) );
  free ( res );

  res = newSpeak ( "Everybody is happy.", d1 );
  assert ( ! strcmp ( res, "Everybody is happy." ) );
  free ( res );

  res = newSpeak ( "The student answered an incorrect answer.", d1 );
  assert ( ! strcmp ( res, "The client answered an alternative answer." ) );
  free ( res );

  res = newSpeak ( "He was dumb, his failure was expected.", d1 );
  assert ( ! strcmp ( res, "He was cerebrally challenged, his non-traditional success was expected." ) );
  free ( res );

  res = newSpeak ( "The evil teacher became a murderer.", d1 );
  assert ( ! strcmp ( res, "The nicenest deprived voluntary knowledge conveyor became a termination specialist." ) );
  free ( res );

  res = newSpeak ( "Devil's advocate.", d1 );
  assert ( ! strcmp ( res, "Dnicenest deprived's advocate." ) );
  free ( res );

  res = newSpeak ( "Hello.", d2 );
  assert ( ! res );

  const char * xxxxxx [][2] = {
          {"prisoner","client of the correctional system"}
          ,{"son","offspring with both X and Y chromosomes"}
          ,{NULL,NULL}};

  res = newSpeak("son of a prisoner",xxxxxx);
  assert (! strcmp (res, "offspring with both X and Y chromosomes of a client of the correctional system"));
  free (res);


    const char * d8 [][2] =
            {
                    { " asi vyskocim z okna po tomto pojebanom progteste ", "zabitemapls" },
                    { "kokotina na entu", "progtest" },
                    { NULL, NULL }
            };

    res = newSpeak ( " asi vyskocim z okna po tomto pojebanom progteste  asi vyskocim z okna po tomto pojebanom progteste  kokotina na entu  asi vyskocim z okna po tomto pojebanom progteste asi vyskocim z okna po tomto pojebanom progtestekokotina na entu", d8 );
    assert ( ! strcmp ( res, "zabitemaplszabitemapls progtest zabitemaplsasi vyskocim z okna po tomto pojebanom progtesteprogtest" ) );
    free ( res );
    
const char * xxxxx [][2] =
{
  { "answer", "conventional answer" },
  { "wrong answer", "alternative answer" },
  { NULL, NULL }
};

res = newSpeak ( "correct answer and wrong answer are opposites", xxxxx );
    assert ( ! strcmp ( res, "correct conventional answer and alternative answer are opposites" ) );
    free ( res );
    
const char * xxxx [][2] = 
{
  { "foobar", "xyz" },
  { "foo", "abc" },
  { NULL, NULL }
};

res = newSpeak ( "bar", xxxx );
    assert ( ! res );
    
const char * xxx[][2] = {
      { "Nina","Ninja"},
      { "Maria", "Mario"},
      { "Neboskova","Nebo stika"},
      {NULL,NULL}
    };
res = newSpeak ( "", xxx);
assert ( ! strcmp ( res, "" ) );
    free ( res );
    
    
const char * xx[][2] = {
      { "Nina","Ninja"},
      { "Maria", "Mario"},
      { "Neboskova","Nebo stika"},
      {NULL,NULL}
    };
res = newSpeak ( "NinaNinaNinaNinaNinaNina.", xx);
assert ( ! strcmp ( res, "NinjaNinjaNinjaNinjaNinjaNinja." ) );
    free ( res );

    
const char * x[][2] = {
      { "i","X"},
      {NULL,NULL}
    };
res = newSpeak ( "Thiiis is a certtified hood classic.", x);
assert ( ! strcmp ( res, "ThXXXs Xs a certtXfXed hood classXc." ) );
    free ( res );
    
const char * xd[][2] = {
      { "i",""},
      {NULL,NULL}
    };
res = newSpeak ( "Thiiis is a certtified hood classic.", xd);
assert ( ! strcmp ( res, "Ths s a certtfed hood classc." ) );
    free ( res );


    
    
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
