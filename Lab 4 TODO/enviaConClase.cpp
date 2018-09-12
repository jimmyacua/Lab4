#define LABEL_SIZE 64
#include <stdio.h>
#include <string.h>

#include "Buzon.h"

const char * html_labels[] = {
   "a",
   "b",
   "c",
   "d",
   "e",
   "li",
   ""
};

int main( int argc, char ** argv ) {


   int id, i, size, st;
   Buzon b;

   i = 0;

   while ( strlen(html_labels[ i ] ) ) {
      b.Enviar( html_labels[ i ], i, 2018 );  // Send a message with 2018 type, (label,n)
      printf("Label: %s, status %d \n", html_labels[ i ], st );
      i++;
   }

}


