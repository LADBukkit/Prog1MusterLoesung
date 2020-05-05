/* Hausaufgabe u06a Integer-Array
 * 05.05.2020
 * Programmiert von David L
 */
#include <stdio.h>
#include <stdlib.h> // Wird für rand() und srand() benötigt
#include <time.h>   // Wird für time() benötigt
#define ARR_SIZE 1000

void init(int intArr[], int arrSize) {
    // initialisieren des Zufallgenerators
    srand(time(NULL));
    /* 	Generelle Zufallszahlerzeugung
     *  int min = 5;
     *  int max = 20;
     *  intArr[i] = rand() % (max - min + 1) + min;
     */
    for (int i = 0; i < arrSize; i++) {
        intArr[i] = (rand() % 5000) + 1;
    }
}

void ausgabe(int intArr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (i != 0 && i % 10 == 0) {
            printf("\n");
        }
        printf("%5d", intArr[i]);
    }
    printf("\n");
}

int suche(int intArr[], int arrSize, int gesucht) {
    for (int i = 0; i < arrSize; i++) {
        if (intArr[i] == gesucht) {
            /*
             * Wenn "gesucht" im Array gefunden wurde,
             * wird die Funktion abgebrochen und der Index zurückgegeben.
             */
            return i;
        }
    }
    /* Wenn "gesucht" nicht gefunden wurde und die Funktion somit nicht
     * abgebrochen wurde, wird -1 zurückgegeben.
     */
    return -1;
}

int main() {
    // Array mit 1000 Feldern
    int myarray[ARR_SIZE];
    int eingabe;
    int treffer;

    init(myarray, ARR_SIZE);
    ausgabe(myarray, ARR_SIZE);

    printf("\nBitte geben Sie einen Wert zur Suche ein: ");
    scanf("%d", &eingabe);
    treffer = suche(myarray, ARR_SIZE, eingabe);
    if (treffer == -1) {
        printf("Die Zahl %d ist im Array nicht vorhanden!\n", eingabe);
    } else {
        printf("Die Zahl %d ist im Array an der Stelle %d!\n", eingabe, treffer);
    }

    return 0;
}