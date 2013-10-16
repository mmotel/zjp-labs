#[lab4](https://github.com/mmotel/zjp-labs/tree/master/lab4/zad1)

###[Zadanie 2](https://github.com/mmotel/zjp-labs/tree/master/lab4/zad2): Rozsyłanie danych do wszystkich
`MPI_Bcast` służy do rozsyłania danych do wszystkich procesów.

Wykorzystajmy to do rozesłania wektora, który wygenerujemy tylko na `procesie 0`. Powinno się udać tak przerobić nasz program, aby było:

 1.  wygeneruj ciąg liczb na `procesie 0`,
 2. `MPI_Bcast` - wysyłamy cały ciąg liczb do wszystkich,
 3. zsumuj swoją część liczb (`rank*rozmiar/iloscprocesow` do `(rank+1)*rozmiar/iloscprocesow`),
 4. wykonaj `MPI_Reduce` z opcją `MPI_SUM`,
 5. Wyświetl wynik na `procesie 0`.

