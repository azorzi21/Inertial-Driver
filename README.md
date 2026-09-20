# Inertial-Driver
LABORATORIO DI PROGRAMMAZIONE
PROGETTO INTERMEDIO
Gruppo: Razza Piave
Cescon Alessandro - Mazzola Thomas - Zorzi Alessandro


PRECISAZIONI SULLE SCELTE PROGETTUALI
Assenza di metodi setter:
Si assume che le letture fornite al sistema non vengano modificate dopo l’acquisizione. 
Per questo motivo non sono stati previsti metodi setter per sovrascrivere i singoli valori delle letture (es. yaw, v, ecc.).

Classe misura
Sebbene la classe InertialDriver accetti in input un array in stile C, si è scelto di utilizzare un contenitore dedicato per le 17 letture. 
Questo permette di definire e gestire più agevolmente le funzioni associate alle misure.



SUDDIVISIONE ARGOMENTI
CESCON
	progettazione classe InertialDriver
	implementazione delle funzioni di InertialDriver

MAZZOLA 
	implementazione delle funzioni delle classi misura e lettura
	implementazione costruttori di tutte e 3 le classi

ZORZI
	revisione classe MyVector
	Implementazione dell’operatore operator<< delle tre classi
	Organizzazione struttura generale del progetto (suddivisione in lettura, misura, InertialDriver ecc.)
	Scrittura file tester



