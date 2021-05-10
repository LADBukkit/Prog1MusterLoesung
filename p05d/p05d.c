/**
 * Name: Luca Chiarelli
 * Datum: 05.05.2021
 * Beschreibung: Ein Programm, welches Primzahlen bestimmen kann und diese Als Paare
 *                  Ausgeben kann. Ebenfalls werden noch Sophie-Germain Primzahlen ausgegeben
 *                  und der Primfaktor einer natuerlichen Zahl errechnet. 
*/
#include <stdio.h> 
#include <stdbool.h> 


// Hilfsfunktion fuer saubere Ausgaben :)
void clear() {
    printf("\n\n\n");
}

bool isPrim(int zahl) {

    // Static, damit der Wert auch nach Aufruf der Funktion im Speicher erhalten bleibt.
    static int teiler = 2; 

    // Abbruchkriterium, da es ab hier keine sinnvollen Teiler mehr gibt.
    if(teiler > zahl / 2) {
        // Den Teiler hier fuer den beginn eines neuen Aufrufs wieder auf '0' setzen. 
        teiler = 2;

        return zahl > 1; 
    }

    // Ist die uebergebene Zahl mit dem Teiler restlos teilbar ist hier schluss.
    if(zahl % teiler == 0) {
        teiler = 2; 

        return false; 
    } 
    else {
        // Teiler erhoehen fuer den naechsten Aufruf der Funktion.
        teiler++; 

        return isPrim(zahl);
    }
}

void doPFZ(int zahl, int teiler) {

    // Wenn es sich bereits um eine Primzahl handelt koennen wir beenden, da ab hier nicht mehr teilbar ist.
    if(isPrim(zahl)) {
        printf("%i\n", zahl);
        return;
    }

    // Wenn Zahl durch Teiler restlos teilbar ist, dann
    if(isPrim(teiler) && zahl % teiler == 0) {
        printf("%i, ", teiler);
        // rekursiver Aufruf der Funktion mit der dividierten Zahl
        return doPFZ(zahl/teiler, teiler);
    }

    // Falls Zahl nicht restlos durch Teiler teilbar ist, dann wird der Teiler solange erhoeht, bis die Zahl restlos teilbar ist oder der Teiler
    // keine Primzahl ist. 
    return doPFZ(zahl, teiler + 1);
}

int main() {

    int max = 0; 
    int i = 0;
    printf("Bitte geben Sie eine Obergrenze an: "); 
    scanf("%i", &max);

    // Aufgabenteil a) Primzahlen als Paare ausgeben
    printf("Ausgabe der Primzahlenpaare: \n");
    for(i = 0; i < max-1; i++) {
        // Primzahl       Primzahl + 2
        if(isPrim(i) && isPrim(i + 2)) {
            printf("(%i %i) ", i, i + 2);
        }
    }

    clear();

    // Aufgabenteil b)
    printf("Ausgabe der SG-Primzahlen: \n");
    for(i = 0; i < max; i++) {
        // Formel fuer SG-Primzahlen: 2 * p + 1
        if(isPrim(i) && isPrim(2 * i + 1))
            printf("%i ", i);
    }

    clear();

    // Aufgabenteil c) 
    int pfz = 0;
    printf("Bitte geben Sie eine Zahl zur PFZ ein: ");
    scanf("%i", &pfz);

    // Teiler mit 2 beginnen, wird dann in der Funktion schrittweise erhoeht. 
    doPFZ(pfz, 2);

    return 0;
}