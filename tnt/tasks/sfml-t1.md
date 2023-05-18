Utwórz abstrakcyjną klasę bazową Figura, która zawiera:

- Wirtualną metodę pole zwracającą wartość typu double. Metoda ta nie powinna mieć żadnej implementacji w klasie Figura.
- Wirtualną metodę opis zwracającą string. Metoda ta nie powinna mieć żadnej implementacji w klasie Figura.
- Następnie stwórz dwie klasy dziedziczące po klasie Figura: Kwadrat i Kolo. Każda z tych klas powinna zawierać:

- Prywatny atrybut do przechowywania długości boku (w przypadku Kwadrat) lub promienia (w przypadku Kolo).
- Konstruktor, który przyjmuje wartość do ustawienia tego atrybutu.
- Implementację metody pole, która oblicza i zwraca pole odpowiedniej figury.
- Implementację metody opis, która zwraca opis figury wraz z jej wymiarami.

W funkcji main:

- Utwórz tablicę wskaźników typu Figura.
- Stwórz obiekty typu Kwadrat i Kolo, a następnie umieść je w tablicy.
- Iterując po tablicy, wywołaj metody opis i pole dla każdego obiektu.
- Odpowiedź powinna zawierać definicje klas Figura, Kwadrat i Kolo, a także kod demonstrujący użycie tych klas w funkcji main. 
- Upewnij się, że program prawidłowo wykorzystuje polimorfizm, 
pozwalając na przechowywanie różnych typów obiektów w tablicy wskaźników do klasy bazowej i prawidłowe wywoływanie odpowiednich metod dla każdego typu obiektu.
