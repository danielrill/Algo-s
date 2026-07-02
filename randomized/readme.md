# Randomisierte Algorithmen in C

Dieses Projekt implementiert mehrere klassische randomisierte Algorithmen in C und demonstriert deren Anwendung anhand eines Testprogramms. Der Fokus liegt auf Algorithmen, die Zufall nutzen, um in der Praxis oft sehr gute Laufzeiten oder einfache probabilistische Korrektheitsgarantien zu erreichen.

## Enthaltene Algorithmen

1. Randomized primality testing
2. Freivalds' algorithm for matrix products
3. Randomized Quicksort
4. Randomized computation of kth largest element
5. Karger's algorithm to compute min-cut in a graph

---

## 1. Randomized primality testing

### Themenbereich
- Zahlentheorie
- Kryptographie
- Algorithmische Mathematik
- Probabilistische Verifikation

### Einsatzgebiete
- Schnelles Testen, ob eine große Zahl wahrscheinlich prim ist
- Vorbereitung für Schlüsselerzeugung in kryptographischen Verfahren
- Vorfilter vor exakteren Primzahltests

### Grundidee
Ein randomisierter Primzahltest prüft mit zufällig gewählten Basen, ob eine Zahl zusammengesetzt ist. In dieser Implementierung wird der **Miller-Rabin-Primzahltest** verwendet. Er ist ein probabilistischer Test:

- Ist die Zahl sicher zusammengesetzt, wird das oft schnell erkannt.
- Besteht die Zahl mehrere unabhängige Tests, ist sie mit hoher Wahrscheinlichkeit prim.

### Mathematische Interpretation
Für eine ungerade Zahl $$n > 2$$ schreibt man:

$$
n - 1 = 2^s \cdot d
$$

mit ungeradem $$d$$. Für zufällig gewählte Basen $$a$$ wird geprüft, ob

$$
a^d \mod n
$$

oder eine der Folgezahlen

$$
a^{2^r d} \mod n \quad \text{für } 0 \le r < s
$$

Eigenschaften zeigt, die bei Primzahlen zu erwarten sind. Falls nicht, ist $$n$$ sicher zusammengesetzt.

### Korrektheitsidee
- Gibt der Algorithmus "zusammengesetzt" aus, ist das korrekt.
- Gibt er "wahrscheinlich prim" aus, gibt es eine kleine Fehlerwahrscheinlichkeit.
- Nach $$k$$ unabhängigen Iterationen ist der Fehler höchstens exponentiell klein, grob $$\le (1/4)^k$$ für ungerade zusammengesetzte Zahlen.

### Laufzeit
Eine Iteration benötigt modulare Exponentiation.

- **Zeit pro Runde:** $$O(\log^3 n)$$ bei einfacher Arithmetik
- **Gesamtzeit:** $$O(k \log^3 n)$$
- **Best Case:** $$\Omega(\log^3 n)$$
- **Tight Bound für feste Rundenzahl:** $$\Theta(k \log^3 n)$$

Bei maschinennahen Ganzzahlen hängt die tatsächliche Laufzeit von der Wortbreite ab.

---

## 2. Freivalds' algorithm for matrix products

### Themenbereich
- Lineare Algebra
- Randomisierte Verifikation
- Matrixalgorithmen

### Einsatzgebiete
- Schnelle probabilistische Prüfung, ob $$A \cdot B = C$$ gilt
- Verifikation teurer Matrixmultiplikationen
- Numerische und symbolische Rechenumgebungen

### Grundidee
Statt $$A \cdot B$$ vollständig auszurechnen, wählt der Algorithmus einen zufälligen Vektor $$r$$ und prüft:

$$
A(Br) \stackrel{?}{=} Cr
$$

Falls $$AB = C$$ gilt, ist die Gleichung immer korrekt. Falls $$AB \ne C$$ gilt, erkennt Freivalds den Fehler mit mindestens konstanter Wahrscheinlichkeit.

### Mathematische Interpretation
Sei

$$
D = AB - C
$$

Dann wird getestet, ob

$$
Dr = 0
$$

für einen zufälligen Vektor $$r \in \{0,1\}^n$$. Falls $$D \ne 0$$, gilt:

$$
P[Dr = 0] \le \frac{1}{2}
$$

pro Iteration.

### Korrektheitsidee
- Falls $$AB=C$$, akzeptiert der Algorithmus immer.
- Falls $$AB \ne C$$, wird ein Fehler mit Wahrscheinlichkeit mindestens $$1/2$$ entdeckt.
- Nach $$k$$ Wiederholungen sinkt die Fehlerwahrscheinlichkeit auf höchstens:

$$
\left(\frac{1}{2}\right)^k
$$

### Laufzeit
Eine Runde benötigt mehrere Matrix-Vektor-Produkte.

- **Zeit pro Runde:** $$O(n^2)$$
- **Gesamtzeit:** $$O(k n^2)$$
- **Best Case:** $$\Omega(n^2)$$
- **Tight Bound:** $$\Theta(k n^2)$$

Das ist deutlich besser als eine vollständige Matrixmultiplikation mit der klassischen Methode $$O(n^3)$$.

---

## 3. Randomized Quicksort

### Themenbereich
- Sortieren
- Divide-and-Conquer
- Randomisierte Algorithmen

### Einsatzgebiete
- Allgemeines Sortieren von Arrays
- Praktische Bibliotheks- und Systemimplementierungen
- Situationen, in denen gute durchschnittliche Performance wichtig ist

### Grundidee
Quicksort wählt ein Pivot und teilt das Array in kleinere und größere Elemente. Beim **randomisierten Quicksort** wird das Pivot zufällig gewählt, um ungünstige Eingaben probabilistisch zu entschärfen.

### Mathematische Interpretation
Die Rekurrenz für die erwartete Laufzeit ist näherungsweise:

$$
T(n) = T(X) + T(n - X - 1) + \Theta(n)
$$

wobei $$X$$ zufällig von der Pivot-Wahl abhängt. Im Erwartungswert ergibt sich:

$$
E[T(n)] = \Theta(n \log n)
$$

### Korrektheitsidee
Partitionieren stellt sicher, dass nach jedem Schritt:
- links nur kleinere oder gleiche Elemente liegen,
- rechts nur größere Elemente liegen,
- und das Pivot an seiner endgültigen Position steht.

### Laufzeit
- **Erwartete Laufzeit:** $$O(n \log n)$$
- **Best Case:** $$\Omega(n \log n)$$
- **Worst Case:** $$O(n^2)$$
- **Erwartete Tight Bound:** $$\Theta(n \log n)$$

### Speicher
- Rekursionsstack durchschnittlich: $$O(\log n)$$
- Im Worst Case: $$O(n)$$

---

## 4. Randomized computation of kth largest element

### Themenbereich
- Selektion
- Ordnungstatistiken
- Divide-and-Conquer

### Einsatzgebiete
- Medianberechnung
- Top-k-Auswahl
- Rangstatistiken
- Datenanalyse und Streaming-Vorverarbeitung

### Grundidee
Gesucht ist das $$k$$-größte Element eines Arrays. Statt komplett zu sortieren, nutzt der Algorithmus eine randomisierte Partition wie bei Quicksort und arbeitet nur in dem Teilbereich weiter, der das gesuchte Element enthält.

Das ist die randomisierte **Quickselect**-Idee.

### Mathematische Interpretation
Wie bei Quicksort wird durch zufällige Pivot-Wahl die erwartete Problemgröße schnell reduziert. Die Rekurrenz im Erwartungswert führt zu:

$$
E[T(n)] = \Theta(n)
$$

### Korrektheitsidee
Nach der Partition liegt das Pivot an der Position, die es auch im vollständig sortierten Array hätte. Daraus kann man schließen:
- ist die Pivot-Position gleich der Zielposition, ist die Lösung gefunden,
- sonst wird rekursiv nur links oder rechts weitergesucht.

### Laufzeit
- **Erwartete Laufzeit:** $$O(n)$$
- **Best Case:** $$\Omega(n)$$
- **Worst Case:** $$O(n^2)$$
- **Erwartete Tight Bound:** $$\Theta(n)$$

### Speicher
- Durchschnittlicher Rekursionsbedarf: $$O(\log n)$$
- Iterative Implementierungen können zusätzlichen Speicher klein halten

---

## 5. Karger's algorithm to compute min-cut in a graph

### Themenbereich
- Graphentheorie
- Randomisierte Algorithmen
- Netzwerkanalyse

### Einsatzgebiete
- Approximation und probabilistische Suche nach minimalen Schnitten
- Netzwerkanalyse
- Robustheitsuntersuchungen von Graphen
- Theoretische Informatik

### Grundidee
Kargers Algorithmus kontrahiert zufällig Kanten, bis nur noch zwei Superknoten übrig bleiben. Die Anzahl der zwischen diesen beiden verbleibenden Kanten ist ein Schnitt. Mit einer gewissen Wahrscheinlichkeit ist dieser Schnitt minimal.

### Mathematische Interpretation
Ein minimaler Schnitt wird genau dann gefunden, wenn während der gesamten Kontraktion keine Kante dieses minimalen Schnitts gewählt wird.

Für einen Graphen mit $$n$$ Knoten ist die Erfolgswahrscheinlichkeit einer einzelnen Ausführung mindestens:

$$
\frac{2}{n(n-1)}
$$

Darum wiederholt man den Algorithmus mehrfach und nimmt das beste Ergebnis.

### Korrektheitsidee
Jede Kontraktion verschmilzt zwei Knoten und erhält Schnittstrukturen probabilistisch. Wird nie eine Kante eines globalen Min-Cuts kontrahiert, bleibt dieser bis zum Ende erhalten und wird gefunden.

### Laufzeit
Bei einfacher Implementierung mit Kantenliste und Disjoint-Set/naiver Kontraktion:

- **Pro Lauf:** ungefähr $$O(mn)$$ oder implementierungsabhängig
- **Mit hier genutzter einfacher Simulation:** typischerweise $$O(mn)$$
- **Bei $$R$$ Wiederholungen:** $$O(Rmn)$$

Asymptotisch:
- **Worst Case:** $$O(Rmn)$$
- **Best Case:** $$\Omega(Rm)$$
- **Praktische Abschätzung:** $$\Theta(Rmn)$$ für diese einfache Implementierung

Für hohe Erfolgswahrscheinlichkeit wählt man oft mehrere Wiederholungen, zum Beispiel in der Größenordnung $$O(n^2 \log n)$$, je nach gewünschter Fehlerwahrscheinlichkeit.

---

## Verwendete Notationen

### Big-O
Beschreibt eine asymptotische obere Schranke:

$$
f(n) = O(g(n))
$$

bedeutet, dass $$f(n)$$ höchstens so schnell wächst wie ein konstanter Faktor von $$g(n)$$.

### Big-Omega
Beschreibt eine asymptotische untere Schranke:

$$
f(n) = \Omega(g(n))
$$

### Theta
Beschreibt eine asymptotisch genaue Schranke:

$$
f(n) = \Theta(g(n))
$$

falls sowohl

$$
f(n) = O(g(n))
$$

als auch

$$
f(n) = \Omega(g(n))
$$

gilt.

---

## Hinweise zur Implementierung

- Die Implementierungen sind auf Verständlichkeit ausgelegt.
- Zufall wird über `rand()` erzeugt.
- Für ernsthafte Kryptographie sollte man stärkere Zufallsquellen und große Integer-Arithmetik verwenden.
- Der Primzahltest arbeitet hier mit `uint64_t`, also 64-Bit-Zahlen.
- Kargers Algorithmus ist probabilistisch und wird deshalb mehrfach wiederholt.

---

## Kompilierung

### Windows
```bat
build.bat
