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
    my_msgbuf sender;
    ssize_t len = sizeof(sender)-sizeof(long);
    sender.mtype = 180;
    //strcpy(sender.msj, msj);
    strncpy(sender.msj, nmsj , MSGSIZE);
    int st = msgsnd(id,&sender,len, IPC_NOWAIT);
    if(-1 == id){ //hubo error
        perror("Buzon::enviar falló");
        exit(2);
    }
}

int Buzon::Recibir(char *mensaje, int len) {
    my_msgbuf receiver;
    len = sizeof(receiver);
    strncpy(receiver.msj, mensaje , MSGSIZE);

}