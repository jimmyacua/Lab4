#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <wait.h>

#include "Semaforo.h"
#include "Buzon.h"

int main(int argc, char *argv[]) {
    /*int i;
   Semaforo s;
   int id = shmget( 123456, 1024, 0700 | IPC_CREAT );
   char * area = (char *) shmat( id, NULL, 0 );
   char * var = "Area de memoria compartida";
   char newvar[100];

   if ( fork() ) {
      strcpy( area, var );
      printf( "Escriba un numero y  para continuar ...\n" );
      scanf( "%i", &i );
      printf( "Variable es %s \n", area );
      s.Signal();
   }
   else {
      s.Wait();
      strcpy( newvar, area );
      printf( "La variable compartida es: %s \n", newvar );
      exit( 0 );
   }
   wait( &i );
   printf( "Fin del programa ... \n" );
   shmdt( area );
   shmctl( id, IPC_RMID, NULL );*/
//---------------------------------------------------------------------------------------------------------------
    Buzon b;
    int i, id;
    char a[80];

    id = fork();
    if ( id ) {
        i= 1;
       printf( "Escriba un numero y  para enviar el mensaje\n" );
       scanf( "%i", &i );
       b.Enviar( "Hola mundo" );
       _exit(0);

    }
    else {
       printf( "Esperando que el mensaje llegue  ...\n" );
       b.Recibir( a, 80 );
       printf( "El mensaje recibido es: %s \n", a );
       _exit(0);
    }
//------------------------------------------------------------------------------
    /*Buzon b;
    char a[80];
    b.Enviar("hola mundo");
    printf("Mensaje enviado \n");
    b.Recibir(a,80);
     */
 //------------------------------------------------------------------------------
   
    /*
   int i;
   Semaforo s;
   int id = shmget( 123456, 1024, 0700 | IPC_CREAT );
   char * area = (char *) shmat( id, NULL, 0 );
   char * var = "Area de memoria compartida";
   char newvar[100];

   if ( fork() ) {
      strcpy( area, var );
      printf( "Escriba un numero y  para continuar ...\n" );
      scanf( "%i", &i );
      printf( "Variable es %s \n", area );
      s.Signal();
   }
   else {
      s.Wait();
      strcpy( newvar, area );
      printf( "La variable compartida es: %s \n", newvar );
      exit(0);
   }
   wait( &i );
   printf( "Fin del programa ... \n" );
   shmdt( area );
   shmctl( id, IPC_RMID, NULL ); 
    */
}
