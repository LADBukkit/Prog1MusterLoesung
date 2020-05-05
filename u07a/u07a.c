/*
 * Author:			Robin Eschbach
 * Datum:			05.05.2020
 * Beschreibung:		u07a - Zeichenketten Palindrome und Quersumme
 */

#include <stdio.h>

// Define für die Arraygrößen
#define WORD_SIZE 20
#define NUM_SIZE  10

void eingabe(char input[], int laenge) {
	char c;
	int i = 0;

	// Einlesen eines Zeichens in c. Abbruch wenn gleich EOF, oder i größer als die Länge ist.
	while((c = getchar()) != EOF && i < laenge) {
		input[i] = c;
		i++;
	}
	// Hinzufügen des Null-Bytes
	input[i] = '\0';
}

void makepali(char input[], char pali[]) {
	int a = 0;
	int i = 0;

	// Kopieren des inputs in pali
	// -- Möglich Kopf einer for-Schleife --
	// for(a = 0, i = 0; input[i] != '\0'; a++, i++) {
	while(input[i] != '\0') {
		pali[a] = input[i];
		a++;
		i++;
	}
	i--;

	// Rückwärts-anfügen des inputs an pali
	// -- Möglich Kopf einer for-Schleife --
	// for(; i >= 0; a++, i--){
	while(i >= 0) {
		pali[a] = input[i];
		a++;
		i--;
	}

	// Hinzufügen des Null-Bytes
	pali[a] = '\0';
}

int quersum(char quer[]) {
	// Variablen für Quersummenberechnung und Schleifendurchlauf
	int q = 0;
	int i = 0;
	
	// Durchlaufen, bis ein Null-Byte gefunden wurde.
	while(quer[i] != '\0') {	
		// Überprüfen, ob quer[i] ein Ziffernzeichen ist.
		if(quer[i] >= '0' && quer[i] <= '9') {
			// Hinzufügen des Ziffernwertes zu q.
			q += quer[i] - '0';
		}
		i++;
	}
	return q;
}

int main() {
	// Deklarierung der Arrays
	char wort[(WORD_SIZE) + 1];
	char pali[(WORD_SIZE) * 2 + 1];
	char numb[(NUM_SIZE) + 1];

	// Aufgabe a)
	printf("Geben Sie bitte ein Wort zur Palindrombildung ein: ");
	eingabe(wort, WORD_SIZE);
	makepali(wort, pali);
	printf("\nDas eingelesene Wort: %s\n", wort);
	printf("Das Palindrom: %s\n", pali);

	// Aufgabe b)
	printf("Geben Sie ein Wort zur Quersummenberechnung ein: ");
	eingabe(numb, NUM_SIZE);
	printf("\nDie Quersumme betraegt: %d\n", quersum(numb));

	return 0;
}
