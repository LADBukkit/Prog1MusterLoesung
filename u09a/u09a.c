/* Name: Übung u09a - Sichere Texte
 * Autor: Robin Freund und David Lüdtke
 * Datum: 26.05.2021
 * Hinweis:   Wir schreiben u.U. deutlich ausfuehrliche Kommentare als ihr
 *            es sollt und muesst. Kommentiert bitte vor allem Dinge,
 *            die nicht durch den Code schon ersichtlich sind.
 */

#include <stdio.h>
#define ARRSIZ 1024

int xstrnlen(char * s, int n) {
	int i = 0;
	
	/* Zaehle bis maximal n ..*/
	for (i = 0; i < n; i++) {
	
		/* und brich ab, wenn das Wort vorher zuende ist. */
		if (s[i] == '\0') {
			break;
		}
	}
	
	/* In jedem Fall: "Index" zurückgeben: Entweder den des Nullbytes oder n */
	return i;
}

char * xstrncpy(char * nach, char * von, int n) {

	/* Zaehle bis maximal n ..*/
	for (int i = 0; i < n; i++) {
	
		/* .. kopiere erst Zeichen für Zeichen ..*/
		nach[i] = von[i];
		
		/* und brich danach ab, wenn das Wort vor n zuende ist. */
		if (von[i] == '\0') {
			break;
		}
	}
	
	/* Haenge kein! Nullbyte an, das macht strcpy auch nicht! */
	return nach;
}

char * xstrncat(char * nach, char * von, int n) {

	/* Finde die Laenge von "nach" heraus, 
	 * um an dieser Position mit der Kopie von "von" anzufangen.
	 */
	int nachLaenge = xstrnlen(nach, ARRSIZ);
	int i = 0;
	
	/* Zaehle bis maximal n ..*/
	for (i = 0; i < n; i++) {
		/* .. und brich direkt ohne Kopie ab, wenn ein Nullbyte auftaucht, damit dieses
		 * nach der for-Schleife angehaengt werden kann ..
		 */
		if (von[i] == '\0') {
			break;
		}
		
		/* .. oder kopiere hinter "nach" den Inhalt von "von". */
		nach[nachLaenge + i] = von[i];
	}
	
	/* Haenge in jedem Fall ein Nullbyte an. Siehe
	 * man-pages fuer mehr Details.
	 */
	nach[nachLaenge + i] = '\0';
	
	return nach;
}

int xstrncmp(char * a, char * b, int n) {
	/* Zaehle bis maximal vor  n-1, damit der letzte Schritt
	 * der Vergleich des richtigen Zeichens ergibt.
	 */
	for (int i = 0; i < n; i++) {
	
		/* Abbruchbedingung 1: Zeichen an einer Stelle ungleich.
		 * Gebe Differenz zurueck.
		 */
		if (a[i] != b[i]) {
			return a[i] - b[i];
		}
		
		/* Abbruchbedingung 2: Eine der beiden Zeichenketten ist an dieser
		 * Position beendet. Gebe Differenz zurueck.
		 */
		if (a[i] == '\0' || b[i] == '\0') {
			return a[i] - b[i];
		}
	}
	/* Kein Abbruch: Gebe eine Differenz von 0 zurück: Zeichenketten sind
	 * identisch bis zum Limit "n"
	 */
	return 0;
}

void replaceWord(char * work, char * find, char * subst, int bufsiz) {
	// "Ziste" » "Sti"
	
	// Schritt 1: Stelle finden, wo find übereinstimmt
	// work = "Von der Zisterne halbe rinnen muss der Schwalbe"
	//                 ^ findPos

	// Schritt 2: Alles dahinter abspeichern in tmp
	// tmp = "rne halbe rinnen muss der Schwalbe"
	
	// Schritt 3: find ersetzen durch subst (solange bis subst zu ende ist)
	// work = "Von der Stiterne halbe rinnen muss der Schwalbe"
	//                    ^ findPos + substLaenge
	
	// Schritt 4: An work tmp anhängen nach Ende von Subst
	// work + tmp = "Von der Stirne halbe rinnen muss der Schwalbe"
	
	char temp[ARRSIZ];
	
	int findLaenge = xstrnlen(find, bufsiz);
	int substLaenge = xstrnlen(subst, bufsiz);
	int findPos = 0;
	
	// Schritt 1:
	while (xstrncmp(work + findPos, find, findLaenge) != 0) {
		if (findPos >= bufsiz) {
			return;
		}
		findPos++;
	}
	
	// Schritt 2:
	xstrncpy(temp, work + findPos + findLaenge, bufsiz - findPos - findLaenge);
	
	// Schritt 3:
	xstrncpy(work + findPos, subst, bufsiz - findPos);
	
	// Schritt 4:
	xstrncat(work + findPos + substLaenge, temp, bufsiz - findPos - substLaenge);
}

int main() {
	char text[ARRSIZ] = "Von der Zisterne halbe rinnen muss der Schwalbe";
	
	replaceWord(text, "albe", "eiss", ARRSIZ);
	replaceWord(text, "albe", "eiss", ARRSIZ);
	
	printf("Unser Satz lautet: |%s|\n", text);
	
	replaceWord(text, "Ziste", "Sti", ARRSIZ);
	
	printf("Unser Satz lautet: |%s|\n", text);
	
	return 0;
}





