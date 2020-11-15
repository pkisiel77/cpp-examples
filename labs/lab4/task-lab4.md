# Kontenery w C++

Należy zaimplementować system dla działu HR w firmie.
1. Gdy w poniższych wymaganiach mowa jest o kontenerze należy zastosować
jeden z poniższych kontenerów (właściwy dla danego wymagania):
• std::stack
• std::vector
• std::queue
• std::list
• std::map
2. Należy zaimplementować klasę Employee z następującymi polami:
• id: string - identyfikator pracownika
• name: string
• surname: string
• departmentId: string - identyfikator działu w którym pracuje dane
osoba
• position: string - stanowisko na którym pracuje dana osoba
3. Należy zaimplementować klasę HRMS służącą do zarządzania pracownikami.
Klasa ma mieć następujące składowe:
• kontener w którym będą przechowywani wszyscy pracownicy
• kontener w którym będzie przechowywane mapowanie pomiędzy
identyfikatorami departamentów a identyfikatorami wszystkich
pracowników danego departamentu
• kontener przechowywujący informacje o zarobkach pracowników
1
• metoda add(Employee employee, std::string departmentId, double
salary) dodająca użytkownika do systemu, do danego departamentu,
mającego dane wynagrodzenie
• metoda printDepartment(std::string departmentId) wypisująca
wszystkich pracowników danego departamentu
• metoda changeSalary(std::string employeeId, double salary) - metoda
zmieniająca wynagrodzenie danego pracownika
• metoda printSalaries() wypisująca wynagrodzenia wszystkich pracowników,
wraz z informacjami o tych pracownikach
• metoda printSalariesSorted() wypisująca wynagrodzenia wszystkich
pracowników, wraz z informacjami o tych pracownikach, w
kolejności malejącego wynagrodzenia (sortowanie ma być wykonana
z użyciem std::algorithm)
4. Należy zaimplementować metodę main demonstrującą działanie powyższego
kodu dla co najmniej 10 pracowników pracujących co najmniej
w 3 departamentach
2
