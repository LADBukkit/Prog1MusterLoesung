/* 
 *  Zweck:   u04a - Uebungsaufgabe zu rekursiven Funktionen
 *  Autor:   David Lüdtke
 *  Datum:   21.04.2019
 */
#include <stdio.h>

int power(int basis, int exponent) {

    /* Abbruchbedingung: Exponent == 0, da x^0 immer 1 ergibt */
    if (exponent == 0) {
        return 1;
    }

    /* Sofern die Funktion bis hier kommt (exponent im derzeitigen Funktionsaufruf weder 0 noch < 0),
	 * eine Ebene tiefer gehen */
    return basis * power(basis, exponent - 1);
}

int fakul(int zahl) {

    /* Abbruchbedingung: zahl == 0 (Es wird runtergezählt, somit kommt man irgendwann bei 0 an) */
    if (zahl == 0) {
        return 1;
    }

    /* Definition der Fakutaetsfunktion: zahl * fakul(zahl -1) */
    return zahl * fakul(zahl - 1);
}

int fibo(int n) {

    /* Abbruchbedingung: Aktuelles n <= 2, da dann immer 1 das Ergebnis ist */
    if (n <= 2) {
        return 1;
    }

    /* Aus der Aufgabe entnommen: Die Definition fuer fibo(n) */
    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    //Variablen, die spaeter eingelesen / errechnet werden
    int base = 0;
    int expo = 0;
    int ergebnis = 0;
    int fakultaet = 0;

    //Aufgabe a)
    printf("Fakultaetsberechnung: ");
    scanf("%d", &fakultaet);
    printf("Fakultaet von %d ist %d\n", fakultaet, fakul(fakultaet));

    //Aufgabe b)
    printf("Geben Sie eine Basis ein: ");
    scanf("%d", &base);
    printf("Geben Sie einen Exponenten ein: ");
    scanf("%d", &expo);
    ergebnis = power(base, expo);
    printf("%d^%d = %d\n", base, expo, ergebnis);

    //Aufgabe c)
    for (int i = 1; i <= 10; i++) {
        printf("%d, ", fibo(i));
    }
    printf("...\n");
    
    return 0;
}