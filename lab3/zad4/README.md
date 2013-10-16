#[lab3](https://github.com/mmotel/zjp-labs/tree/master/lab3)

###Zadanie 4
Napisz program, który prześle żeton przez wszystkie procesy, to znaczy:

 1. `Jednostka 0` wczytuje liczbę całkowitą, wysyła ją do `jednostki 1`,
 2. `jednostka 1` przesyła otrzymaną liczbę do `jednostki 2`,
 3. i tak dalej,
 4. `ostatnia jednostka` przesyła liczbę do `jednostki 0`,
 5. `jednostka 0` odczytuje tą liczbę i wyświetla na ekranie.
 6. Można zrobić tak, aby każdy proces wyświetlał komunikat w momencie otrzymania żetonu. 
