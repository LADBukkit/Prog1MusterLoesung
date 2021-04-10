/* 
 * Autor: Katrin Vollhardt
 * Datum: 7.4.21
 * Zweck: Zeichenzaehler einer Eingabe
 * Hinweis: Wir schreiben hier u.U. *deutlich* ausfuehrlichere/redundantere Kommentare als ihr es muesst/sollt.
 *          Das dient teilweise rein zur Veranschaulichung bei den ersten Uebungen.
 *          Ihr muesst z.B. ueber eine Addition nicht schreiben, dass es eine Addition ist. Schreibt hier eher,
 *          warum ihr addiert - wenn es nicht selbstverstaendlich ist. Das selbe Prinzip bei Schleifen oder Variablen.
 */

#include <stdio.h>

int main () {
    
    /* Zeichen-Zwischenspeicher */
    char eingabe;

    /* Zaehler für Zeichengruppen*/
    int counter = 0;
    int grossb = 0;
    int kleinb = 0;
    int ziffernb = 0;
    int steuerb = 0;
    int rest = 0;

    /* Fussgesteuerte Schleife - erster Durchlauf wird immer durchgefuehrt */
    /* Hier: Da erst Eingabe gelesen werden soll, damit diese für die Abbruchbedingung
     * zur Verfügung steht. */
    do {
        /* Zeichen aus stdin lesen und auf eingabe speichern,
         * Liegen mehrere Zeichen im Strom, wird hier nur das zuerst eingegebene Zeichen genommen. */
        eingabe = getchar();

        /* Insgesamt gelesene Zeichenanzahl um eins erhöhen;
         * entspricht counter = counter + 1 */
        counter++;

        /* Ist das aktuelle Zeichen ein Grossbuchstabe...*/
        if (eingabe >= 'A' && eingabe <= 'Z') {
            grossb++; /* den entsprechenden Zaehler erhoehen */
        } else if (eingabe >= 'a' && eingabe <= 'z') { /* ansonsten, aber *nur* wenn Kleinbuchstabe */
            kleinb++; /* den entsprechenden Zaehler erhoehen */
        } else if (eingabe >= '0' && eingabe <= '9') {
            ziffernb++;
        } else if (eingabe < ' ') {
            steuerb++;
        } else { /* Wenn *kein* anderer Fall zutrifft, ist es ein "anderer Buchstabe". */
            rest++;
        }

        /* Das eingelesene Zeichen wieder ausgeben */
        putchar(eingabe);

    /* Schleife wird durchgefuehrt, bis Strg+D gedrueckt wird
     * Hierbei springt der Code immer wieder zum Anfang der Schleife (Zeile 26), bis die
     * Abbruchbedingung (eingel. Zeichen = EOF) erfuellt ist. 
     */
    } while (eingabe != EOF);

    printf("\nAnzahl der Zeichen: %i\n", counter);
    
    printf("Anzahl der Grossbuchstaben: %i\n", grossb);
    printf("Anzahl der Kleinbuchstaben: %i\n", kleinb);
    printf("Anzahl der Ziffernbuchstaben: %i\n", ziffernb);
    printf("Anzahl der Steuerzeichen: %i\n", steuerb);
    printf("Anzahl der anderen Zeichen: %i\n", rest);

    return 0;
}