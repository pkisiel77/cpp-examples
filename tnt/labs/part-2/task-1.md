## Zadanie 1:

Stwórz klasę o nazwie Samochod. Klasa powinna mieć następujące prywatne atrybuty:

marka: string przechowujący markę samochodu.
model: string przechowujący model samochodu.
rokProdukcji: liczba całkowita przechowująca rok produkcji samochodu.
przebieg: liczba całkowita przechowująca przebieg samochodu.
Dodaj publiczne metody dostępowe do tych atrybutów (gettery i settery). Pamiętaj, że niektóre z tych wartości (np. rokProdukcji i przebieg) nigdy nie powinny być ujemne.

Dodaj konstruktor, który przyjmuje marka, model i rokProdukcji jako argumenty. Przebieg powinien być ustawiony na 0 podczas tworzenia nowego obiektu.

## Zadanie 2:

Dodaj do klasy Samochod następujące metody:

jedz: ta metoda powinna przyjmować odległość jako argument i zwiększać wartość przebieg o tę odległość. Powinna również wydrukować informację o tym, ile samochód przejechał i jaki jest teraz jego całkowity przebieg.

informacje: ta metoda powinna wydrukować informacje o samochodzie, tj. markę, model, rok produkcji i przebieg.

## Zadanie 3:

Stwórz klasę SportowySamochod, która dziedziczy po klasie Samochod. Ta klasa powinna mieć dodatkowy atrybut maksymalnaPredkosc, który jest prywatny i ma własne metody dostępowe (gettery i settery). Wartość maksymalnej prędkości nie powinna być ujemna.

Dodaj do klasy SportowySamochod metodę turbo, która zwiększa wartość maksymalnaPredkosc. Metoda ta powinna przyjmować jako argument wartość, o którą zwiększana jest prędkość.

## Zadanie 4:

Stwórz kilka obiektów klasy Samochod i SportowySamochod i użyj metod jedz, informacje i turbo do symulacji jazdy tymi samochodami i wyświetlania ich stanu.
