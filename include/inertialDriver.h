#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "MyVector.h"
#include "misura.h"
#include "lettura.h"
#include <ostream>

class InertialDriver
{
    public:
    
    //costruttore di default, crea un buffer vuoto
    InertialDriver();

    //copy constructor
    InertialDriver(const InertialDriver& other);

    //move constructor
    InertialDriver(InertialDriver&& other);

    //copy assignment
    InertialDriver& operator= (const InertialDriver&);

    //move assignment   
    InertialDriver& operator=(InertialDriver&& other);

    //inserisce una nuova misura nel buffer
    void push_back(const lettura lett[]);    
    
    //rimuove e restituisce la misura più vecchia nel buffer, lancia underflow_error se il buffer è vuoto
    const lettura* pop_front();

    //svuota il buffer
    void clear_buffer();

    //restituisce la lettura nella posizione pos dell'ultima misura inserita, lancia out_of_range se pos non è valida
    lettura get_reading(int pos);

    //restituisce l'ultima misura inserita
    misura get_last();

    //distruttore
    ~InertialDriver();


    private:

    static const int BUFFER_DIM = 20;
    MyVector<misura> buffer;
    int front;
    int back;

    //incrementa l'indice passato come parametro in modo circolare
    void increment(int&);

    //controlla se il buffer è vuoto
    bool isEmpty();
};

//operatore << per InertialDriver, stampa l'ultima misura inserita nel buffer
ostream& operator<<(ostream& os, InertialDriver driver);


#endif
