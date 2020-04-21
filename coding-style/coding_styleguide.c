/*
 * 1. Nach einem ; kommt eine neue Zeile, außer in Schleifenköpfen
 * 1. Der Code zwischen {} wird um einen Tabulator eingerückt
 * 1. {} brauchen Platz zum Atmen
 * 1. Arithmetische und logische Operatoren brauchen Platz zum Atmen
 * 1. Schlüsselwörter brauchen Platz zum Atmen
 * 1. Nach einer { folgt EINE neue Zeile
 * 1. } Stehen einzeln, außer es folgt ein else oder ein while
 * 1. Funktionen enden NICHT mit einer Leerzeile!!!
 * 1. Sinnabschnitte werden durch EINE Leerzeile getrennt
 *    => Sinnabschnitte sind nach gusto zu kommentieren
 * 1. Nach einem Komma folgt ein Leerzeichen
 *    => Ausnahme sind inkrement und dekrement Operatoren
 *
 * 0. Der Coding-Style muss konstant sein!
 *
 * Alle Regeln sind wichtig, deswegen gibt es keine Eindeutigkeit bei der Nummerierung
 *
 */

#include <stdio.h>

int power(int basis, int expo) {
	if (expo == 0) {
		return 1;
	}
	
	return basis * power(basis, expo - 1);
}

int fibo(int n) {
	if (n <= 2) {
		return 1;
	}
	
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	// Deklaration der Variablen
	int x = 0, y = 0;
	int i = 0;
	
	// Eingabe der Werte
	printf("Bitte geben Sie die Basisein:");
	scanf("%d", &x);
	printf("Bitte geben Sie den Exponenten ein:");
	scanf("%d", &y);
	
	// Berechnung der Potenz
	if (y < 0) {
		printf("Ungueltiger negativer Exponent.\n");
	} else {
		printf("Das Ergebnis ist %d\n", power(x, y));
	}
	
	// Berechnung der Fibonacci Zahlen von 1-10
	printf("\nDie Fibonacci-Folge der ersten zehn Zahlen lautet:\n");
	while (i < 10) {
		printf("%d,", fibo(i + 1));
		i++;
	}
	printf("...\n");
	
	return 0;
}