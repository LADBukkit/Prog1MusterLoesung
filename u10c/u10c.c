/*
 * Author:  Robin Eschbach
 * Datum:   09.06.21
 * Zweck:   Stauverwaltung mit verketteten Listen
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Die Nummer 0 als struct Node Zeiger,
// um nicht-existierende Nodes darzustellen.
#define NIL ((struct Node*) 0)

// Die Länge der Strings.
#define STR_LEN (21)

// Ein Fahrzeug struct mit allen elementen.
struct Fahrzeug {
    char hersteller[STR_LEN];
    char modell[STR_LEN];
    char kennzeichen[STR_LEN];
    int personen;
};

// Der Kontainer für die Listenverkettung.
// next muss ein Zeiger sein, da ein struct keine variablen des eigenen Typs enthalten kann.
struct Node {
    struct Fahrzeug content;
    struct Node* next;
};

void anhaengen(struct Node** current) {
    // Bis zum letzten Element vorgehen.
    while(*current != NIL) {
        current = &((*current)->next);
    }

    // Neues Element erzeugen.
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    // Da das neue Element am Ende ist, kommt danach nichts mehr.
    newNode->next = NIL;

    // Einlesen der Werte des structs.
    // %20[^\n] liest all zeichen außer das linebreak ein.
    printf("\nHersteller: ");
    scanf(" %20[^\n]", newNode->content.hersteller);
    printf("Modell: ");
    scanf(" %20[^\n]", newNode->content.modell);
    printf("Kennzeichen: ");
    scanf(" %20[^\n]", newNode->content.kennzeichen);
    printf("Anzahl Personen: ");
    scanf(" %i", &(newNode->content.personen));

    // Da unser current momentan auf das NIL am Ende der Liste zeigt,
    // ersetzen wir es mit unserem neuen Element.
    *current = newNode;
}

void anzeigen(struct Node* current) {
    // Der Tabellenkopf (20 Zeichen pro String und linksbündig)
    printf("\n%-20s %-20s %-20s %s\n", "Hersteller", "Modell", "Kennzeichen", "Personen");

    // Bis zum Ende der Schleife wiederholen:
    while(current != NIL) {
        // Element ausgeben.
        printf("%-20s %-20s %-20s %i\n", current->content.hersteller, current->content.modell, current->content.kennzeichen, current->content.personen);
        // Zum nächsten Element gehen.
        current = current->next;
    }
}

void stauAufloesen(struct Node* current) {
    // So lange rekursiv weitergehen, bis das Ende der Liste erreicht ist.
    if(current->next != NIL) {
        stauAufloesen(current->next);
    }
    // Von hinten anfangend auflösen.
    free(current);
}

void ausklinken(struct Node** current, struct Node** ausgeklinkt) {
    // Fehlermeldung fals schon ausgeklinkt
    if(*ausgeklinkt != NIL) {
        printf("Es wurde schon ein Fahrzeug ausgeklinkt. Bitte klinken Sie es zuerst wieder ein!\n");
        return;
    }

    // Einlesen des Kennzeichens
    char kennzeichen[STR_LEN];
    printf("Geben Sie das Kennzeichen fuer das Fahrzeug ein, welches Ausgeklinkt werden soll:\n");
    scanf(" %20[^\n]", kennzeichen);

    // Bis zu dem Kennzeichen vorgehen und den Vorgänger mitspeichern.
    struct Node* old = *current;
    while(*current != NIL && strcmp(kennzeichen, (*current)->content.kennzeichen) != 0) {
        old = *current;
        current = &((*current)->next);
    }

    // Wenn das Kennzeichen nicht gefunden wurde einen Fehler ausgeben.
    if(*current == NIL) {
        printf("Es wurde kein Fahrzeug mit diesem Kennzeichen gefunden!\n");
    } else {
        // Den gefundenen auf ausgeklinkt setzen
        *ausgeklinkt = *current;
        if(old == *current) {
            // Falls das erste Element ausgeklinkt werden soll,
            // wirde der Listenkopf einen weitergeschoben.
            *current = (*current)->next;
        } else {
            // ansonsten wird das gefundene Element nun übersprungen
            old->next = (*current)->next;
        }
        (*ausgeklinkt)->next = NIL;
    }
}

void einklinken(struct Node** current, struct Node** ausgeklinkt) {
    // Wenn noch nicht ausgeklinkt wurde dann Fehler ausgeben.
    if(*ausgeklinkt == NIL) {
        printf("Es wurde noch kein Fahrzeug ausgeklinkt. Bitte klinken Sie zuerst aus!\n");
        return;
    }

    // Kennzeichen einlesen
    char kennzeichen[STR_LEN];
    printf("Geben Sie das Kennzeichen fuer das Fahrzeug ein, hinter dem eingeklinkt werden soll:\n");
    scanf(" %20[^\n]", kennzeichen);

    // Bis zu diesem Kennzeichen vorgehen.
    while(*current != NIL && strcmp(kennzeichen, (*current)->content.kennzeichen) != 0) {
        current = &((*current)->next);
    }

    // Wenn das Kennzeichen nicht gefunden wurde, dann Fehler ausgeben.
    if(*current == NIL) {
        printf("Es wurde kein Fahrzeug mit diesem Kennzeichen gefunden!\n");
    } else {
        // Ansonsten das Element zwischen dem gefundenem und dem folgendem einklinken.
        (*ausgeklinkt)->next = (*current)->next;
        (*current)->next = *ausgeklinkt;
        *ausgeklinkt = NIL;
    }
}

int main() {
    // Variablen für die Menüeingabe, den Stau und das Ausgeklinkte Element.
    char menu = '\0';
    struct Node* stau = NIL;
    struct Node* ausgeklinkt = NIL;

    do {
        printf("\nWaehlen Sie einen Menuepunkt aus:\n");
        printf("a => Anhaengen\n");
        printf("l => Anzeigen\n");
        printf("k => Ausklinken\n");
        printf("e => Einklinken\n");
        printf("q => Beenden\n");
        printf("$ ");

        // Leerzeichen vor %c um Whitespace-Charaktere zu schlucken.
        scanf(" %c", &menu);

        switch(menu) {
            case 'a':
                anhaengen(&stau);
                break;
            case 'l':
                anzeigen(stau);
                break;
            case 'k':
                ausklinken(&stau, &ausgeklinkt);
                break;
            case 'e':
                einklinken(&stau, &ausgeklinkt);
                break;
            case 'q':
                printf("\nAuf Wiedersehen\n");
                break;
        }
    } while(menu != 'q');

    // Am Ende noch den Speicher aufräumen
    stauAufloesen(stau);    

    return 0;
}