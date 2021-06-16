/* dechiffer.c - (c)2018 by C Held
 * (c)2021 by David Lüdtke
 * (c)2021 by Robin Eschbach für den Steuererklärungswitz
 * Musterlösung für Dechiffrieren Loesungswort aus 2 Textargumenten, fast fertig.
 * Der Code enthält vielleicht noch ein, zwei Fehler.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replacechar(char *text)
{
    char *cp = text;
    while (*cp != '\0') {
        if (*cp == '!') {
    	    *cp = 'i';
    	} else if (*cp == '0') {
    	    *cp = 'o';
    	} else if (*cp == '2') {
    	    *cp = 'z';
    	} else if (*cp == '3') {
    	    *cp = 'e';
    	} else if (*cp == '7') {
    	    *cp = 'r';
    	} else if (*cp == '9') {
    	    *cp = 'g';
    	}
    	cp++;
    }
}

/* Texte Zusammenfuegen ("Reissverschlussverfahren") */
char *mixtexts(char *cp1, char *cp2)
{
    char *cp, *rp;
    rp = cp = malloc(strlen(cp1) + strlen(cp2) + 1);
    if (cp != (char *)0) {
        /* solange mindestens ein Text noch Zeichen hat */
        while (*cp1 != '\0' || *cp2 != '\0') {
            /* jeweils mit Text1 anfangen */
            if (*cp1 != '\0') {
                *cp = *cp1;
                cp++;
                cp1++;
            }
            
            /* dann Text2 dazumischen */
            if (*cp2 != '\0') {
                *cp = *cp2;
                cp++;
                cp2++;
            }
        }
    }
    return rp;
}

int main()
{
    char zkette1[1024];
    char zkette2[1024];
    char *cp;			
    /* Zeichenketten einlesen */
    printf("Bitte Zeichenkette 1 eingeben: ");
    scanf("%s", zkette1);
    printf("Bitte Zeichenkette 2 eingeben: ");
    scanf("%s", zkette2);
    /* Kontrollausgabe */
    printf("Zeichenketten unbearbeitet: |%s| und |%s|\n", zkette1, zkette2);
    /* In beiden Argumenten die Buchstaben ersetzen */
    replacechar(zkette1);
    replacechar(zkette2);
    /* Kontrollausgabe */
    printf("Argumente nach Zeichenumsetzung: |%s| und |%s|\n", zkette1, zkette2);
    /* Zusammenfuegen */
    cp = mixtexts(zkette1, zkette2);
    if (cp != (char *) 0) {
        /* Abschlussausgabe */
	    printf("Das Loesungswort ist: |%s|\n", cp);
	    free(cp);
    }
    return 0;
}