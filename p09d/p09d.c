/* Autor: Robin Freund
 * Datum: 02.06.2021
 * Zweck: Teilnehmerverwaltung
 * Hinweis: Wir schreiben hier u.U. *deutlich* ausfuehrlichere/redundantere Kommentare als ihr es muesst/sollt.
 *          Das dient teilweise rein zur Veranschaulichung bei den ersten Uebungen.
 *          Ihr muesst z.B. ueber eine Ausgabe nicht schreiben, dass es eine Schleife ist. Schreibt hier eher,
 *          wie die Schleife funktioniert - wenn es nicht selbstverstaendlich ist. Das selbe Prinzip bei Schleifen, Ausgaben,
 *          Funktionsaufrufen.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXELEM 100

struct Teilnehmer {
    char vorname[20];
    char nachname[20];
    char beruf[20];
    int tischNr;
};

void printMenu() {
    printf("\n> Du hast folgende Auswahlmoeglichkeiten:\n");

    printf("> Teilnehmerliste unsortiert anzeigen (u)\n");
    printf("> Teilnehmerliste nach Tischen sortiert anzeigen (s)\n");
    printf("> Neuen Teilnehmer erfassen (n)\n");
    printf("> Programm beenden (e)\n");
}

void printList(struct Teilnehmer liste[], int anzElem) {
    /* Ausgabe des Tabellenkopfes: Bis auf die Tischnummer nimmt jedes Wort mindestens 
     * 19 Zeichen, linksbündig mit Leerzeichen gefüllt, ein und legt damit die Breite
     * der "Tabelle" auf 19 Zeichen der ersten drei Spalten fest */
    printf("%-19s %-19s %-19s %s\n", "Vorname", "Nachname", "Beruf", "Tischnummer");

    for (int i = 0; i < anzElem; i++) {
        /* Wenn ein Element beim Iterieren die Tischnummer 0 hat, kann man davon ausgehen,
         * dass das das erste Element ist, das nicht von uns erzeugt wurde und die Liste als
         * beendet betrachten. */
        if (liste[i].tischNr == 0) {
            break;
        }

        /* Ausgabe des aktuellen Elementes, wieder mit 19 Zeichen Minimum pro "Spalte" */
        printf("%-19s %-19s %-19s %d\n", liste[i].vorname, liste[i].nachname, liste[i].beruf, liste[i].tischNr);
    }
}

void printListSorted(struct Teilnehmer liste[], int anzElem) {
    printf("%-19s %-19s %-19s %s\n", "Vorname", "Nachname", "Beruf", "Tischnummer");

    /* Ausgabe von zuerst Tisch 1, 2, 3 und dann 4 .. */
    for (int tischNr = 1; tischNr <= 4; tischNr++) {    
        /* .. wofür jedes Element einzeln geprüft werden muss. */
        for (int i = 0; i < anzElem; i++) {
            if (liste[i].tischNr == 0) {
                break;
            }

            if (tischNr == liste[i].tischNr) {
                printf("%-19s %-19s %-19s %d\n", liste[i].vorname, liste[i].nachname, liste[i].beruf, liste[i].tischNr);
            }
        }
    }
}

void addTeilnehmer(struct Teilnehmer liste[], int anzElem) {
    int i = 0;
    /* Suche das erste Element, das leer ist.. */
    for (i = 0; i < anzElem; i++) {
        if (liste[i].tischNr == 0) {
            break;
        }
    }

    /* .. und beginne an dieser Stelle dann, die neuen Daten zu füllen. */
    /* Achtung: Mit scanf ist eine Eingabe von Daten mit Leerzeichen nicht vernünftig möglich. */
    printf("> Bitte neuen Teilnehmer eingeben\n");
    printf("> Vorname: ");
    scanf("%s", liste[i].vorname);
    printf("> Nachname: ");
    scanf("%s", liste[i].nachname);
    printf("> Beruf: ");
    scanf("%s", liste[i].beruf);

    liste[i].tischNr = rand() % 4 + 1;
    printf("> Der Teilnehmer hat Tisch %d zugewiesen bekommen.\n", liste[i].tischNr);
}

int main () {
    /* Variable zum Halten der späteren Benutzereingabe im Menü */
    char input = '\0';

    /* Initialisieren des Zufallszahlengenerators */
    srand(time(NULL));

    printf("========= Speed Networking =========\n");
    printf("Hallo! Dieses Programm dient der Verwaltung von Teilnehmern dieses Events.\n");

    /* Initialisierung der ersten sechs Elemente.
     * Alle Elelmente, die in der Liste nicht explizit initialisiert werden, sind
     * automatisch mit Nullwerten initialisiert. */
    struct Teilnehmer teilnehmerListe[MAXELEM] = {
        {"Horst", "Hose", "Schneidermeister", rand() % 4 + 1},
        {"Roman", "Rohrfrei", "Wasserinstallateur", rand() % 4 + 1},
        {"Paula", "Planlos", "Architektin", rand() % 4 + 1},
        {"Armin", "Gips", "Stuntman", rand() % 4 + 1},
        {"Nora", "Notfall", "Nachtschwester", rand() % 4 + 1},
        {"Stella", "Standup", "Fitnesstrainerin", rand() % 4 + 1},
    };

    do {
        printMenu();

        /* Um einen Zeilenumbruch nicht ebenfalls als Eingabe zu erfassen: 
         * Lese Zeichen für Zeichen ein, aber ignoriere Leerraumcharaktere (durch das Leerzeichen am Anfang)
         * (z.B. Leerzeichen, Tab und besonders Zeilenumbrüche - siehe man scanf / man 3 isspace für mehr) */
        scanf(" %c", &input);

        switch (input) {
            case 'u':
                printList(teilnehmerListe, MAXELEM);
                break;
            case 's':
                printListSorted(teilnehmerListe, MAXELEM);
                break;
            case 'n':
                /* Füge Teilnehmer hinzu und lasse die Funktion selbst entscheiden, wo.
                 * Alternative: Hier in der main()-Funktion mitzählen, wie viele Teilnehmer erfasst wurden
                 * und diese Zahl als Neuanlage-Index übergeben. */
                addTeilnehmer(teilnehmerListe, MAXELEM);
                break;
            case 'e':
                printf("Das Programm wird beendet.\n");
                break;
        }
    /* Führe Schleife nur solange aus, bis der Nutzer 'e' drückt. */
    } while (input != 'e');

    return 0;
}