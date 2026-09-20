#ifndef LETTURA_CPP
#define LETTURA_CPP

#include "../include/lettura.h"
#include <ostream>

/*
    definizione di tutti i metodi della classe lettura, dichiarata in inertialDriver.h
*/

//inizializza tutti i campi a 0.0
lettura::lettura()
: yaw_v{0}, yaw_a{0}, pitch_v{0}, pitch_a{0}, roll_v{0}, roll_a{0}
{}

//inizializza i campi con i valori passati come parametro, nell'ordine, yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a
lettura::lettura(double a, double b, double c, double d, double e, double f)
: yaw_v{a}, yaw_a{b}, pitch_v{c}, pitch_a{d}, roll_v{e}, roll_a{f} 
{}

//faccio la copia membro a membro dell'oggetto lettura passato come parametro
lettura::lettura(const lettura& lett)
:yaw_v{lett.yaw_v}, yaw_a{lett.yaw_a}, pitch_v{lett.pitch_v}, 
pitch_a{lett.pitch_a}, roll_v{lett.roll_v}, roll_a{lett.roll_a}
{}

//faccio l'assegnamento membro a membro dell'oggetto lettura passato come parametro
lettura& lettura::operator=(const lettura& lett) 
{
    yaw_v = lett.yaw_v;
    yaw_a = lett.yaw_a;
    pitch_v = lett.pitch_v;
    pitch_a = lett.pitch_a;
    roll_v = lett.roll_v;
    roll_a = lett.roll_a;

    return *this;
}

//get_a ritorna il valore del campo a, dove a può essere yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a

double lettura::get_yaw_v()
{return yaw_v;}

const double lettura::get_yaw_v()const
{return yaw_v;}
    
double lettura::get_yaw_a()
{return yaw_a;}

const double lettura::get_yaw_a()const
{return yaw_a;}
    
double lettura::get_pitch_v()
{return pitch_v;}

const double lettura::get_pitch_v()const
{return pitch_v;}
    
double lettura::get_pitch_a()
{return pitch_a;}

const double lettura::get_pitch_a()const
{return pitch_a;}
    
double lettura::get_roll_v()
{return roll_v;}

const double lettura::get_roll_v()const
{return roll_v;}
    
double lettura::get_roll_a()
{return roll_a;}

const double lettura::get_roll_a()const
{return roll_a;}

std::ostream& operator<<(std::ostream& os, const lettura& lett)
{
    return os<<lett.get_yaw_v()<<" "<<lett.get_yaw_a()<<" "<<lett.get_pitch_v()<<" "<<
    lett.get_pitch_a()<<" "<<lett.get_roll_v()<<" "<<lett.get_roll_a();
}

#endif
