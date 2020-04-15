/* 
 * C-Programm das Geometrie-Funktionen berechnet
 * Autor: Katrin, inf3493
 * Datum: 14.04.2020
 *
 */
#include <stdio.h>
#include <math.h> /* kompilieren mit -lm ! */

double pythagoras(double kA, double kB) { /* Berechnung der Länge der Hypotenuse mithilfe des Satzes von Pythagoras,
					     d.h. a^2+b^2 = c^2, benötigte Formel dafür: sqrt(a^2+b^2)*/
	double hypotenuse = 0;
	hypotenuse = sqrt(( kA * kA ) + ( kB * kB ));
	return hypotenuse;
}

double konvertRadius(double hypotenuse){ /* Berechnung des Radius eines Kreises mit derselben Fläche wie oben genannten c^2, 
					    d.h. die Wurzel der Fläche geteilt durch Pi ergibt unseren gewünschten Radius.*/
	double flaecheH = 0;
	flaecheH = hypotenuse * hypotenuse;
	double Radius = 0;
	Radius = sqrt(flaecheH/M_PI);
	return Radius;
}

double kubusVolumen(double hypotenuse){ /*Berechnung des Volumens eines Würfels mit c^3*/ 
	double volumen = 0;
	volumen = (hypotenuse*hypotenuse*hypotenuse);
	return volumen;
}

double kugelVolumen(double radius){ /*Berechnung des Kugelvolumens mithilfe von 4/3 * Pi * r^3*/
	double volumenK = 0;
	volumenK = (( 4.0 / 3l ) * M_PI * (radius * radius * radius)); /*Aufpassen: 
									 Integerdivision vermeiden, deshalb 4.0 und 3.0 (oder 4l und 3l)*/
	return volumenK;
}

int main(){
	double katheteA = 1.9;
	double katheteB = 4.2;
	double hypotenuse = 0;
	double Radius = 0;
	double kubusV = 0;
	double kugelV = 0;

	hypotenuse = pythagoras(katheteA, katheteB); 
	printf("a: %.3lf, a Quadrat: %.3lf\n", katheteA, (katheteA*katheteA));
	printf("b: %.3lf, b Quadrat: %.3lf\n", katheteB, (katheteB*katheteB));
	printf("c: %.3lf c Quadrat: %.3lf\n", hypotenuse, (hypotenuse*hypotenuse));

	Radius = konvertRadius(hypotenuse);
	printf("Kreisradius: %g, Flaecheninhalt: %g\n", Radius, (Radius*Radius*M_PI));

	kubusV = kubusVolumen(hypotenuse);
	printf("Kantenlaenge: %g, Wuerfelvolumen: %g\n", hypotenuse, kubusV);

	kugelV = kugelVolumen (Radius);
	printf("Kreisradius : %g, Kugelvolumen: %g\n", Radius, kugelV);
	
	return 0;
}
