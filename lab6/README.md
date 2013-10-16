#lab6

###[test](https://github.com/mmotel/zjp-labs/tree/master/lab6/test)

Prosty test `OpenMP`.

###[Zadanie 1](https://github.com/mmotel/zjp-labs/tree/master/lab6/zad1)

Napisz program wykonujący współbieżnie `sumowanie elementów w tablicy` liczb stałoprzecinkowych. Na początku zaimplementuj `wersję sekwencyjną`, a następnie `wersję OpenMP`. Proponuję najpierw poprzez zwykłe zrównoleglenie pętli, a następnie poprzez wykorzystanie dodatkowo `reduce`. Porównaj czasy wykonania. Jaka wersja jest szybsza? Proponuję sprawdzić dla tablic o `rozmiarze 10000 lub większych`.

Kolejny etap to zrównoleglenie generowania takiej tablicy (już zaimplementowany). 

###[Zadanie 2](https://github.com/mmotel/zjp-labs/tree/master/lab6/zad2)

Napisz program wykonujący współbieżnie `mnożenie macierzy kwadratowych`. Na początku zaimplementuj `wersję sekwencyjną`, a następnie `wersję OpenMP`. Dodaj jakąś metodę pomiaru czasu (np `clock_gettime`). Sprawdź, czy lepiej zrównoleglać pętlę wewnętrzną czy zewnętrzną. Porównaj czasy wykonania. Jaka wersja jest szybsza? Proponuję sprawdzić dla tablic o `rozmiarze 10000 lub większych`.


