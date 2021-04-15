/*
 * 1. Nach einem ; kommt eine neue Zeile bzw. Anweisungen stehen alleine auf einer eigenen Zeile
 * 1. Der Code innerhalb von Blöcken wird um die jeweilige Ebene eingerückt
      (oder anders: Alles zwischen {} wird um einen Tabulator/4 Leerzeichen eingerückt)
 * 1. {} brauchen Platz zum Atmen
 * 1. Arithmetische und logische Operatoren brauchen Platz zum Atmen
 *    ==> Unäre Operatoren (z.B. i++) haben explizit keinen Platz zum Atmen
 * 1. Schlüsselwörter brauchen Platz zum Atmen
 * 1. Nach einer { folgt EINE neue Zeile
 * 1. } Stehen einzeln, außer es folgt ein else oder ein while
 * 1. Funktionen enden nicht mit einer Leerzeile, wenn sie nicht mit einer anfangen
      ==> Eine Leerzeile ist so oder so das Maximum
 * 1. Sinnabschnitte werden durch EINE Leerzeile getrennt
 *    ==> Sinnabschnitte sind nach gusto zu kommentieren
 *
 * 0. Der Coding-Style muss konstant sein!
 *
 * Alle Regeln sind wichtig, deswegen gibt es keine Eindeutigkeit bei der Nummerierung
 *
 */

#include <stdio.h>

int main()
{
    int eingabe = 0;
    int produkt = 1;
    int eingegebeneZahlen = 0;

    printf("> Bitte geben Sie Ganzzahlen ein, aus allen Zahlen wird am Ende ein Produkt gebildet!\n");
    printf("> Mit der Eingabe einer 0 kann das Programm beendet werden.\n");
    do
    {
        printf("> Bitte geben Sie eine Zahl ein: ");

        scanf("%d", &eingabe);
        printf("\nDie eingegebene Zahl: %d\n", eingabe);

        eingegebeneZahlen++;
        if (eingabe == 0)
        {
            printf("Das Endergebnis: %d", produkt);
            printf("Anzahl eingelesener Zahlen: %d\n", eingegebeneZahlen);
            break;
        }

        switch (eingabe)
        {
            case 42:
                produkt *= -1;
                break;
            case 100:
                printf("BINGO\n");
                produkt *= 1000;
                break;
            case 1:
                printf("NOPE\n");
                produkt = 1;
                break;
            default:
                produkt *= eingabe;
        }

        printf("Zwischenergebenis: %d\n", produkt);
    } while (eingabe != 0);

    return 0;
}