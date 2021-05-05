/*
 * Name: Luca Chiarelli
 * Datum: 07.04.2021
 * Beschreibung: Ganzzahlen in Schleife einlesen, das Produkt 
 * der eingegebenen Zahlen bilden und einen Counter setzen, 
 * wie viele Zahlen eingegeben wurden. 
 * Aufgabenteil b): Schleife mit einem switch-Case ergänzen welcher
 * eingabe bestimmter Zahlen andere Ereignisse hervorbringt??? 
 */
 
 // Wichtig um scanf und printf zu verwenden
#include <stdio.h> 



int main() {
    
    int counter = 0;    // ein Counter zum hochzaehlen 
    int input;          // Eine Variable fuer Eingaben
    int produkt = 1;    // Vordefinierte Variable die NICHT 0 sein, da sonst mit 0 multipliziert wird.

    printf("Bitte geben Sie eine Ganzzahl ein.\nDie Schleife errechnet das Produkt aus den in der Schleife eingegebenen Zahlen (0 zum abbrechen):\n");

    // While-Schleife die solange laeuft, bis der Nutzer eine 0 eingibt. 
    while(input != 0) {

        // Bibliotheksfunktion fuer Eingaben von Integer, kann auch fuer andere Datentypen verwendet werden, braucht dann aber einen anderen "Formatstring" (das "%i").
        scanf("%i", &input);

        // Switch Case, aehnlich wie if abfragen, nur das hier mehrere if-Abfragen in einem Codeblock gebuendelt werden.
        switch(input) {
            // Wenn input 42 ist, dann soll das Prodult mit -1 multipliziert werden.
            case 42: 
                produkt *= -1;
                // Das break ist wichtig, damit nach dieser Anweisung das Switch-Case abgebrochen wird. Fehlt das break, wuerde Switch ins naechste case rutschen und somit das 
                // Produkt mit 1000 multiplizieren, siehe naechstes Switch Case.
                break;
            case 100: 
                printf("Bingo!\n");
                produkt *= 1000;
                break; 
            case 1:
                printf("NOPE\n");
                break;
            // Falls keins der cases zutrifft gibt es einen default, welches jedes mal ausgefuehrt wird. Da default das letzte Switch-Case darstellt, braucht man hier kein break. 
            default:
                if(input != 0)
                    produkt *= input; 
        }   
        // Nach der Eingabe und der ueberpruefung der Eingabe zaehlen wir unseren Counter hoch, um die anzahl der Eingaben zu checken.
        counter++;
    }
    
    // Ausgabe des Errechneten Produkts
    printf("Das Produkt der eingegebenen Zahlen ist: %i\n", produkt);
    // Ausgabe des Counter. Hier mit -1, da sonst die 0 mitgezaehlt wird.
    printf("Es wurden %i Zahlen eingegeben\n", counter-1);

    return 0;
}



