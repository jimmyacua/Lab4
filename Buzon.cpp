//
// Created by jimmy on 11/09/18.
//



#include "Buzon.h"

struct my_msgbuf {
               long mtype;       // message type, must be > 0
               char msj[MSGSIZE];    // message data
};


Buzon::Buzon(){
    id = msgget(KEY,IPC_CREAT|0600);
    if(-1 == id){ //hubo error
        perror("Buzon::constructor");
        exit(2);
    }
}

Buzon::~Buzon(){
    int st = msgctl(id, IPC_RMID, NULL);
}

int Buzon::Enviar(char * nmsj){
    struct my_msgbuf sender;
    ssize_t len = sizeof(sender.msj)-sizeof(long);
    sender.mtype = 1;
    //strcpy(sender.msj, msj);
    strncpy(sender.msj, nmsj , MSGSIZE);
    int st = msgsnd(id,&sender,len, IPC_NOWAIT);
    if(-1 == st){ //hubo error
        perror("Buzon::enviar falló");
        exit(2);
    }
}

int Buzon::Recibir(char *mensaje, int len) {
    struct my_msgbuf receiver;
    int st = msgrcv(id,&receiver, len,1,MSG_NOERROR | IPC_NOWAIT);
    //strncpy(receiver.msj, mensaje , MSGSIZE);
    if(-1 == st){ //hubo error
        perror("Buzon::recibir falló");
        exit(2);
    } else{
        mensaje = receiver.msj;
        printf("El mensaje recibido es: %s\n", mensaje);
    }
}