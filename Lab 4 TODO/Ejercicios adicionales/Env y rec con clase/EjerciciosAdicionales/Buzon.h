//
// Created by jimmy on 11/09/18.
//

#ifndef SEM_BUZONES_BUZON_H
#define SEM_BUZONES_BUZON_H


#define KEY 0xB50060	// Valor de la llave del recurso
#define MSGSIZE 64

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


class Buzon {
    struct my_msgbuf {
               long mtype;       // message type, must be > 0
               int times;
               char msj[MSGSIZE];    // message data
    };
    
public:
    Buzon();
    ~Buzon();
    int Enviar(const char * nmsj, int i, long type);
    int Recibir(long type);  
private:
    int id;		// Identificador del buzon
};

#endif //SEM_BUZONES_BUZON_H
