/* u05a.c
 * Autor: David Luedtke
 * Datum: 28.04.2021
 */
 
#include <stdio.h>
 
// Funktion zur Berechnung der Potenz: x^y
double power(int x, int y) {
	// Beachtung von negativen Exponenten: x^(-y) = 1 / (x^y)
	if (y < 0) {
 		return 1 / power(x, -y);
 	}
 	
 	// Abbruchbedingung: x^0=1
 	if (y == 0) {
 		return 1;
 	}
 	
 	// x * (x^(y-1));
 	return x * power(x, y - 1);
}

// Funktion zur Berechnung der Summe von: 2 * i + 1
int summe(int i) {
	// Abbruchbedingung
	if (i <= 0) {
		return 0;
	}
	
	return summe(i - 1) + (2 * i + 1);
}
 
int main() {
	// Aufgabenteil a)
	int x = 0, y = 0;
 	
 	printf("Bitte gib eine Basis ein: ");
 	scanf("%d", &x);
 	printf("Bitte gib einen Exponenten ein: ");
 	scanf("%d", &y);
 	
 	double ergebnis = power(x, y);
 	printf("Das Ergebnis von %d^%d ist %lf\n", x, y, ergebnis);
 	
 	// Aufgabenteil b)
	int n = 0;
	printf("Geben Sie n zur Berechnung der Summe ungerader Zahlen ein: ");
	scanf("%d", &n);
	
	int ergebnisSumme = summe(n);
	if (ergebnisSumme != 0) {
		printf("Das Ergebnis lautet: %d\n", ergebnisSumme);
	} else {
		printf("Berechnung von n <= 0 nicht moeglich!\n");
 	}
 	return 0;
}
