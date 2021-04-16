/*
Name: Dominic Meyer
Datum: 14.4.21
Beschreibung: u04a Funktionen zur Geometrie
Beim kompilieren mit Option -lm
*/

#include <stdio.h>
#include <math.h>

#define PI 3.1415                                                                   //Definition einer eigenen Konstante, alternativ können wir auch das definierte PI aus der math.h Bibliothek nehmen

double zuBogen(double grad)                                                         //Funktion vom Typ double zur Umrechnung vom Gradmaß ins Bogenmaß
{
    return (PI / 180) * grad;
}

double phi(double a, double b)                                                      //Funktion vom Typ double zur Berechnung von phi
{
    return b - a;
}

double u(double s, double a, double phi)                                            //Funktion vom Typ double zur Berechnung von u (formel kommt von der Aufgabenstellung)
{                                                                                   
    return s * sin(zuBogen(a)) / sin(zuBogen(phi));                                 //die Funktion sin() rechnet nur im Gradmaß, wir wollen das Ergebnis im Bogenmaß, daher konvertieren wir
}

double hoehe(double s, double a, double b)                                          //Funktion vom Typ double zur Berechnung der Hoehe
{
    double phi_tmp = phi(a, b);                                                     //initialisieren einer temporaeren Variablen, damit das return ein bisschen übersichtlicher aussieht
    return u(s, a, phi_tmp) * sin(zuBogen(b));                                      //sin() rechnet allerdings im Gradmaß, daher hier ebenfalls konvertieren
}


int main()
{
    double s = 0;
    double alpha = 0;
    double beta = 0;

    printf("Bitte geben Sie eine Laenge ein: ");
    scanf("%lf", &s);
    printf("Bitte geben Sie einen Wert fuer Alpha ein: ");
    scanf("%lf", &alpha);
    printf("Bitte geben Sie einen Wert fuer Beta ein: ");
    scanf("%lf", &beta);

    //Aufruf der Funktionen im printf()
    printf("Der Turm hat eine Hoehe von: %g Meter\n", hoehe(s, alpha, beta));       
    printf("Die Strecke s betraegt: %g Meter\n", s);
    printf("Der winkel Alpha betraegt: %g Grad\n", alpha);
    printf("Der Winkel Beta betraegt: %g Grad\n", beta);
    printf("Der Winkel phi betraegt: %g Grad\n", phi(alpha, beta));

    return 0;
}