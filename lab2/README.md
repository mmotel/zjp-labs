#lab2

Za pomocą fork napisz program wykonujący sumę elementów tablicy. Powinien on dawać możliwość wybrania rozmiaru tablicy i ilości procesów. Wymiana danych może odbywać się za pomocą plików na dysku. Jeśli za pomocą plików to można to zrobić tak:

 * proces główny uruchamia procesy potomne.
 * procesy potomne liczą i zapisują do plików o takich nazwach jak ich PID.
 * główny proces czeka na zakończenie procesów potomnych, oraz odczytuje wyniki cząstkowe. Sumuje wyniki cząstkowe i zwraca wynik. 

Dodaj pomiar czasu wykonania każdego procesu, oraz czasu wykonania całego programu. 
