#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Semaforo.h"
#include "Buzon.h"

int main() {
    Semaforo s;
    Buzon b;
    int i, id;
    char a[80];

    id = fork();
    if ( id ) {
        printf( "Escriba un numero y  para enviar el mensaje\n" );
        scanf( "%i", &i );
        b.Enviar( "Hola mundo" );
        exit(0);

    }
    else {
        printf( "Esperando que el mensaje llegue  ...\n" );
        b.Recibir( a, 80 );
        printf( "El mensaje recibido es: %s \n", a );
    }
/*
    if ( fork() ) {
        for (int i = 0; i < 10; i++ )
            printf( "Esperando para activar el semaforo %d \n", i );
        scanf( "%i", &i );
        s.Signal();
    }
    else {
        printf( "Esperando que el semaforo se active  ...\n" );
        s.Wait();
        printf( "Semaforo activado\n" );
    }
    */
}
