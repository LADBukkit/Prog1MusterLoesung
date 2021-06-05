/* Autor: Robin Freund
 * Datum: 02.06.2021
 * Zweck: Hexenküche / Mittagstischplanung
 * Hinweis: Wir schreiben hier u.U. *deutlich* ausfuehrlichere/redundantere Kommentare als ihr es muesst/sollt.
 *          Das dient teilweise rein zur Veranschaulichung bei den ersten Uebungen.
 *          Ihr muesst z.B. ueber eine Ausgabe nicht schreiben, dass es eine Schleife ist. Schreibt hier eher,
 *          wie die Schleife funktioniert - wenn es nicht selbstverstaendlich ist. Das selbe Prinzip bei Schleifen, Ausgaben,
 *          Funktionsaufrufen.
 */

#include <stdio.h>
#include <string.h>

/* Konstante Groesse des Arrays hier festlegen */
#define ANZELEM 7

/* Definiere eine Struktur, die Platz fuer einen Integer- und einen Double-Wert
 * sowie eine Zeichenkette hat. Auf diese Elemente koennen wir spaeter ueber
 * die angegebenen Namen zugreifen
 */
struct Tagesstatistik
{
    int gaeste;
    double kalorien;
    char bezeichnung[100];
};

void printList(struct Tagesstatistik liste[], int anzElem)
{
    /* Formatierte Ausgabe, %-19s gibt die Zeichenkette linksbuending und
     * mit Platz fuer mindestens 19 Zeichen aus - Zeichen, die von uns nicht gefuellt werden,
     * werden von printf bei der Ausgabe mit Leerzeichen gefuellt
     */
    printf("%-19s %-19s %s\n", "Anzahl Gaeste", "Anzahl Kalorien", "Bezeichnung");

    for (int i = 0; i < anzElem; i++)
    {
        printf("%-19d %-19lf %s\n", liste[i].gaeste, liste[i].kalorien, liste[i].bezeichnung);
    }
}

void tausche(struct Tagesstatistik liste[], int indexA, int indexB)
{        
    /* Schritt 1: Speichere Wert der Variable zwischen, die in Zeile 47 ueberschrieben wird */
    struct Tagesstatistik tmp = liste[indexA];
    /* Schritt 2: Array unter indexA bekommt den Wert unter indexB */
    liste[indexA] = liste[indexB];
    /* Schritt 3: Element "tmp" wird nun in liste an indexB kopiert */
    liste[indexB] = tmp;

    
    /* Folgender Code wird dabei automatisch durch den Compiler generiert
     * bzw. koennte bei manchen, insb. aelteren Compilern direkt notwendig sein:
     *
     * struct Tagesstatistik tmp = {liste[indexA].gaeste, liste[indexA].kalorien};
     * strcpy(tmp.bezeichnung, liste[indexA].bezeichnung);
     *
     * liste[indexA].gaeste = liste[indexB].gaeste;
     * liste[indexA].kalorien =  liste[indexB].kalorien;
     * strcpy(liste[indexA].bezeichnung, liste[indexB].bezeichnung);
     *
     * liste[indexB].gaeste = tmp.gaeste;
     * liste[indexB].kalorien =  tmp.kalorien;
     * strcpy(liste[indexB].bezeichnung, tmp.bezeichnung);
     */
}

void tauscheMitZeiger(struct Tagesstatistik *a, struct Tagesstatistik *b)
{
    /* Speichere Wert der Variable zwischen, die in Zeile 58 ueberschrieben wird */
    struct Tagesstatistik tmp = *a;
    /* Speicherzelle unter der Adresse a bekommt den Wert unter b */
    *a = *b;
    /* Speicherzelle unter Adresse b bekommt den ehemaligen Wert unter a, der aktuell auf tmp liegt */
    *b = tmp;
}

void sortiereNachKalorien(struct Tagesstatistik stat[], int anzahl)
{
    /* Implementierung des Bubble-Sort-Algorithmus */
    for (int n = anzahl; n > 1; n--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            /* Folgender Absatz ist gleich zu: (*(stat+i)).kalorien > (*(stat+i+1)).kalorien
             * Wenn das aktuelle Element mehr Kalorien enthaelt als das naechste, ..
             */
            if ((stat + i)->kalorien > (stat + i + 1)->kalorien)
            {
                /* .. tausche das aktuelle Element mit dem naechsten - durch Array direkt im Speicher,
                 * daher reicht es hier aus, die Indexe und das Array (Referenz) zu uebergeben
                 */
                tausche(stat, i, i + 1);
            }
        }
    }
}

void sortiereNachBezeichnung(struct Tagesstatistik stat[], int anzahl)
{
    /* Implementierung des Bubble-Sort-Algorithmus */
    for (int n = anzahl; n > 1; n--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            /*  Vergleich zweier Elemente ueber die String-Funktion "strcmp"
             *  Beispielnutzung: 
             *    char a[] = "vor";
             *    char b[] = "nach";
             *    int i = strcmp(a, b);
             *
             *  Moegliche Werte, die strcmp zurueckgibt:
             *    i == 0 -> a == b
             *    i <  0 -> a kommt vor b im Alphabet
             *    i >  0 -> a kommt nach b im Alphabet
             */
            if (strcmp(stat[i].bezeichnung, stat[i + 1].bezeichnung) > 0)
            {
                tauscheMitZeiger(&stat[i], &stat[i + 1]);
            }
        }
    }
}

void textmix(struct Tagesstatistik *karte, int anzElem)
{
    /* Ersetzen von Zeichen im Array (direkt im Speicher, nicht in einer Kopie!) */
    for (int i = 0; i < anzElem; i++)
    {
        /* Setze den Pointer "tmp" auf das aktuelle Element im Array
         * (karte + i) ist hierbei das selbe Element wie &karte[i] und
         * stellt die Adresse vom Element unter "karte" an der Stelle "i" dar.
         */
        struct Tagesstatistik *tmp = karte + i;

        int j = 0;
        
        /* Ueber die Komponente "bezeichnung" bekommen wir, da auch "bezeichnung"
         * die Adresse des ersten Zeichens unserer Zeichenkette ist, das erste Zeichen
         * heraus, das wir pruefen wollen. Mit j koennen wir dank Zeigerarithmetik
         * durch jedes Zeichen in der Bezeichnung gehen.
         * 
         * Solange wir nicht das letzte Zeichen der Zeichenkette erreichen ..
         */
        while (*(tmp->bezeichnung + j) != '\0')
        {
            /* .. schaue, was das aktuelle Zeichen ist.. */
            switch (*(tmp->bezeichnung + j))
            {
                /* .. und ersetze es bei Bedarf. */
                case 'r':
                    *(tmp->bezeichnung + j) = 'n';
                    break;
                case 'n':
                    *(tmp->bezeichnung + j) = 'r';
                    break;
                case 'P':
                    *(tmp->bezeichnung + j) = 'K';
                    break;
                case 'K':
                    *(tmp->bezeichnung + j) = 'P';
                    break;
            }

            j++;
        }
    }
}

void minmax(struct Tagesstatistik *liste, int anzElem, struct Tagesstatistik **pmin, struct Tagesstatistik **pmax)
{
    /* Gehe durch das Array.. */
    for (int i = 0; i < anzElem; i++)
    {

        /* und veraendere den Zeiger unter pmax (min im Hauptprogramm) so, dass .. */
        if ((liste + i)->gaeste > (*pmax)->gaeste)
        {
            /* .. der Zeiger unter pmax auf das aktuell groessere Element im Array zeigt .. */
            *pmax = liste + i;
        }

        /* und veraendere den Zeiger unter pmin (min im Hauptprogramm) so, dass .. */
        if ((liste + i)->kalorien < (*pmin)->kalorien)
        {
            /* .. der Zeiger unter pmin auf das aktuell kleinere Element im Array zeigt .. */
            *pmin = liste + i;
        }
    }

    /* Wichtig zu beachten: pmin ist hier ein Zeiger auf den Zeiger (im Hauptprogramm min),
     * der auf das aktuell kleinste Element zeigt - er ist nicht das kleinste Element selbst!
     *
     * Wuerden wir hier keinen Zeiger auf den Zeiger, sondern nur den Zeiger selbst an die
     * Funktion uebergeben, koennten wir nur das Element im Array selbst aendern, nicht den
     * Zeiger auf das Element.
     */
}

int main()
{
    struct Tagesstatistik woche[ANZELEM] = {
        {87, 111.3, "Spinnwebengeflecht in Aspik aus vergorenem Algenglibber"},
        {21, 77.7, "Ganzer Kuerbisgeist flambiert nach Tageslaune des Raben"},
        {69, 178.871, "Leckeres Schwefel-Salmiak-Sueppchen mit Sahnehaeubchen"},
        {17, 13.08, "In Naphtalin gegarte Knoblauchzehe an einem Hauch von Panik"},
        {281, 234.5, "Stinkmorchel im eigenen Saft mit rohen Pantoffelpuffern"},
        {42, 323.232, "Brennender Teufelswurz im Marzipanmantel auf Sauerampfer"},
        {2, 1024.7, "Vergammelter Fliegenpilz am feinen Rattengift im Schmalzbad"}};

    /* Setze zwei Zeiger auf ein real existierendes Element im Array, die spaeter
     * auf das echte Minimum/Maximum umgelenkt werden.
     */
    struct Tagesstatistik *pmin = woche;
    struct Tagesstatistik *pmax = woche;

    printf("Unsortierte Ausgabe:\n");
    printList(woche, ANZELEM);

    printf("Sortierte Ausgabe:\n");
    sortiereNachKalorien(woche, ANZELEM);
    printList(woche, ANZELEM);

    printf("\nSortiert nach Bezeichnung\n");
    sortiereNachBezeichnung(woche, ANZELEM);
    printList(woche, ANZELEM);

    printf("\nNach Textmix:\n");
    textmix(woche, ANZELEM);
    printList(woche, ANZELEM);

    minmax(woche, ANZELEM, &pmin, &pmax);
    
    printf("Kleinste Kalorienzahl:\n");

    /* Ausgabe des kleinsten Elementes, indem der Funktion vorgemacht wird, das uebergebene
     * Array wuerde bei "min" beginnen und nur ein Element enthalten.
     */
    printList(pmin, 1);
    printf("Groesste Gastanzahl:\n");
    printList(pmax, 1);

    return 0;
}