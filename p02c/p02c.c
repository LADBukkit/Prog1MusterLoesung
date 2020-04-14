/* Zweck: p02c - Bewertungsaufgabe zu Zeichen und Schleifen
 * Autor: Robin Freund
 * Datum: 14.04.2020
 * Hinweis: Wir schreiben hier u.U. *deutlich* ausfuehrlichere/redundantere Kommentare als ihr es muesst/sollt.
 *          Das dient teilweise rein zur Veranschaulichung bei den ersten Uebungen.
 *          Ihr muesst z.B. ueber eine Addition nicht schreiben, dass es eine Addition ist. Schreibt hier eher,
 *          warum ihr addiert - wenn es nicht selbstverstaendlich ist. Das selbe Prinzip bei Schleifen oder Variablen.
 */

#include <stdio.h>

int main()
{
    /* Zwischenspeicher fuer Zeichen im Schleifendurchgang */
    char c;

    /* Zaehler für Gruppen der Zeichen */
    int alleZeichen = 0;
    int grossBuchst = 0, kleinBuchst = 0, ziffernBuchst = 0, andereBuchst = 0;

    /* Zaehler fuer jeweils aktuelle Quersumme */
    int quersumme = 0;

    printf("Bitte geben Sie Zeichen ein: \n");

    /* Fussgesteuerte Schleife - erster Durchlauf wird immer durchgefuehrt */
    do
    {
        /* Liest das naechste Zeichen, das in den Eingabestrom geschrieben wurde
         * und speichert es in c. Liegen mehrere Zeichen im Strom, wird hier nur
         * das zuerst eingegebene Zeichen genommen.
         */
        c = getchar();

        /* Gleichbedeutend: alleZeichen++; */
        alleZeichen = alleZeichen + 1;

        /* Wenn das aktuelle Zeichen ein Grossbuchstabe ist.. */
        if (c >= 'A' && c <= 'Z')
        {
            grossBuchst++; /* ..den entsprechenden Zaehler um eins erhoehen .. */
        }
        else if (c >= 'a' && c <= 'z') /* .. ansonsten, aber *nur* wenn Kleinbuchstabe .. */
        {
            kleinBuchst++; /* .. erhoehe Zaehler fuer Kleinbuchstaben. */
        }
        else if (c >= '0' && c <= '9')
        {
            ziffernBuchst++;

            /* Ziehe ASCII-Wert von '0' (Konstante, steht fuer die Zahl 48) vom 
             * uebergebenen Zeichen ab und speichere Ergebnis in "ziffer" - hierdurch 
             * wird mit der "echten" Zahl gerechnet und nicht ihr ASCII-Wert 
             */
            quersumme = quersumme + (c - '0');
        }
        else
        {
            /* Wenn *kein* anderer Fall zutrifft, ist es ein "anderer Buchstabe". */
            andereBuchst++;
        }

        putchar(c);

        /* Schleife wird durchgefuehrt, bis Strg+D gedrueckt wird
         * Hierbei springt der Code immer wieder zum Anfang der Schleife (Zeile 33), bis die
         * Abbruchbedingung erfuellt ist. 
         */
    } while (c != EOF);

    printf("Gesamtanzahl an Zeichen: %d\n", alleZeichen);
    printf("Anzahl Grossbuchstaben: %d\n", grossBuchst);
    printf("Anzahl Kleinbuchstaben: %d\n", kleinBuchst);
    printf("Anzahl Ziffern: %d\n", ziffernBuchst);
    printf("Anzahl anderer Zeichen: %d\n", andereBuchst);
    printf("Quersumme: %d\n", quersumme);

    return 0;
}