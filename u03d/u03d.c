/*
 * Author           Robin Eschbach
 * Datum            28.04.21
 * Beschreibung     Quersummenbildung anhand des Eingabestroms
 */

#include <stdio.h>

int quersum(char c) {
    static int summe = 0;       // Ein statische Variable behält über das Funktionsende ihren Wert
                                // sie wird nur 1 mal initialisiert => Beim ersten Funktions Aufruf
    summe += c - '0';           // Herunterrechnen des ASCII Bereiches von '0' => '9' (48 => 57) auf
                                // Den Bereich 0 => 9 durch subtrahieren von '0' (48)
    return summe;
}

int main() {
    char eingabe = '\0';
    int quersumme = 0;

    printf("Geben Sie Ziffern zur Quersummenberechnung ein (Abbruch mit EOF):\n");

    do {
        eingabe = getchar();                            // Eingabe und Ausgabe der gelesenen Zeichen
        putchar(eingabe);

        if(eingabe >= '0' && eingabe <= '9') {          // Ab hier werden nur Ziffern betrachtet, also der Bereich von '0' => '9' (48 => 57)
            quersumme = quersum(eingabe);               // Zwischenspeichern der momentanen Quersumme
        }
    } while(eingabe != EOF);                            // Abbruch der Eingabe mit EOF

    printf("\nDie Quersumme ist: %i\n", quersumme);

    return 0;
}