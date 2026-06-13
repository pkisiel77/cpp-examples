# Checklista projektu zaliczeniowego

Użyj tej listy przed oddaniem projektu i podczas krótkiego pokazu działania.
Lista pomaga sprawdzić, czy projekt spełnia wariant minimum, czy da się go
uruchomić na czystym stanowisku i czy student potrafi wyjaśnić własne decyzje.

## 1. Wariant minimum

- [ ] Projekt realizuje wszystkie punkty z sekcji `Minimalny wariant zaliczeniowy`.
- [ ] Menu albo główny sposób obsługi jest zrozumiały bez czytania kodu.
- [ ] Podstawowy przypadek użycia działa od początku do końca.
- [ ] Program obsługuje co najmniej jeden przypadek błędnych danych.
- [ ] Program nie kończy się awaryjnie po typowym błędzie użytkownika.

## 2. Kompilacja i uruchomienie

- [ ] W `README.md` projektu jest komenda kompilacji.
- [ ] W `README.md` projektu jest komenda uruchomienia.
- [ ] Projekt kompiluje się z flagami `-Wall -Wextra -pedantic`.
- [ ] Projekt nie wymaga plików wygenerowanych wcześniej ręcznie.
- [ ] W repozytorium nie ma artefaktów build, np. `.o`, `.exe`, binariów ani katalogu `build` z wynikiem kompilacji.

## 3. Organizacja kodu

- [ ] Kod jest podzielony na funkcje albo metody zgodnie z odpowiedzialnościami.
- [ ] W większym projekcie funkcja `main` uruchamia program, ale nie zawiera całej logiki.
- [ ] Pliki źródłowe mają czytelne nazwy.
- [ ] Jeśli projekt ma kilka modułów, deklaracje i implementacje są rozdzielone na `.h` i `.cpp`.
- [ ] Nazwy zmiennych, funkcji, klas i plików opisują ich rolę.

## 4. Dane i błędy

- [ ] Program sprawdza poprawność danych wpisanych przez użytkownika.
- [ ] Operacje na plikach sprawdzają, czy odczyt albo zapis się powiódł.
- [ ] Pusty zestaw danych jest obsłużony w przewidywalny sposób.
- [ ] Przypadki graniczne są opisane albo przetestowane.
- [ ] Komunikaty błędów pomagają użytkownikowi poprawić dane.

## 5. Testy i scenariusze sprawdzenia

- [ ] Projekt ma testy automatyczne albo listę ręcznych scenariuszy sprawdzenia.
- [ ] Jest scenariusz dla poprawnych danych.
- [ ] Jest scenariusz dla danych błędnych.
- [ ] Jest scenariusz dla danych granicznych, np. pusta lista, zero, brak pliku.
- [ ] Student potrafi uruchomić te scenariusze podczas odbioru projektu.

## 6. Dokumentacja projektu

- [ ] `README.md` opisuje cel projektu.
- [ ] `README.md` opisuje strukturę katalogów i najważniejsze pliki.
- [ ] `README.md` opisuje wariant minimum.
- [ ] Rozszerzenia są oddzielone od wariantu minimum.
- [ ] Ograniczenia albo znane braki są opisane uczciwie.

## 7. Pokaz i omówienie

- [ ] Student potrafi uruchomić projekt bez pomocy prowadzącego.
- [ ] Student potrafi wskazać najważniejsze funkcje, klasy albo moduły.
- [ ] Student potrafi wyjaśnić, gdzie program przechowuje dane.
- [ ] Student potrafi pokazać obsługę błędnego wejścia.
- [ ] Student potrafi powiedzieć, co dodałby w kolejnej wersji.

## 8. Rozszerzenia

- [ ] Rozszerzenia działają dopiero po stabilnym wariancie minimum.
- [ ] Rozszerzenia są opisane w dokumentacji.
- [ ] Rozszerzenia nie psują podstawowych scenariuszy.
- [ ] Dla rozszerzeń istnieje krótki scenariusz sprawdzenia.
