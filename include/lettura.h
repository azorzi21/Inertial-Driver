#ifndef LETTURA_H
#define LETTURA_H

#include <ostream>

class lettura
{
    public: 

    //costruttore di default, inizializza tutti i campi a 0.0
    lettura();

    //costruttore che prende in input, nell'ordine, yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a
    lettura(double, double, double, double, double, double);

    //copy constructor
    lettura(const lettura&);

    //copy assignment
    lettura& operator=(const lettura&);

    //metodi get
    double get_yaw_v();
    const double get_yaw_v()const;
    double get_yaw_a();
    const double get_yaw_a()const;
    double get_pitch_v();
    const double get_pitch_v()const;
    double get_pitch_a();
    const double get_pitch_a()const;
    double get_roll_v();
    const double get_roll_v()const;
    double get_roll_a();
    const double get_roll_a()const;


    private: 

    double yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a;
};

//operatore << per lettura, stampa le 6 variabili membro di lettura, nell'ordine, yaw_v, yaw_a, pitch_v, pitch_a, 
//roll_v, roll_a
std::ostream& operator<<(std::ostream& os, const lettura& lett);

#endif