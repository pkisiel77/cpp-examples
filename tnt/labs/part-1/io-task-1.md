## Zadanie
Napisz program w języku C++, który pozwala na aktualizowanie danych w pliku tekstowym. 
Program powinien umożliwić wprowadzanie nowych danych do pliku oraz edycję już istniejących danych.

## Wymagania

- Program powinien otwierać plik o określonej nazwie i ścieżce, która zostanie podana przez użytkownika.
- Program powinien umożliwiać wprowadzanie nowych danych do pliku poprzez dodanie ich na końcu pliku.
- Program powinien umożliwiać edycję istniejących danych w pliku poprzez podanie indeksu lub klucza danej, którą chcemy zmienić.
- Program powinien umożliwiać wyświetlenie zawartości pliku.

## Sugestie

- Aby umożliwić edycję danych, można wykorzystać struktury danych, takie jak tablica do przechowywania danych z pliku.
- Aby ułatwić wprowadzanie danych, można dodać funkcję, która pozwala na wprowadzanie danych jednocześnie dla wielu pól.

## Uwaga 

Program powinien być czytelny, zawierać komentarze i być zgodny z dobrymi praktykami programowania w C++.

## Kod

```cpp
fstream plik; 
plik.open("nazwa_pliku.txt", ios::out);
```

