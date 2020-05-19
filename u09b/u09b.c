/*
 * Author:		Robin Eschbach
 * Datum:		19.05.2020
 * Beschreibung:	u09b - Kurverwaltung mit Structs und Arrays
 */

#include <stdio.h>
#include <string.h>

// Enum für die Art der Sortierung
enum Sortierung {
	NACH_GAESTE,
	NACH_TEMPERATUR,
	NACH_TITEL
};

// Steht für die Statistik eines Monats
struct Statistik {
	int	gaeste;
	float	temperatur;
	char	titel[128];
};

void print(struct Statistik verw[], int laenge) {
	// Ausgeben des Tabellenkopfes
	printf("%-10s %-10s %s\n", "Gaeste", "Temperatur", "Titel");

	for(int i = 0; i < laenge; i++) {
		// Ausgeben der einzelnen Zeilen
		printf("%-10i %-10g %s\n", verw[i].gaeste, verw[i].temperatur, verw[i].titel);
	}
}

void tausche(struct Statistik* a, struct Statistik* b) {
	// Tauscht die Structs unter a und b
	struct Statistik hilfe = *a;
	*a = *b;
	*b = hilfe;
}

void sortiere(struct Statistik verw[], int laenge, enum Sortierung sort) {
	// Sortieren mit dem BubbleSort Algorithmus
	for(int n = laenge; n > 1; n--) {
		for(int i = 0; i < n - 1; i++) {
			// Sortieren nach Gästen
			if(sort == NACH_GAESTE) {
				if(verw[i].gaeste < verw[i + 1].gaeste) {
					tausche(verw + i, verw + i + 1);
				}
			}
			// Sortieren Temperatur
			else if(sort == NACH_TEMPERATUR) {
				if(verw[i].temperatur < verw[i + 1].temperatur) {
					tausche(verw + i, verw + i + 1);
				}
			}
			// Sortieren nach Titel
			else if(sort == NACH_TITEL) {
				// Sortieren mit strcmp
				// Ergebnis von strcmp:
				// strcmp(a, b) <  0 : a kommt im Alphabet vor b
				// strcmp(a, b) == 0 : a ist gleich b
				// strcmp(a, b) >  0 : a kommt im Alphabet nach b
				if(strcmp(verw[i].titel, verw[i + 1].titel) > 0) {
					tausche(verw + i, verw + i + 1);
				} 
			}
		}
	}
}

void textmix(struct Statistik verw[], int laenge) {
	for(int i = 0; i < laenge; i++) {
		char* titel = (verw + i)->titel;
		
		// Durchlaufen des Titels bis zum Nullbyte
		while(*titel != '\0') {
			// Austauschen der Buchstaben
			switch(*titel) {
				case 'a':
					*titel = 'o';
					break;
				case 'o':
					*titel = 'a';
					break;
				case 'A':
					*titel = 'O';
					break;
				case 'O':
					*titel = 'A';
					break;
			}
			titel++;
		}
	}
}

void minmax(struct Statistik verw[], int laenge, struct Statistik** min, struct Statistik** max) {
	for(int i = 0; i < laenge; i++) {
		// Wenn die Gästeanzahl des i-ten Elements größer ist
		// als die des momentanen Maximums
		if(verw[i].gaeste > (*max)->gaeste) {
			// Setzte den Zeiger unter max auf das i-te Element
			*max = verw + i;
		}

		// Wenn die Temperatur des i-ten Elements kleiner ist
		// als die des momentanen Minimums
		if(verw[i].temperatur < (*min)->temperatur) {
			// Setzte den Zeiger unter min auf das i-te Element
			*min = verw + i;
		}
	}
}

int main() {
	// Initialisierung des Verwaltungs Arrays
	struct Statistik verwaltung[12] = {
		{412, 2.34, "Holliday on Ice"},
		{352, 1.03, "Skizirkus Graswandertoni"},
		{78, 3.72, "Haselnussbluete am Kroetenbrunnen"},
		{201, 5.68, "Osternestbasteln mit Artur"},
		{534, 11.11, "Siegfried und der Maidrache"},
		{478, 15.34, "Zauberfloete auf der Domstaffel"},
		{1267, 23.88, "Pfrimmschwimmen fuer Alle"},
		{1482, 24.02, "Heuschobernaechte rustikal"},
		{739, 17.44, "Indian Summer in der Pfalz"},
		{333, 12.55, "Weinlese im Weingut Oechsle"},
		{12, 6.66, "Eat what you can mit Martinsgans"},
		{856, -3.22, "Weihnachtsmarkt Erzgebirge"}
	};

	// Zeiger auf das Element in verwaltung mit der niedrigsten Temperatur
	struct Statistik* pmin = verwaltung;
	// Zeiger auf das Element in verwaltung mit der höchsten Gästeanzahl
	struct Statistik* pmax = verwaltung;

	// Ausgeben des Unsortierten Arrays
	print(verwaltung, 12);

	// Sortieren nach Gästen und ausgeben
	sortiere(verwaltung, 12, NACH_GAESTE);
	print(verwaltung, 12);

	// Sortieren nach Temperatur und ausgeben
	sortiere(verwaltung, 12, NACH_TEMPERATUR);
	print(verwaltung, 12);

	// Sortieren nach Titel und ausgeben
	sortiere(verwaltung, 12, NACH_TITEL);
	print(verwaltung, 12);

	// Vertauschen der Buchstaben und ausgeben
	textmix(verwaltung, 12);
	print(verwaltung, 12);

	// Richtung von pmin und pmax auf die jeweiligen Elemente
	minmax(verwaltung, 12, &pmin, &pmax);

	// Ausgabe von pmin
	printf("Monat mit niedrigster Temperatur:\n");
	print(pmin, 1);

	// Ausgabe von pmax
	printf("Monat mit hoester Gaesteanzahl:\n");
	print(pmax, 1);

	return 0;
}
