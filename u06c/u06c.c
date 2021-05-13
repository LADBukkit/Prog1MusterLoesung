/*
Name: Dominic Meyer
Datum: 12.5.21
Beschreibung: Arrays befuellen, ausgeben, Statistiken dazu erstellen und sortieren
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define SIZEMYARRAY 1000                                                        //definieren von festen Groessen der Arrays
#define SIZEMYSTAT 10

void init(int intArr[], int arrSize)                                            //Parameter bestehen aus einem Array und passend dazu die Groesse des Arrays
{
    for(int i = 0; i < arrSize; i++)                                            //Liste durchgehen, um jeder Stelle des Arrays eine Zufallszahl zuzuweisen
    {
        intArr[i] = (rand() % 1000) + 1;                                        //die generierte Zufallszahl Modulo 1000 rechnen, damit wir nur Zahlen <= 1000 bekommen
    }                                                                           //+1, damit es bei 1 anfaengt
}

void ausgabe(int intArr[], int arrSize)
{
    for(int i = 0; i < arrSize; i++)                                            //Array von vorne bis hinten durchgehen
    {   
        if((i % 10) == 0)                                                       //Wenn i restlos durch 10 teilbar ist, machen wir einen Zeilenumbruch --> 10 Zahlen pro Zeile
        {
            printf("\n");
        }
        printf("%4d\t", intArr[i]);                                             //%4d\t --> 4, es werden 4 Stellen fuer das Integer reserviert. \t --> Tab
    }
    printf("\n");                                                               //\n fuer schoenere Ausgabe
}

void statistik(int myArray[], int mystat[], int sizeMyArray, int sizeMyStat)    //Parameter sind 2 Arrays und die Groesse von den Arrays
{
    for(int i = 0; i < sizeMyArray; i++)                                        //wir gehen das Array von vorne bis hinten durch
    {
        if(myArray[i] > 900)                                                    //wenn die Zahl von myArray an der Stelle i groesser als 900 ist, 
        {
            mystat[9]++;                                                        //wir mystat an der Stelle 9 um eins erhoeht und somit auch die Statistik fuer Zahlen 
        }                                                                       //die zwischen 901 und 1000 liegen
        else if (myArray[i] > 800)                                              //genau die gleiche Abfrage machen wir fuer die darunterkiegenden Zahlenbereiche
        {
            mystat[8]++;                                                        //es wird entsprechend mystat veraendert
        }
        else if (myArray[i] > 700)
        {
            mystat[7]++;
        }
        else if (myArray[i] > 600)
        {
            mystat[6]++;
        }
        else if (myArray[i] > 500)
        {
            mystat[5]++;
        }
        else if (myArray[i] > 400)
        {
            mystat[4]++;
        }
        else if (myArray[i] > 300)
        {
            mystat[3]++;
        }
        else if (myArray[i] > 200)
        {
            mystat[2]++;
        }
        else if(myArray[i] > 100)
        {
            mystat[1]++;
        }
        else
        {
            mystat[0]++;
        }
    }
}

int suche(int intArr[], int arrSize, int gesuchteZahl)                          //Parameter ist ein Array, die Groesse des Arrays und die gesuchte Zahl
{
    for(int i = 0; i < arrSize; i++)                                            //wir gehen das Array von vorne bis hinten durch
    {
        if(intArr[i] == gesuchteZahl)                                           //an jder Stelle des Arrays ueberpruefen wir, ob die Zahl gleich der gesuchten Zahl ist
        {
            return i;                                                           //wenn ja, wird der Index zurueckgegeben
        }
    }
    return -1;                                                                  //wenn díe gesuchte Zahl nicht gefunden wurde, soll -1 zurueckgegeben werden
}

void tausche(int intArr[], int index1, int index2)                              //Parameter sind ein Array und zwei Indizes
{
    int hilfs = intArr[index1];                                                 //wir erstellen eine Hilfsvariable in der wir den Wert vom Array an der Stelle index1 speichern
    intArr[index1] = intArr[index2];                                            //intArr an der Stelle index1 bekommt den Wert von intArr an der Stelle index2
    intArr[index2] = hilfs;                                                     //intArr an der Stelle index2 bekommt den vorher zwischengespeicherten Wert hilfs 
}                                                                               //(alter Wert von intArr[index1])

void sortiere(int intArr[], int arrSize)                                        //Bubblesort-Algorithmus vom sortieren von Zahlen (von klein nach gross)
{
    for(int n = arrSize; n > 1; n--)
    {
        for(int i = 0; i < n-1; i++)
        {
            if (intArr[i] > intArr[i + 1])
            {
                tausche(intArr, i, i + 1);
            }
        }
    }
}

int main()
{
    srand(time(NULL));                                                          //einmaliger Aufruf, damit wir rand() benutzen koennen
    int myarray[SIZEMYARRAY] = {0};                                             //wir initialisieren das Array mit Nullen --> an jeder Speicherstelle des Arrays steht eine 0
    int mystat[SIZEMYSTAT] = {0};
    int gesuchteZahl = 0;
    int index = 0;

    init(myarray, SIZEMYARRAY);                                                 //myarray wird mit Zufallszahlen befuellt
    ausgabe(myarray, SIZEMYARRAY);                                              //Ausgabe von myarray

    printf("\n\nHaeufigkeitsverteilung: \n");
    statistik(myarray, mystat, SIZEMYARRAY, SIZEMYSTAT);                        //Aufruf der Funktion Statistik
    ausgabe(mystat, SIZEMYSTAT);                                                //Ausgabe von mystat (hier wird die Statistik gespeichert)

    printf("\nBitte geben Sie eine Zahl ein, die Sie finden moechten: ");       //Benutzer gibt eine Zahl ein, die er finden moechte
    scanf("%d", &gesuchteZahl);
    index = suche(myarray, SIZEMYARRAY, gesuchteZahl);                          //suche Funktion wird aufgerufen, Rueckgabewert wird in index gespeichert
    if(index != -1)                                                             //wenn suche die Zahl gefunden hat, ist der Rueckgabewert ungleich -1
    {
        printf("\nDie gesuchte zahl ist an der Stelle %d im Array\n", index);
    }
    else                                                                        //Rueckgabewert ist -1
    {
        printf("\nDie Zahl wurde nicht gefunden!\n");
    }

    printf("\nDas sortierte Array:");
    sortiere(myarray, SIZEMYARRAY);                                             //Array wird sortiert 
    ausgabe(myarray, SIZEMYARRAY);                                              //und ausgegeben

    return 0;
}