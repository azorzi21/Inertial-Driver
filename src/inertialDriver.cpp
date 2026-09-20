#ifndef INERTIAL_CPP
#define INERTIAL_CPP

#include "../include/inertialDriver.h"
#include "../include/misura.h"
#include "../include/lettura.h"
#include <stdexcept>
#include <ostream>

/*
    definizione di tutti i metodi della classe InertialDriver, dichiarata in inertialDriver.h
*/

// Calcola l'indice circolare nel buffer. Usato in pop_front() e push_back().
void InertialDriver::increment(int& index)
{index = (index + 1) % BUFFER_DIM;}

//la condizione front == back indica buffer vuoto, siccome back indica la prima cella libera
bool InertialDriver::isEmpty()
{return front == back;};

//costruttore di default, crea un buffer vuoto
InertialDriver::InertialDriver()
:buffer{MyVector<misura>(BUFFER_DIM)}, front{0}, back{0}
{}

//copy constructor
InertialDriver::InertialDriver(const InertialDriver& other)
:buffer{MyVector<misura>(BUFFER_DIM)}, front{other.front}, back{other.back}
{
    for(int i = front; i != back; increment(i))
    {buffer[i] = other.buffer[i];}
}

//move constructor, uso std::move per evitare di fare una deep copy di tutti gli elementi del buffer
InertialDriver::InertialDriver(InertialDriver&& other)
: buffer(std::move(other.buffer)),front(other.front),back(other.back)
{
    other.front = 0;
    other.back = 0;
}

//aggiunge un elemento in coda in modo circolare, non uso il push_back di MyVector 
//perchè non supporta la gestione circolare
void InertialDriver::push_back(const lettura lett[])
{
    buffer[back] = lett;
    increment(back);

    if(back == front)
        increment(front);
}

//assegnamento di copia
InertialDriver& InertialDriver::operator= (const InertialDriver& other)
{
    front = other.front;
    back = other.back;
       
    //copia di buffer, non uso l'assegnamento di copia di MyVector perché non usando il push_back di MyVector,
    //non incremento mai la size del buffer, e siccome nell'assegnamento di copia di MyVector si copiano 
    //"size" elementi, non copierei nulla
    for(int i = front; i != back; increment(i))
    {buffer[i] = other.buffer[i];}

    return *this;
}

//move assignment, chiamo std::move su buffer per evitare di fare una deep copy di tutti gli elementi del buffer
InertialDriver& InertialDriver::operator=(InertialDriver&& other) 
{
    if (this != &other)
    {
        //chiamo std::move su buffer per evitare di fare una deep copy di tutti gli elementi del buffer
        buffer = std::move(other.buffer);
        front = other.front;
        back = other.back;
            
        other.front = 0;
        other.back = 0;
    }
    return *this;
}

//rimuove e restituisce la misura più vecchia nel buffer, lancia underflow_error se il buffer è vuoto
const lettura* InertialDriver::pop_front()
{
    if(!isEmpty())
    {
        int aux = front; 
        increment(front);

        return buffer[aux].to_array();
    }
    else
        throw underflow_error("pop_front su buffer vuoto");
}

//non elimino nessun elemento, semplicemente resetto gli indici per rendere gli elementi rimasti 
//nel buffer inaccessibili
void InertialDriver::clear_buffer()
{front = 0;back = 0;}

//restituisce la lettura nella posizione pos dell'ultima misura inserita, lancia out_of_range se pos non è valida
lettura InertialDriver::get_reading(int pos)
{
    if(pos < 0 || pos >= 17)
	{throw std::out_of_range("Indice non valido");}

    //cerco l'indice "precedente" a back in modo circolare
    int aux = back - 1;
    if(aux < 0)
        aux += BUFFER_DIM;

    return buffer[aux][pos];
}

//restituisce l'ultima misura inserita
misura InertialDriver::get_last()
{
    //cerco l'indice "precedente" a back in modo circolare
    int last = back - 1;
    if(last < 0)
        last += BUFFER_DIM;

    return buffer[last];
}

/*
    uso il distruttore di default, siccome il distruttore di default chiama i disutruttoridi tutti i membri 
    della classe, l'unico membro che alloca memoria dinamicamete è buffer, ma MyVector ha già un distruttore 
    che si occupa di deallocare la memoria allocata dinamicamente.
    Anche se questa notazione non è stata spiegata, tramite la consultazione di strumenti AI abbiamo notato che
    è possibile usare il distruttore di default in questo modo, ed è meglio che scrivere un distruttore con corpo
    vuoto perché se il costruttore è user-defined si impedisce al compilatore di fare certe ottimizzazioni.
*/
InertialDriver::~InertialDriver() = default;


ostream& operator<<(ostream& os, InertialDriver driver)
{
    misura m = driver.get_last();
    return os << m;
}

#endif
