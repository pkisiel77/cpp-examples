## Zadanie 1
Jesteś programistą w firmie zajmującej się dystrybucją filmów. Twoim zadaniem jest stworzenie systemu, który pozwoli na zarządzanie biblioteką filmów.

Każdy film w bibliotece posiada unikalny tytuł oraz ocenę (liczbę zmiennoprzecinkową w zakresie od 1.0 do 5.0). Tytuł filmu służy jako klucz, a ocena filmu jest wartością w strukturze std::map.

Stwórz klasę MovieLibrary, która zawiera prywatną std::map<std::string, double> reprezentującą bibliotekę filmów. Ta klasa powinna zawierać następujące metody:

- addMovie(const std::string& title, double rating): dodaje nowy film do biblioteki. Jeżeli film o takim tytule już istnieje, powinna zostać zwrócona odpowiednia informacja.
- removeMovie(const std::string& title): usuwa film o podanym tytule z biblioteki. Jeżeli film o takim tytule nie istnieje, powinna zostać zwrócona odpowiednia informacja.
- getRating(const std::string& title): zwraca ocenę filmu o danym tytule. Jeżeli film o takim tytule nie istnieje, powinna zostać zwrócona odpowiednia informacja.
- getAverageRating(): oblicza i zwraca średnią ocenę wszystkich filmów w bibliotece.
- getHighestRatedMovie(): zwraca tytuł filmu z najwyższą oceną. Jeżeli w bibliotece nie ma żadnych filmów, powinna zostać zwrócona odpowiednia informacja.

W funkcji main, stwórz obiekt MovieLibrary i dodaj do niego kilka filmów. Następnie przetestuj wszystkie funkcje klasy MovieLibrary.

Pamiętaj o obsłudze potencjalnych błędów, takich jak próba usunięcia lub odczytania oceny filmu, którego nie ma w bibliotece.
