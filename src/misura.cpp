#ifndef MISURA_CPP
#define MISURA_CPP

#include "../include/misura.h"
#include "../include/lettura.h"
#include <ostream>

/*
    definizione di tutti i metodi della classe misura, dichiarata in inertialDriver.h
*/

//creo oggetti misura vuoti, in cui tutte le letture sono inizializzate con il costruttore di default
misura::misura()
{
    for(int i = 0; i < DIM; i++)
        data[i] = lettura();
}

//costruttore di copia
misura::misura (const misura& a)        
{
    for(int i = 0; i < DIM; i++)
        data[i] = a.data[i];
}

//costruttore con array stile C come parametro, usato nel push_back di InertialDriver che deve prendere
//in input un array stile C di letture
misura::misura (const lettura lett[])
{
    for(int i = 0; i < 17; i++)
    {
        data[i] = lett[i];
    }
}

//costruttore di copia
misura misura::operator=(const misura& a)
{
    for(int i = 0; i < DIM; i++)
        data[i] = a.data[i];
        
    return *this;
}

//assegnamento con array stile C come parametro, usato nel push_back di InertialDriver che deve prendere
//in input un array stile C di letture
misura misura::operator=(const lettura lett[])
{
    for(int i = 0; i < 17; i++)
    {
        data[i] = lett[i];
    }
        
    return *this;
}

//restituisce l'oggetto lettura nella posizione passata come parametro
lettura& misura::operator[](int pos)
{return data[pos];}

//restituisce l'oggetto lettura nella posizione passata come parametro
const lettura& misura::operator[](int pos) const
{return data[pos];}

//restituisce la copia del buffer di misura come un array stile C di letture non sovrascrivibile
const lettura* misura::to_array()const
{return data;}

std::ostream& operator<<(std::ostream& os, const misura& m)
{
    for(int i = 0; i < 17; i++)
    {
        os<<m[i]<<"\n";
    }
    return os;
}

#endif
