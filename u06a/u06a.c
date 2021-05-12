/* C-Programm - Aufgabe u06a Numerik
* Name: Maren Franke
* Datum: 12.05.2021
* Inhalt:
*		a) Umwandlung eines eingegebenen Char in einen Int
*		b) Umwandlung eines eingegebenen Char in einen Double
*/

#include <stdio.h>
#include <limits.h>			// fuer die Verwendung von INT_MAX
#include <stdbool.h>		// fuer die Verwendung von Wahrheitswerten (bool)

		
int makeInt(char c) {
	/* Statische Variable zur Speicherung der Werte über die Funktionsgrenze hinweg */
	static int zahl = 0;
	
	/* Umwandlung des Char in einen Integer durch die Subtraktion mit '0' */
	int ci = (c - '0');
	
	/* Komplexe Variante zum Abfangen des Integer-Überlaufs 
	* 1.Teil: (zahl > (INT_MAX / 10))
	*	- Sicherstellung, dass die Zahl, wenn man sie mit 10 Multiplizieren würde, nicht größer als die maximale 
	*	  Integer-Zahl ist
	*	- zahl darf daher (da es im Programm mit 10 Multipliziert würde) nicht größer als INT_MAX / 10 sein
	* 2.Teil: (zahl == (INT_MAX / 10) && ci > INT_MAX % 10)
	* 	- INT_MAX / 10 = 2147483647 / 10 = 214748364
	*   - Wenn die Zahl diesen Wert hat, wird sie nicht von Teil 1 abgefangen
	*   - Problem ergibt sich, wenn 214748364 * 10 = 2147483640 gerechnet wird und im nächsten Schritt eine Zahl
	*     addiert wird, die einen Wert größer als 7 (INT_MAX % 10) hat
	*   - Daher wird verhindert, dass die Zahl einen Überlauf hat
	*/
	if(zahl > (INT_MAX / 10) || (zahl == (INT_MAX / 10) && ci > INT_MAX % 10)) {
		printf("Integer wird zu groß! \n");
		return zahl;
	}
	
	/* Alternative (auch absolut gültige) Variante zum Abfangen des Integer-Überlaufs 
	*	- Idee: Abfangen von Werten, die einen Ganzzahlüberlauf erzeugen würden (kleiner als 0)
	*/
	/*if((zahl * 10) + ci < 0) {
		printf("Integer wird zu groß! \n");
		return zahl;
	}*/
	
	
	/* Zuerst Verschiebung der Zahl um eine 10er Stelle und daraufhin Addition von der Zahl ci */
	zahl = (zahl * 10) + ci;
	
	return zahl;
}

double makeDouble(char c) {
	/*Definition von verschiedenen Variablen*/
	static double zahl = 0.0;
	static bool vorKomma = true;
	static double divi = 0.1;
	
	
	/* Abfangen des ".", sobald ein Punkt eingeben wird, wird der bool vorKomma "aktiviert" */
	if(c == '.') {
		vorKomma = false;
		return zahl;
	}
	
	/* Umwandlung des charakters in einen Double durch die Subtraktion mit '0' und Casting auf Double*/
	double ci = (double)(c - '0');
	
	/* Unterscheidung der Fälle, wenn wir vor und nach dem Komma sind */
	if(vorKomma) {
		/* Betrachtung der Stellen vor dem Komma; Rechnung analog zur Rechnung in makeInt() */
		zahl = (zahl * 10.0) + ci;
	}
	else {
		/* Betrachtung der Stellen nach dem Komma
		* 	- Multiplikation des neu eingegebenen Zeichens mit einer Vordefinierten Zahl divi
		*	- Divi ist zu Beginn 0.1 und wird immer durch 10 dividiert um zu erreichen, dass die Zahl immer
		*     mit dem richtigen Wert verrechnet wird:
		*	- Beispiel:
		*		Eingabe von 123.123 -> 123. wird von if(vorKomma)... bearbeitet; Verarbeitung von .123:
		*			zahl = 123 + 1 * 0.1	= 123.1		=> divi war 0.1
		*			zahl = 123.1 + 2 * 0.01	= 123.12	=> divi war 0.01
		* 			zahl = 123.12 + 3 * 0.001	= 123.12	=> divi war 0.001
		*		
		*/
		zahl = zahl + ci * divi;
		divi = divi / 10;
	}

	return zahl;
}


int main() {
	/* Definition der Variablen und erste Wertzuweisungen */
	char c;
	int ergebnisInt = 0;
	double ergebnisDouble = 0.0;
	
	/* Einlesen einer Zahl vom Benutzer */
	printf("Bitte eine Zahl eingeben: ");
	do {
		c = getchar();
		
		/* Abfangen von allen Zeichen, außer den Ziffern + Aufruf der Funktion makeInt(c) */
		if(c >= '0' && c <= '9') {
			ergebnisInt = makeInt(c);
		}
		
		/* Abfangen von allen Zeichen, außer den Ziffern & des Punkts + Aufruf der Funktion makeDouble(c) */
		if((c >= '0' && c <= '9') || c == '.') {
			ergebnisDouble = makeDouble(c);
		}
	
	} while(c != EOF);

	
	/* Ausgaben der erzeugten Zahlen */
	printf("Die Zahl ist (int): %i \n", ergebnisInt);
	printf("Die Zahl ist (double): %lf \n", ergebnisDouble);
	
	/* %19.18E -> 19 Stellen insgesamt, 18 Stellen nach dem Komma und in wissenschaftlicher Schreibweise */
	printf("Die Zahl ist (double): %19.18E \n", ergebnisDouble);

	return 0;
}






