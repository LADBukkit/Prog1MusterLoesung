/* u05a - Numerik
 * 28.04.2020 - Marcel Transier
 * Btw: Ihr müsst in den Abgaben nicht soo übertreiben mit den Kommentaren.
 *      Hier sind nur so ausführliche, um alles verständlich zu machen :)
 */

#include <stdio.h>
#include <limits.h> /* für INT_MAX */

int zuGanzzahl(char c) {
  /* Die statische Variable `zahl` merkt sich den aktuellen Zahlenwert auch
   * über das Verlassen der Funktion hinaus. Somit kann die Funktion jeweils
   * alleine mit dem anzuhängenden Ziffernzeichen aufgerufen werden.
   */
  static int zahl = 0;

  /* Ziffernzeichen `c` in Dezimalzahl umwandeln:
   * Eine ASCII Tabelle hilft zum Verstehen. (z.B.: `man 7 ascii`)
   * Jedem ASCII Zeichen ist eine Zahl zugeordnet.
   * Die Ziffern in der ASCII Tabelle sind von 0 bis 9 sortiert.
   * Wenn wir also den ASCII-Wert des Ziffernzeichen 0 von von dem ASCII-Wert
   * eines beliebigen Ziffernzeichens abziehen erhalten wir den tatsächlichen
   * Wert dieser Ziffer.
   * Damit berechnen wir ja den Abstand von 2 Zeichen. Und der Abstand von '0'
   * zu '0' ist 0. Und der Abstand von '0' zu '2' ist 2. Und so weiter.
   */
  int i = c - '0';

  /* Als nächstes werden wir die aktuelle `zahl` mit 10 multiplizieren und
   * dann i drauf addieren.
   * Z.B.: `zahl` ist 4 und wir wollen 2 anhängen. 4*10 = 40; +2 = 42
   *
   * Da wir aber einen Integer-Overflow (Ganzzahlen-Überlauf) verhindern
   * wollen, müssen wir, bevor wir etwas mit `zahl` machen, überprüfen, ob es
   * zu einem Überlauf führen würde.
   * Da wir ja vorhaben `zahl` mit 10 zu multiplizieren können wir schonmal
   * sagen: Wenn `zahl` größer als ein 10tel von INT_MAX ist, dann wird `zahl`
   * bei einer Multiplikation mit 10 mit Sicherheit INT_MAX überschreiten.
   *    2147483647  | /10
   *  = 214748364
   * Aber was passiert wenn die `zahl` genau ein 10tel von INT_MAX ist?
   * Dann hängt es von `i` das auf die bereits mit 10 multipliziert `zahl`
   * addiert werden soll ab.
   * Nur wenn `i` größer als 7 ist gibt es einen Überlauf.
   * Aber weil INT_MAX auf verschiedenen theoretisch einen unterschiedlichen
   * Wert haben kann, benutzen wir `INT_MAX % 10` statt fest 7.
   */
  if (zahl > (INT_MAX / 10) || (zahl == (INT_MAX / 10) && i > INT_MAX % 10)) {
    /* Das Anhängen der Ziffer würde einen Überlauf verursachen.
     * Die Funktion wird abgebrochen und gibt die bisherige Zahl zurück.
     */
    return zahl;
  }

  /* `zahl` mit 10 multiplizieren und `i` drauf addieren:
   * Z.B.:
   * zahl = 133; wir wollen die 7 anhängen.
   * 133 * 10 = 1330
   * 1330 + 7 = 1337
   */
  zahl *= 10;
  zahl += i;

  return zahl;
}

double zuDouble(char c) {
  /* Das gleiche wie bei zuGanzzahl(), nur mit einem double
   * und aufgrund dessen, dass es bei doubles keinen Überlauf gibt
   * auch ohne Überlauferkennung.
   */
  static double zahl = 0;

  zahl *= 10;
  zahl += (c - '0');

  return zahl;
}

int main() {
  char c;
  int iErg = 0;
  double dErg = 0;

  /* Im Schleifenkopf wird ein Zeichen eingelesen und in `c` gespeichert
   * und es wird direkt die Überprüfung, dass das eingelesene Zeichen nicht
   * EOF ist als Bedingung verwendet.
   */
  while((c = getchar()) != EOF) {
    /* Wenn das eingelesene Zeichen ein Ziffernzeichen ist
     * werden die Funktionen aufgerufen und das Ergebniss gespeichert.
     */
    if (c >= '0' && c <= '9') {
      iErg = zuGanzzahl(c);
      dErg = zuDouble(c);
    }
  }

  /* Nachdem EOF gelesen wurde und die while Schleife somit beendet wurde
   * werden die Ergebnisse ausgegeben.
   */
  printf("%d\n", iErg);
  printf("%.18e\n", dErg);

  return 0;
}
