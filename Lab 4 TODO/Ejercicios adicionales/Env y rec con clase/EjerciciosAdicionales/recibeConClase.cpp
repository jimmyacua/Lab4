#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Buzon.h"

#define LABEL_SIZE 64


int main( int argc, char ** argv ) {


/*struct msgbuf {
       long mtype;     // message type, must be > 0 
       int times;	// Times that label appears
       char label[ LABEL_SIZE ];  // Label to send to mailbox
};

   struct msgbuf A;*/
   int id, size, st;
   Buzon b;

   st = b.Recibir(2018 );  // Receives a message with 2016 type
   while ( st > 0 ) {
      //printf("Label: %s, times %d \n", A.label, A.times );
      st = b.Recibir(2018 );
   }

    //b.~Buzon();

}



