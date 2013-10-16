#lab4

###Zadanie 1: Zbieranie danych od wszystkich procesów
Przypomnij sobie poprzedni program. Jeśli pamiętasz, to aby zsumować wyniki cząstkowe należało wykonać serię komend wysyłania i odbierania. `MPI` umożliwia na wygodną komunikację w takich przypadkach. Zobacz komendę `MPI_Reduce`. Nasz program zliczający sumę liczb może w takiej sytuacji działać tak:

 1. wygeneruj ciąg liczb `(*)`,
 2. zsumuj swoją część liczb (czyli od `rank*rozmiar/iloscprocesow` do `(rank+1)*rozmiar/iloscprocesow`),
 3. wykonaj `MPI_Reduce` z opcją `MPI_SUM`,
 4. Wyświetl wynik na `procesie 0`.

`(*)` Cały czas wszystkie procesy niepotrzebnie generują cały ciąg liczb.

Wykorzystaj `MPI_Reduce` tak jak opisano wyżej.

###Zadanie 2: Rozsyłanie danych do wszystkich
`MPI_Bcast` służy do rozsyłania danych do wszystkich procesów.

Wykorzystajmy to do rozesłania wektora, który wygenerujemy tylko na `procesie 0`. Powinno się udać tak przerobić nasz program, aby było:

 1.  wygeneruj ciąg liczb na `procesie 0`,
 2. `MPI_Bcast` - wysyłamy cały ciąg liczb do wszystkich,
 3. zsumuj swoją część liczb (`rank*rozmiar/iloscprocesow` do `(rank+1)*rozmiar/iloscprocesow`),
 4. wykonaj `MPI_Reduce` z opcją `MPI_SUM`,
 5. Wyświetl wynik na `procesie 0`.

