#lab3

###Zadanie 3
Pamiętasz program liczący sumę za pomocą fork? Teraz spróbuj to zrobić za pomocą `MPI`

* Na początek - pomiar czasu, aby miał sens, powinien znajdować się jak najbliżej faktycznych obliczeń. Zapytaj prowadzącego czy twoje rozwiązanie jest dobre jeśli nie jesteś absolutnie pewien że jest OK.
* Pomiar czasu należy rozpocząć przed pętlą sumującą, a zakończyć zaraz po niej. Każdy proces powinien wyświetlić ten czas.
* Na początek nie musisz dodawać przesyłania danych za pomocą `MPI`. Zobacz czy po prostu to zadziała.
* Kolejnym krokiem jest zebranie wyników cząstkowych za pomocą `MPI_Send` i `MPI_Recv`. Zobacz czy to działa. Proponuję zadawać pytania. 
