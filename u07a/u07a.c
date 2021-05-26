/*
 * Author           Robin Eschbach
 * Datum            26.05.21
 * Beschreibung     Erkennung von Palindromen
 */
#include <stdio.h>
#include <stdbool.h>

// Ein rekursiver Ansatz der Palindromerkennung
bool isPaliRekursiv(char wort[], int a, int b) {
    if(a >= b) {                                // Falls a rechts von b ist, haben wir ein Palindrom gefunden,
        return true;                            // also das ganze Wort wurde abgearbeitet.
    }
    if(wort[a] != wort[b]) {                    // Wenn das wort and der Stelle a und b nicht übereinstimmt,
        return false;                           // SO ist dies kein Palindrom.
    }

    return isPaliRekursiv(wort, a + 1, b - 1);  // Wenn noch kein Palindrom gefunden wurde,
                                                // so gehen wir einen Schritt nach innen.
}

// Ein iterativer Ansatz der Palindromerkennung
bool isPali(char wort[], int a, int b) {
    while(a < b) {                  // Solange a links von b ist, so müssen wir noch Zeichen überprüfen.
        if(wort[a] != wort[b]) {    // Wenn das wort and der Stelle a und b nicht übereinstimmt,
            return false;           // SO ist dies kein Palindrom.
        }
        a++;                        // a inkrementieren und b dekrementieren,
        b--;                        // damit diese aufeinander zulaufen.
    }
    return true;                    // Sobald die while-Schleife abgearbeitet ist,
                                    // so haben wir ein Palindrom gefunden.
}

int main() {
    char wort[21];          // Array welches das eingelesene Wort hält
                            // (Die Länge des Arrays ist nicht laut Aufgabe festgesetzt)
    int laenge = 0;         // Platzhalter für die Länge des Wortes

    printf("Geben Sie bitte ein Wort zur Palindromerkennung ein: ");
    scanf("%20s", wort);    // Länge bei scanf muss mindestens einen kleiner sein, als die Länge des Arrays,
                            // damit auch immer ein Nullbyte hinten angefügt werden kann.

    // Berechnung der Länge des eingelesenen Wortes
    // Länge des eingelesenes Wortes == Position des Nullbytes
    while(wort[laenge] != '\0') {
        laenge++;
    }

    // Aufruf der isPali Funktion mit den Positionen des ersten und letzten Zeichens.
    if(isPali(wort, 0, laenge - 1)) {
        printf("\n%s ist ein Palindrom.\n", wort);
    } else {
        printf("\n%s ist kein Palindrom.\n", wort);
    }

    return 0;
}