//
// Created by jimmy on 11/09/18.
//

#ifndef SEM_BUZONES_SEMAFORO_H
#define SEM_BUZONES_SEMAFORO_H


#define KEY 0xB50060	// Valor de la llave del recurso

class Semaforo {
public:
    Semaforo( int ValorInicial = 0 );
    ~Semaforo();
    int Signal();	// Puede llamarse V
    int Wait();	// Puede llamarse P
private:
    int id;		// Identificador del semaforo
};

#endif //SEM_BUZONES_SEMAFORO_H
