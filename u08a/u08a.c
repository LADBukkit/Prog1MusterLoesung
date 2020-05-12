/* Name: Übung u08a - Manipulation von Zeichenketten
 * Autor: Luca Chiarelli + Robin Freund
 * Datum: 12.05.2020
 * Hinweis: Wir schreiben u.U. deutlich ausfuehrliche Kommentare als ihr
 *          es sollt und muesst. Kommentiert bitte vor allem Dinge,
 *          die nicht durch den Code schon ersichtlich sind.
 */
#include <stdio.h>

#define STR_LEN 1024

int xstrnlen(char s[], int n)
{
    int i = 0;

    /* Suche das Ende der Zeichenkette (Nullbyte oder Maximallaenge).. */
    while (s[i] != '\0' && i < n)
    {
        /* .. und zaehle bei jedem Schritt hoch. */
        i++;
    }

    /* Gib die Anzahl der Zeichen (ohne Nullbyte) zurueck. */
    return i;
}

char *xstrncpy(char nach[], char von[], int n)
{
    int i = 0;

    /* Suche das Ende der Zeichenkette (Nullbyte oder Maximallaenge).. */
    while (von[i] != '\0' && i < n)
    {
        /* .. kopiere Zeichen fuer Zeichen von "von" nach "nach" ..*/
        nach[i] = von[i];
        i++;
    }

    /* und haenge das Nullbyte an. */
    nach[i] = '\0';

    return nach;
}

char *xstrncat(char nach[], char von[], int n)
{
    /* Suche das Ende der Zeichenkette "nach".. */
    while (*nach != '\0')
    {
        nach++;
    }

    /* und kopiere hinter sie die Zeichenkette "von".
     * Dafuer wird der Kopierfunktion gesagt, dass die Speicherstelle,
     * ab der "von" in "nach" anfangen soll, genau hinter dem letzten Zeichen,
     * sprich: *auf* dem Nullbyte liegt.*/
    return xstrncpy(nach, von, n);
}

int xstrncmp(char a[], char b[], int n)
{
    int i = 0;

    /* Solange die Zeichenkette gleich ist und der Zaehler unter der Groesse
     * des Arrays liegt, schaue, ob die Zeichen unter i gleich sind.. */
    while (a[i] == b[i] && i < n - 1)
    {
        /* Pruefe, ob eine der beiden Seiten ein Nullbyte ist (ab diesem Punkt)
         * koennen und duerfen wir nicht weiter nach Unterschieden suchen */
        if (a[i] == '\0' || b[i] == '\0')
            break;

        i++;
    }

    /* Wenn die Schleife abbricht (Nullbyte) oder fertig ist (kein Unterschied) gefunden,
     * gib die Differenz des entweder ersten unterschiedilchen Zeichens oder des letzten untersuchten
     * Zeichens zurueck */
    return a[i] - b[i];
}

/* Diese Funktion ist zum besseren Verstaendnis mit Hilfsarray umgesetzt. 
 * Um zu sehen, wie ein Konzept ohne Hilfsarray aussieht, siehe HIER NOCH LINK ODER DATEIVERWEIS EINFÜGEN */
void replaceWord(char work[], char find[], char subst[], int bufsiz)
{
    /* Zwischenspeicher mit genug Platz fuer den Endteil der Zeichenkette "work", 
     * da dieser spaeter potentiell uebrschrieben wird. Array-Groesse muss bei dieser
     * Definitionsform schon zur Kompilierzeit bekannt sein, daher geht "bufsize" nicht als Groesse. */
    char temp[STR_LEN];
    int findPos = 0, findLaenge = xstrnlen(find, bufsiz);

    /* Schritt 1: Finde die Stelle im Speicher, an der "find" anfaengt */
    while (xstrncmp(work + findPos, find, findLaenge) != 0 && findPos < bufsiz)
    {
        findPos++;
    }

    /* Schritt 2: Pruefe, ob die Zeichenkette "find" gefunden wurde. */
    if (findPos < bufsiz)
    {
        /* Schritt 3: Sichere den Teil hinter "find", da dieser moeglicherweise beim Ersetzen
         * ueberschrieben wird. */
        xstrncpy(temp, work + findPos + findLaenge, bufsiz);

        /* Schritt 4: Ueberschreibe "find" mit "subst". Genauer gesagt:
         * Schreibe ab der Stelle, an der "find" anfaengt, "subst" ohne Ruecksicht auf
         * nachfolgende Zeichen in den Speicher - mit Nullbyte! */
        xstrncpy(work + findPos, subst, bufsiz);

        /* Schritt 5: Haenge den unversehrten, zwischengespeicherten Endteil
         * hinter unsere Zeichenkette "subst" */
        xstrncat(work + findPos + xstrnlen(subst, bufsiz), temp, bufsiz);
    }
}

int main()
{
    char string[STR_LEN] = "Heute back ich, morgen schlaf ich, uebermorgen ...";

    printf("Ursprungszeichenkette: %s\n", string);

    replaceWord(string, "schlaf", "strick", STR_LEN);
    printf("Neue Zeichenkette: %s\n", string);

    replaceWord(string, "strick", "brau", STR_LEN);
    printf("Neue, neue Zeichenkette: %s\n", string);

    return 0;
}