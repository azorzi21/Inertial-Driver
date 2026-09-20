#ifndef MISURA_H
#define MISURA_H

#include "lettura.h"
#include <ostream>

class misura
{
    public:

    //costruttore di default, inizializza tutte le letture con il costruttore di default
    misura();

    //copy constructor
    misura (const misura&);
    
    //costruttore con array stile C come parametro
    misura (const lettura[]);

    //copy assignment
    misura operator=(const misura&);

    //assignment con array stile C come parametro
    misura operator=(const lettura[]);

    //restituisce l'oggetto lettura nella posizione passata come parametro
    lettura& operator[](int);
    const lettura& operator[](int) const;

    //restituisce un array non modificabile di letture
    const lettura* to_array() const;

    private:
    const int DIM = 17;
    lettura data[17];
};

//operatore << per misura, stampa le 17 letture contenute in misura, una per riga
std::ostream& operator<<(std::ostream& os, const misura& m);



#endif