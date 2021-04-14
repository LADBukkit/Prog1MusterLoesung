/*
 * Datum:           14.04.21
 * Author:          Robin Eschbach
 * Beschreibung:    Darstellungen eines Kalendars
 */

#include <stdio.h>

/**
 * Ein enum welches die Monate enthält und sie ihrer Zahl zwischen 1 und 12 zuweist.
 * C rechnet automatisch die Werte auf Basis der vorherigen Werte aus, weswegen nur
 * der Januar einen expliziten Wert benötigt.
 */
enum MONAT {
    JANUAR = 1, FEBRUAR, MAERZ,
    APRIL, MAI, JUNI,
    JULI, AUGUST, SEPTEMBER,
    OKTOBER, NOVEMBER, DEZEMBER
};

/**
 * Gibt die Anzahl der Tag in einem Monat wieder.
 * Hierbei wird nicht das enum verwendet, da in der Aufgabenstellung a)
 * explizit die Werte als Sprungmarker verwendet werden sollten.
 * 
 * Falls ein Monat der nicht zwischen 1 und 12 liegt übergeben wird,
 * so wird der Fehlerwert -1 wiedergegeben.
 */
int tageDesMonats(int monat) {
    switch(monat) {
        case 1: return 31;  // Das return bricht die Funktion ab und es wird deswegen kein break mehr benötigt.
        case 2: return 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return -1;
    }
}

/**
 * Gibt den Namen der übergebenen Monats auf der Konsole aus.
 * Hierbei wird das enum als Sprungmarke verwendet, da dies explizit in der Aufgabe steht.
 * 
 * Falls ein Monat der nicht zwischen 1 und 12 liegt übergeben wird, wird nichts ausgegeben.
 */
void monatAusgeben(int monat) {
    switch(monat){
        case JANUAR:
            printf("Januar");
            break;              // Das break verhindert ein durchfallen der Cases, da jeder Case der nach einem Zutreffenden
        case FEBRUAR:           // steht, automatisch auch Zutrifft.
            printf("Februar");
            break;
        case MAERZ:
            printf("Maerz");
            break;
        case APRIL:
            printf("April");
            break;
        case MAI:
            printf("Mai");
            break;
        case JUNI:
            printf("Juni");
            break;
        case JULI:
            printf("Juli");
            break;
        case AUGUST:
            printf("August");
            break;
        case SEPTEMBER:
            printf("September");
            break;
        case OKTOBER:
            printf("Oktober");
            break;
        case NOVEMBER:
            printf("November");
            break;
        case DEZEMBER:
            printf("Dezember");
            break;
    }
}

int main() {
    /**
     * Erklärung der Modulo Werte:
     * 0 % 7 = 0 R 0    Montag
     * 1 % 7 = 0 R 1    Dienstag
     * 2 % 7 = 0 R 2    Mittwoch
     * 3 % 7 = 0 R 3    Donnerstag
     * ...
     * 6 % 7 = 0 R 6    Sonntag
     * 7 % 7 = 1 R 0    Montag
     */

    // Der momentane Tag im Jahr (0 - 364)
    int tagImJahr = 0;

    for(int monat = 1; monat <= 12; monat++) {
        monatAusgeben(monat);
        printf("\n");

        // Die Anzahl an Tagen, die für die Einrückung übersprungen werden soll,
        // ist gleich dem Zahlenwert des momentanen Wochentages.
        int einrueckung = tagImJahr % 7;

        // Für jeden übersprungenen Tag wird ein \t ausgegeben.
        for(int i = 0; i < einrueckung; i++) {
            printf("\t");
        }

        int anzahlTage = tageDesMonats(monat);
        for(int tag = 1; tag <= anzahlTage; tag++) {
            // Bevor wir einen Montag ausgeben, soll in eine neue Zeile gegangen werden.
            if(tagImJahr % 7 == 0) {
                printf("\n");
            }
            printf("%i\t", tag);
            
            // Jeder Tag im monat zählt auch den tagImJahr hoch.
            tagImJahr++;
        }

        // Linebreaks nach Ausgabe des Monats.
        printf("\n\n");
    }

    return 0;
}