/* u11b - C-Programm zum Umgang mit main-Argumenten
* Datum: 16.06.2021
* Name: Maren Franke
* Beschreibung: Verschiedene Aktionen fuer verschiedene Programmnamen
*		upper 	=> alle Argumente werden gross ausgegeben 
*		number 	=> die Ziffern werden aus den Argumenten extrahiert
*		pali 	=> aus den Argumenten werden Palindrome gebildet
*/


/* Beispiel

0. Argument					1. Argument				2. Argument
| . / u p p e r \0 |		| H a l l o \0 |		| W e l t \0|
  0 1 2 3 4	5 6  7			  0 1 2 3 4	 5			  0 1 2 3  4

*/

#include <stdio.h>		
#include <string.h>			/* fuer strrchr(), strncpy(), strlen(), strcmp(), strcat() */
#include <ctype.h>			/* fuer toupper() */
#include <stdlib.h>			/* fuer atoi() */
#include <stdbool.h>		/* fuer bool */

/* fuer die number; Erkennung, ob in der Zeichenkette eine Zahl vorkommt */
bool hatZahl(char arr[], int len) {
	/* Durchlauf des gesamten Arrays */
	for(int i = 0; i < len; i++) {
		
		/* wenn eine Ziffer gefunden wird, beendet sich die Funktion und gibt true zurueck */
		if(arr[i] >= '0' && arr[i] <= '9') {
			return true;
		}
	}
	
	/* Wenn keine Ziffer gefunden wurde, gibt die Funktion mit false zurueck */
	return false;
}

/* Main-Funktion mit Main-Parametern
*  argc = Anzahl der Aufrufparameter => Programmname + Anzahl Parameter
*  *argv[] =enthaelt alle Argumente als Zeichenketten
*  bspw. ./upper Hallo Welt		=> argc = 3 	
*  argv[0] = "./upper"; argv[1] = "Hallo"; 	argv[2] = "Welt"
*/
int main(int argc, char * argv[]) {
	/* Programmname, damit der Parameter argv[0] nicht veraendert wird	*/
	char progname[51];
	
	/* Ziel: Pfad aus dem Programmnamen rausschneiden
	*  Durchsuche des Char-Arrays argv[0] nach dem char '/' und Rueckgabe des Pointers auf die Stelle, wenn
	*  das Char Element gefunden wurde, ansonsten erfolgt die Rueckgabe von 0 */
	if(!strrchr(argv[0], '/')) {
		/* Der Programmname enthaelt keinen Pfad => Kopierung von argv[0] auf progname */
		strncpy(progname, argv[0], sizeof(progname));
	}
	else {
		/* Ziel: Kopierung des Programmnamens ohne Pfad
		*  Erneute Durchsuchung bis zu '/' => Rueckgabewert ist ein Pointer auf die Stelle '/', da wir aber '/'
		*  nicht mit kopieren wollen, gehen wir ein Element weiter (+1) und kopieren ab dieser Stelle den 
		*  Programmnamen auf den Char-Array progname */
		strncpy(progname, strrchr(argv[0], '/') + 1, sizeof(progname));
	}
	
	/* Ausgabe zur Ueberpruefung */
	printf("progname: %s \n", progname);
	
	/* Ueberpruefung, ob das Programm genuegend Parameter besitzt (es muss fuer die Sinnhaftigkeit mindestens
	*  zwei Parameter besitzen (Programmname und ein Argument)), wenn dies nicht der Fall ist wird eine 
	*  Fehlermeldung ausgegeben und das Programm beendet */
	if(argc < 2) {
		printf("%s - Falsche Anzahl an Parametern! \n", progname);
		return 22;
	}
	
	if(strcmp(progname, "upper") == 0) {		/* Aufruf, wenn Programmname "upper" ist */
		/* Durchlauf durch alle Argumente */
		for(int i = 1; i < argc; i++) {
			
			/* Durchlauf durch alle char-Elemente des jeweiligen Arguments */
			for(int j = 0; j < strlen(argv[i]); j++) {
				/* Umwandlung der einzelnen Zeichen in Grossbuchstaben */
				printf("%c", toupper(argv[i][j]));
			}
			printf(" ");
		}
		printf("\n");
	}
	else if(strcmp(progname, "number") == 0) {	/* Aufruf, wenn Programmname "number" ist */
		/* Durchlauf durch alle Argumente */
		for(int i = 1; i < argc; i++) {
		
			/* Wenn im jeweilige Argument eine Zahl enthalten ist */
			if(hatZahl(argv[i], strlen(argv[i]))) {
				/* Umwandlung der Zeichenketten mit Zahlen in eine Integer */
				printf("%i ", atoi(argv[i]));
			}
		}
		printf("\n");
	}
	else if(strcmp(progname, "pali") == 0) {	/* Aufruf, wenn Programmname "pali" ist */
		/* Durchlauf durch alle Argumente */
		for(int i = 1; i < argc; i++) {
			int laenge = strlen(argv[i]);		/* Laenge des jeweiligen Arguments bestimmen */
			char cpy[laenge + 1];				/* neues Hilfs-Array mit derselben Laenge wie argv[i] */
			char pali[laenge * 2 + 1];			/* Array fuer das Ergebnis-Palindrom */
			
			/* Kopierung des Arguments auf das Ergebnis-Array
			*  Begruendung: Palindrom = Wort zuerst vorwaerts, danach rueckwaerts
			*  => Kopierung des Wortes vorwaerts auf das Array */
			strcpy(pali, argv[i]);
			
			/* Kopierung des Arguments rueckwaerts auf das cpy-Array, "Umdrehung" 
			*  bspw. wird aus lager => regal	*/
			for(int j = 0; j < laenge; j++) {
				cpy[j] =  argv[i][laenge - j - 1];
			}
			cpy[laenge] = '\0';
			
			/* Anhaengen des Wortes, welches rueckwaerts ist, an das Wort, das vorwaerts ist
			*  bspw. pali = "lager"	cpy = "regal"		=> pali = "lagerregal"
			*/
			strcat(pali, cpy);
			printf("%s \n", pali);
		}
	}
		
	return 0;
}
