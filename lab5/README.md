#lab5

###[test](https://github.com/mmotel/zjp-labs/tree/master/lab5/test)

Prosty test `MPI_Scatter-a` oraz `MPI_Gather-a`.

###[Zadanie 1](https://github.com/mmotel/zjp-labs/tree/master/lab5/zad1)

Zadanie na ćwiczenia to napisać program który:

 1. W `procesie 0` wygeneruje tablicę o `rozmiarze` takim jak `ilość procesów` i wypełni ją kolejnymi liczbami pseudolosowymi,
 2. Roześle fragmenty tablicy do `wszystkich procesów` (za pomocą `MPI_Scatter`, czyli każdy proces otrzyma jedną liczbę),
 3. Każdy proces wygeneruje 4 liczby za pomocą generatora liczb pseudolosowych z ustawionym ziarnem generatora na wartość otrzymaną z `procesu 0`,
 4. Wyniki zostaną zebrane (za pomocą `MPI_Gather`) do `procesu 0` i na nim wyświetlone. 
