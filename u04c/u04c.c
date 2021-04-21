/* C-Programm u04c
* Name: Maren
* Datum: 21.04.2021
* Inhalt: Bestimmung der Hypothenuse, des Radius und des Volumens
*/

#include <stdio.h>
#include <math.h>

/*
* a^2 + b² = c^2
* => c = Wurzel(a^2 + b^2)
*/
double pythagoras(double a, double b) {
	return sqrt(a * a + b * b);
}

/*
* A = Pi * r^2		| durch Pi
* A / Pi = r^2		| Wurzel ziehen
* Wurzel( A / Pi) = r
* A = c^2
* r = Wurzel ( c^2 / Pi)
*/
double konvertRadius(double c) {
	return sqrt( c * c / M_PI);
}

/*
* c * c * c
*/
double kubusVolumen(double c) {
	return c * c * c;
}

/*
* 4/3 * Pi * r^3
*/
double kugelVolumen(double r) {
	return (4.0/3.0 * M_PI * r * r * r);
}

int main() {

	double a = 1.9, b = 4.2, c;
	double r;

	/* ----- Aufgabenteil a -----*/
	c = pythagoras(a, b);

	printf("a: %lf, a Quadrat: %lf \n", a, a * a);
	printf("b: %lf, b Quadrat: %lf \n", b, b * b);
	printf("c: %lf, c Quadrat: %lf \n", c, c * c);

	/* ----- Aufgabenteil b -----*/
	r = konvertRadius(c);

	printf("Kreisradius: %lf, Flaecheninhalt: %lf \n", r, c * c);


	/* ----- Aufgabenteil c -----*/
	printf("Kantenlaenge: %lf, Wuerfelvolumen: %lf \n", c, kubusVolumen(c));
	printf("Kreisradius: %lf, Kugelvolumen: %lf \n", r, kugelVolumen(r));

	return 0;
}
