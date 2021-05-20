#include <stdio.h>
// Wird fuer strlen() benötigt.
#include <string.h>

void rot13(char wort[], char encode[]) {

    // strlen() gibt uns zurueck wie viele Zeichen unser "wort" hat.
    for(int i = 0; i < strlen(wort); i++) {

        if(wort[i] >= 'a' && wort[i] <= 'm') {
            encode[i] = wort[i] + 13;
        }
        else if(wort[i] > 'm' && wort[i] <= 'z') {
            encode[i] = wort[i] - 13;
        }   
        else {
            encode[i] = wort[i];
        }
    }
}


int main() {
    
    // Arrays für die Palindrombildung
    char inArr[21];
    char paliArr[41];

    // Character fuer die Eingaben
    char c;     // nimmt Buchstaben mit getchar an
    int i = 0;      // zum hochzaehlen der Arrays
    int j = 0;      // zur Manipulation von inArr

    printf("Bitte geben Sie ein Wort ein: ");

    while((c = getchar()) != '\n' && i < 20) {
        inArr[i] = c;
        i++; //                                 |
        // lager     ->     h   a   l   l   o   v -> an dieser Stelle ist i
        // schreibt in --> [h] [a] [l] [l] [o] [ ]
    }

    // inArr[20] = '\0'--> erreichen wir [20]?
    // eher unwahrscheinlich, deswegen 
    // [h] [a] [l] [l] [o] ['\0']; <-- das Nullbyte wir auf die letzte
    // Stelle gesetzt
    inArr[i] = '\0';

    // ueberpruefen ob das eingegebene Wort das richtige ist
    printf("Das eingegebene Wort ist: %s\n", inArr);

    // -> Palindrombildung

    // 1. Schleife zum auffuellen von paliArr
    for(/* int j = 0*/; j < i; j++) {
        paliArr[j] = inArr[j];
    }

    // Kontrollausgabe um zu gucken welchen Wert
    // j an dieser Stelle hat
    printf("i: %i, j:%i \n",i, j);

    // j wird hier vom Nullbyte wieder auf 'o' gesetzt
    // waehrend i weiter das paliArr hochzaehlt.
    for(j -= 1; j >= 0; j--) {
    //   |                |
    //   v hochzaehlen    v runterzaehlen    
        paliArr[i] = inArr[j];
        // setzt unser i beim letzten durchgang auf len+1
        i++;
    }

    // Nullbyte ans Ende einfuegen
    paliArr[i] = '\0';

    printf("Das Palindrom ist: %s\n", paliArr);


    /////////////////////////////////////////////////////////////////
    // Aufgabenteil B
    /////////////////////////////////////////////////////////////////

    char wort[64];      // Array welches das einzulesende Wort speichert.
    char encode[64];    // Array welches das verschluesselte speichert.
    char input;

    int i13 = 0;

    printf("Bitte geben Sie das zu verschluesselnde Wort ein: ");

    // Wie oben wieder Einleseschleife
    while((input = getchar()) != '\n' && i13 < 64) {
        wort[i13] = input;
        i13++;
    }
    wort[i13] = '\0';

    // Alternativ
    // scanf("%63s", wort);
    // fgets(wort, size, stdin);

    rot13(wort, encode);

    printf("Wort: %s\tVerschluesselt:%s\n", wort, encode);

    return 0;
}