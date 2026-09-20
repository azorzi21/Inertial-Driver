#ifndef MyVector_H
#define MyVector_H

#include <iostream>

using namespace std;

template <typename T>
class MyVector
{
	public:
	//costruttore di default
	MyVector();

	//copy constructor
	MyVector(const MyVector&);

	//inizializza un vettore vuoto di dimensione dim
	MyVector(int dim);

	//move constructor
	MyVector(MyVector&&);
	
	//restituisce la dimensione del vettore
	int size() const;
	
	//assegnamento di copia
	MyVector& operator=(MyVector&);	

	//move assignment
	MyVector& operator=(MyVector&&);

	//accede all'elemento in posizione pos
	T& operator[](int pos);

	//accede all'elemento in posizione pos (versione per oggetti const)
    const T& operator[](int pos) const;
    
	//accede all'elementoin posizione pos con boundary check
	T& at(int pos);

	//accede all'elementoin posizione pos con boundary check (versione per oggetti const)
    const T& at(int pos) const;

	//aggiunge un elemento in coda
    void push_back(T d);

	//rimuove e restituisce l'ultimo elemento
    T pop_back();

	//riserva spazio per n elementi
    void reserve(int n);

	//distruttore
	~MyVector();

	private:
	int sz;
	int max;
	T* elem;
	
	//ridimensiona il vettore a dimensione n
	void resize(int n);
};

#include "MyVector.hpp"

#endif