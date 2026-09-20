#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

using namespace std;

//tutti i campi vengono inizializzati a 0 (nullptr per il buffer elem)
template <typename T>
MyVector<T>::MyVector()
:sz{0}, max{0}, elem{nullptr}
{}

//costruttore che inizializza un vettore vuoto di dimensione dim
template <typename T>
MyVector<T>::MyVector(int dim)
{
	sz = 0;
	max = dim;
	elem = new T[dim];
}

//costruttore di copia, copio solo sz elementi (gli elementi entro la dimensione logica)
template <typename T>
MyVector<T>::MyVector(const MyVector<T>& arg)
:sz{arg.sz}, elem{new T[arg.sz]}, max{arg.max}
{
	copy(arg.elem, arg.elem+arg.sz, elem);
}


///move constructor, copio i campi uno ad uno eccetto per il buffer elem,
//per il quale faccio una shallow copy invalidando il buffer dell'oggetto sorgente
template <typename T>
MyVector<T>::MyVector(MyVector&& arg)
:sz{arg.sz}, max{arg.max}, elem{arg.elem}
{
	arg.sz = 0;
	arg.max = 0;
	arg.elem = nullptr;
}

//restituisce la dimesione logica del vettore
template <typename T>
int MyVector<T>::size() const
{return sz;}

//assegnamento di copia, deep copy membro a membro
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector& arg)
{
	T* p = new T[arg.sz];
	copy(arg.elem, arg.elem+arg.sz, p);
	delete[] elem;
	elem = p;
	sz = arg.sz;
	max = arg.max;

	return *this;
}

//move assignment, copio i campi uno ad uno eccetto per il buffer elem,
//per il quale faccio una shallow copy invalidando il buffer dell'oggetto sorgente
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& arg)
{
	sz = arg.sz;
	max = arg.max;
	elem = arg.elem;

	arg.sz = 0;
	arg.max = 0;
	arg.elem = nullptr;

	return *this;
}

//restituisce l'elemento in posizione pos
template <typename T>
T& MyVector<T>::operator[](int pos)
{return elem[pos];}

//restituisce l'elemento in posizione pos (versione per oggetti const)
template <typename T>
const T& MyVector<T>::operator[](int pos) const
{return elem[pos];}

//restituisce l'elemento in posizione pos con boundary check
template <typename T>
T& MyVector<T>::at(int pos)
{
    if(pos < sz && pos >= 0)
        return elem[pos];
    else
        throw "Indice fuori dai limiti";
}

//restituisce l'elemento in posizione pos con boundary check (versione per oggetti const)
template <typename T>
const T& MyVector<T>::at(int pos) const
{
    if(pos < sz)
        return elem[pos];
    else
        throw "Indice fuori dai limiti";
}

//aggiunge un elemento in coda, ridimensionando il vettore se necessario con il doppio della dimensione
//per mantenere la complessità ammortizzata di O(1)
template <typename T>
void MyVector<T>::push_back(T d)
{
if(sz == max)
	{
		if(max == 0)
		{
			resize(1);
		}
		else
		{
			resize(2*max);
		}
	}
       
    elem[sz] = d;
    sz ++;
}

//elimina e restituisce l'ultimo elemento del vettore, decrementando la dimensione logica del vettore
template <typename T>
T MyVector<T>::pop_back()
{
	if(sz == 0)
	{
		throw "Vettore vuoto";
	}
    sz --;
    return elem[sz];
}

//riserva spazio per n elementi
template <typename T>
void MyVector<T>::reserve(int n)
{
    if(n > max)
        resize(n);
}

//elimina il buffer per evitare memory leak
template <typename T>
MyVector<T>::~MyVector()
{
	delete[] elem;
	elem = nullptr;
}
	
//ridimensiona il vettore a dimensione n
template <typename T>
void MyVector<T>::resize(int n)
{
	//gestisco il caso in cui n = 0 per evitare di avere un buffer di dimensione 0
	if(n == 0)
		n == 1;
	
	T* p = new T[n];
	copy(elem, elem+sz, p);
	delete[] elem;
		
	elem = p;
	max = n;
}
	
	
#endif