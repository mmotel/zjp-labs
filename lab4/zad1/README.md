#[lab4](https://github.com/mmotel/zjp-labs/tree/master/lab4/zad1)

###Zadanie 1: Zbieranie danych od wszystkich procesów
Przypomnij sobie poprzedni program. Jeśli pamiętasz, to aby zsumować wyniki cząstkowe należało wykonać serię komend wysyłania i odbierania. `MPI` umożliwia na wygodną komunikację w takich przypadkach. Zobacz komendę `MPI_Reduce`. Nasz program zliczający sumę liczb może w takiej sytuacji działać tak:

 1. wygeneruj ciąg liczb `(*)`,
 2. zsumuj swoją część liczb (czyli od `rank*rozmiar/iloscprocesow` do `(rank+1)*rozmiar/iloscprocesow`),
 3. wykonaj `MPI_Reduce` z opcją `MPI_SUM`,
 4. Wyświetl wynik na `procesie 0`.

`(*)` Cały czas wszystkie procesy niepotrzebnie generują cały ciąg liczb.

Wykorzystaj `MPI_Reduce` tak jak opisano wyżej.
