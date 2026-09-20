#include "../include/lettura.h"
#include "../include/misura.h"
#include "../include/inertialDriver.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void stampa_misura_da_array(const lettura* arr)
{
    // stampa le 17 letture di una misura rappresentata come array stile C
    for (int i = 0; i < 17; i++)
    {
        cout << "lettura " << i << ": " << arr[i] << '\n';
    }
}

int main()
{
    cout <<"Tester RazzaPiave Inertial\n";

    InertialDriver d;   

    //------------ 1a misura--------------
    lettura mis1[17];
    for (int i = 0; i < 17; i++)
    {
		//valori esempio
        mis1[i] = lettura{i + 0.1, i + 1.1, i + 2.2, i + 3.3, i + 4.4, i + 5.5};
    }

    cout << "Push_back\n";
    d.push_back(mis1);

    cout << "\nStampa con operator<< (dovrebbe essere mis1):\n";
    cout << d << '\n';

    // --------------- getReading<-----------------------
    cout << "Test get_reading(0) sulla misura piu' recente:\n";
    try
    {
        lettura r0 = d.get_reading(0);
        cout << "get_reading(0): " << r0 << "\n\n";
    }
    catch (const std::out_of_range& e)
    {
        cout << "Eccezione out_of_range in get_reading(0)\n";
    }

    //  -------------Circolarità-------------------------
    cout << "Inserisco altre misure per testare il buffer circolare\n";
    for (int k = 0; k < 25; k++)   // 25 > BUFFER_DIM (20), quindi si verifica sovrascrittura
    {
        lettura mis[17];
        for (int i = 0; i < 17; i++)
        {
			mis[i] = lettura{k * 1.1 + i, k * 2.2 + i + 1, k * 3.3 + i + 2, k * 4.4 + i + 3, k * 5.5 + i + 4, k * 6.6 + i + 5};
        }
        d.push_back(mis);
    }

    cout << "\nStampa\n";
    cout << d << '\n';

    cout << "Test get_reading(4) sull'ultima misura:\n";
    try
    {
        lettura r4 = d.get_reading(4);
        cout << "get_reading(5): " << r4 << "\n\n";
    }
    catch (const std::out_of_range& e)
    {
        cout << "Eccezione out_of_range\n";
    }

    // ----------------pop_front()---------------------
    cout << "pop_front()\n";
    try
    {
        const lettura* arr = d.pop_front();
        cout << "Misura restituita da pop_front\n";
        stampa_misura_da_array(arr);
        cout << '\n';
    }
    catch (const std::underflow_error& e)
    {
        cout << "Eccezione underflow_error in pop_front: \n";
    }

    // ---------------clear_buffer------------------
    cout << "Svuoto il buffer con clear_buffer()\n";
    d.clear_buffer();

    cout << "pop_front()\n";
    try
    {
        d.pop_front();
        cout << "ERRORE: non è stata lanciata l'eccezione attesa!\n";
    }
    catch (const std::underflow_error& e)
    {
        cout << "Eccezione underflow_error catturata correttamente\n";
    }

    // --------------get_reading "sbagliato"---------------------
    cout << "\nTest get_reading con indice non valido (es. 20)\n";
    try
    {
        d.get_reading(20); // indice fuori da [0,16]
        cout << "ERRORE: non è stata lanciata l'eccezione out_of_range!\n";
    }
    catch (const std::out_of_range& e)
    {
        cout << "Eccezione out_of_range catturata \n";
    }

    cout << "\n--------------FINE--------------\n";
    return 0;
}
