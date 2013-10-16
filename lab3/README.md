#lab3

###[Zadanie 2](https://github.com/mmotel/zjp-labs/tree/master/lab3/zad2)
Napisz program, który prześle liczbę całkowitą z `procesu 1` do `procesu 0`, `proces 0` ma ją wyświetlić.

###[Zadanie 3](https://github.com/mmotel/zjp-labs/tree/master/lab3/zad3)
Pamiętasz program liczący sumę za pomocą fork? Teraz spróbuj to zrobić za pomocą `MPI`

* Na początek - pomiar czasu, aby miał sens, powinien znajdować się jak najbliżej faktycznych obliczeń. Zapytaj prowadzącego czy twoje rozwiązanie jest dobre jeśli nie jesteś absolutnie pewien że jest OK.
* Pomiar czasu należy rozpocząć przed pętlą sumującą, a zakończyć zaraz po niej. Każdy proces powinien wyświetlić ten czas.
* Na początek nie musisz dodawać przesyłania danych za pomocą `MPI`. Zobacz czy po prostu to zadziała.
* Kolejnym krokiem jest zebranie wyników cząstkowych za pomocą `MPI_Send` i `MPI_Recv`. Zobacz czy to działa. Proponuję zadawać pytania. 

###[Zadanie 4](https://github.com/mmotel/zjp-labs/tree/master/lab3/zad4)
Napisz program, który prześle żeton przez wszystkie procesy, to znaczy:

 1. `Jednostka 0` wczytuje liczbę całkowitą, wysyła ją do `jednostki 1`,
 2. `jednostka 1` przesyła otrzymaną liczbę do `jednostki 2`,
 3. i tak dalej,
 4. `ostatnia jednostka` przesyła liczbę do `jednostki 0`,
 5. `jednostka 0` odczytuje tą liczbę i wyświetla na ekranie.
 6. Można zrobić tak, aby każdy proces wyświetlał komunikat w momencie otrzymania żetonu. 
