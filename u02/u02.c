/*
 * Author:			Robin Eschbach
 * Datum:			07.04.20
 * Beschreibung:	a) Summe der Zahlen 1 bis 42
 *					b) Summe der eingegebenen Ganzahlen
 *					c) Summe der eingegebenen Gleitkommazahlen
 */

#include <stdio.h>

int main() {
	// Aufgabe a)
	// Platzhalter fuer die Summe von 1-42
	int summe = 0;

	// Zaehlschleife von 1 bis einschliesslich 42
	for(int i = 1; i <= 42; i++) {
		// Addieren von der momentanen Zahl auf die Summe
		summe = summe + i;
	}
	printf("Die Summe von 1 bis 42 ist: %i\n", summe);


	// Aufgabe b)
	// Platzhalter fuer die Eingabe und der Summe auf der Eingabe (Ganzzahl)
	int eingabe = 0;
	int summeB = 0;
	
	do {
		printf("Geben Sie bitte eine Ganzzahl ein: ");
		
		// Einlesen der Ganzzahl
		scanf("%i", &eingabe);
		printf("Deine Zahl ist: %i\n", eingabe);

		// Bilden der Summe
		summeB += eingabe;
		printf("Das Zwischenergebnis ist: %i\n", summeB);
	} while(eingabe != 0);
	printf("Das Gesamtergebnis ist: %i\n", summeB);


	// Aufgabe c)
	// Platzhalter fuer die Eingabe und der Summer auf der Eingabe (Gleitkommazahl)
	double eingabeC = 0;
	double summeC = 0;

	do {
		printf("Geben Sie bitte eine Gleitkommazahl ein: ");
		
		// Einlesen der Gleitkommazahl		
		scanf("%lf", &eingabeC);
		printf("Deine Zahl ist: %g\n", eingabeC);
		// Bilden der Summe und Multiplikation mit dem Faktor 1.19		
		summeC += eingabeC * 1.19;
		printf("Das Zwischenergebnis ist: %g\n", summeC);
	} while(eingabeC != 0);
	printf("Das Gesamtergebnis ist: %g\n", summeC);
	

	return 0;
}
