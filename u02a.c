/*
Name: Macedo da Silva, bruno
Datum: 7.4.2021
Aufgabe: u02a - numerischen Datentypen und Schleifen


Skizze
a- 
for (int i = 1  i <= 42) a 1 bis 42
     a = a + i

b- 
 Loop Benutzer_einige != 0
    summe_2 = summe_2 + Benutzer_einige + 
Ausgabe Summe_2

c-
Loop benutzer != 0
    ergebnis +=  eingabe * 1.19
    //ergebnis = ergenibs +  eingabe * 1.19
Ausgabe ergebnis

*/

#include <stdio.h>

int main () {

    int summe = 0, i = 0;
    int benutzer_eingabe_1 = 0, summe_2 = 0;
    double eingabe_3 = 0.0, ergebnis_3 = 0.0;

    /*
    Dieses Teil gehoert nicht zur Aufgabe. Es war aber benutzt, um zu verstehen, 
    wie pre- und posoperator funktionieren

    ++i = Zuerst wird die Zahl erhoet, dann wird die Variable benutzt, 
    dann geht es zu der naechsten Anweisung.

    i++ = Der originale Wert wird benutzt, danach wird es erhoeht.
    */

    if (++i == 0) {
        printf("Ich bin true\n");
    } else {
        printf("Ich bin false\n");
    }
    printf("Neue i = %d\n", i);

    /*
    Teil a
    For-Schleife mit einem Sprung 1. Die Zwischensumme wird der in Variable Summe gespeichert
    */
    for (i = 1; i <= 42; ++i) {
        summe = summe + i;
    }
    printf("Summe = %d\n", summe); 

    /*
    Teil b
    do-while-Schleife wurde hier und in Teil c verwendet, damit unser Code mindestens einmal ausgefuhert wird,
    bevor er die Bedingung ueberprueft.
    Die Ausgabe ist auch so gestaltet, dass wir jedes Zwischenergebnis beobachten koennen
    */
    do {  
        printf("Geben Sie eine Zahl ein: ");
        scanf("%d", &benutzer_eingabe_1);
        printf("Zwischen: %d + %d = %d\n", benutzer_eingabe_1, summe_2, summe_2 + benutzer_eingabe_1);
        summe_2 = summe_2 + benutzer_eingabe_1;
    } while (benutzer_eingabe_1 != 0);
    printf("Summe Total = %d\n\n", summe_2); 

    /*
    Teil c
    */
    do {
        printf("Geben Sie eine Zahl ein: ");
        scanf("%lf", &eingabe_3);
        printf("Zwischen: %lf * 1.19 + %lf = %lf\n", eingabe_3, ergebnis_3, ergebnis_3 + eingabe_3 * 1.19);
        ergebnis_3 += 1.19 * eingabe_3;
    } while (eingabe_3 != 0.0); 
    printf("\nErgebnis 3 = %lf\n", ergebnis_3); 
  
    return 0;
}