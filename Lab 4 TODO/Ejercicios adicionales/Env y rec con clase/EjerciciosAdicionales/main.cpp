/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: b50060@ecci.ucr.ac.cr
 *
 * Created on September 12, 2018, 4:03 PM
 */
#define LABEL_SIZE 64


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
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


/*
 * 
 */
int main(int argc, char** argv) {
    
    //Enviar
    int id, i, size, st;
    Buzon b;
    i = 0;
    while ( strlen(html_labels[ i ] ) ) {
      b.Enviar( html_labels[ i ], i, 2018 );  // Send a message with 2018 type, (label,n)
      printf("Label: %s, status %d \n", html_labels[ i ], st );
      i++;
    }
    printf("Fin envio  \n");
    //_exit(0);
    //-----------------------------------------------------
    
    
    //Recibir
    /*struct msgbuf {
       long mtype;     // message type, must be > 0 
       int times;	// Times that label appears
       char label[ LABEL_SIZE ];  // Label to send to mailbox
};

   struct msgbuf A;*/
   //int id, size, st;
   //Buzon b;

   st = b.Recibir(2018 );  // Receives a message with 2016 type
   while ( st > 0 ) {
      //printf("Label: %s, times %d \n", A.label, A.times );
      st = b.Recibir(2018 );
   }
   _exit(0);

   b.~Buzon();
}