/*
 * Autor:	Robin Eschbach (dok. Robin Freund)
 * Datum:	14.04.2020
 * Zweck:	Berechnung der Groesse eines Turmes
 * Hinweis: Wir schreiben hier u.U. *deutlich* ausfuehrlichere/redundantere Kommentare als ihr es muesst/sollt.
 *          Das dient teilweise rein zur Veranschaulichung bei den ersten Uebungen.
 *          Ihr muesst z.B. ueber eine Addition nicht schreiben, dass es eine Addition ist. Schreibt hier eher,
 *          warum ihr addiert - wenn es nicht selbstverstaendlich ist. Das selbe Prinzip bei Schleifen oder Variablen.
 */

#include <stdio.h>
#include <math.h>

double degToRad(double deg)
{
	/* Formel zur Umberechnung: von Gradmass nach Bogenmass */
	return (M_PI / 180.0) * deg;
}

double phi(double alpha, double beta)
{
	return beta - alpha;
}

/* Anmerkung: Variablen, die den selben Namen wie eine Funktion haben,
 * kann man _innerhalb_ einer neuen Ebene (= engl. scope, z.B. Funktion) zwar
 * nutzen, diese ueberschreiben allerdings die Funktion innerhalb dieser Ebene. 
 * Die Funktion kann dann in diesem Bereich nicht gleichzeitig verwendet werden. 
 * Daher nennen wir die Variable hier nicht phi, sondern _phi, auch, weil die Funktionsnamen
 * durch die Aufgabenstellung vorgegeben sind.
 */
double u(double s, double alpha, double _phi)
{
	/* sin(double) erwartet das Argument im Bogenmass, daher hier konvertieren */
	double sinA = sin(degToRad(alpha));
	double sinPhi = sin(degToRad(_phi));

	/* Formel aus der Aufgabe: u = s * sin(a) / sin(phi) */
	return s * sinA / sinPhi;
}

double hoehe(double s, double alpha, double beta)
{
	double _phi = phi(alpha, beta);
	double _u = u(s, alpha, _phi);
	double sinB = sin(degToRad(beta));

	/* Formel aus der Aufgabe: h = u * sin(b) */
	return _u * sinB;
}

int main()
{
	double s = 0, alpha = 0, beta = 0;

	printf("Geben Sie die Standlinie ein: ");
	scanf("%lf", &s);
	printf("Geben Sie den Winkel alpha ein: ");
	scanf("%lf", &alpha);
	printf("Geben Sie den Winkel beta ein: ");
	scanf("%lf", &beta);

	/* Anmerkung: Der Formatspezifikator %g schreibt eine Gleitkommazahl
	 * so kurz, wie es geht. Entweder in wissenschaftlicher Schreibweise (z.B. 3.2610e+3)
	 * oder einfach ohne Nullen am Ende.
	 */
	printf("\nDer Turm hat eine Hoehe von: %g Metern.\n", hoehe(s, alpha, beta));
	printf("Die Strecke s betraegt: %g Meter.\n", s);
	printf("Der Winkel alpha betraegt: %g Grad.\n", alpha);
	printf("Der Winkel beta betraegt: %g Grad.\n", beta);
	printf("Der Winkel phi betraegt: %g Grad.\n", phi(alpha, beta));

	return 0;
}