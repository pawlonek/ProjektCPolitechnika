/*! naglowek pliku sterujacego baza magazyn */
#ifndef mag_h
#define mag_h
    /** Struktura listy magazynu. 
     *  Lista cofajaca przechowywujaca nazwy i indexy magazynow
     */
 struct nmag
  {
     char name[29]; /**< nazwa magazynu */
     int id;    /**< index madazynu */
     struct nmag *prev; /**< link do poprzedniego pola magazynu */
  };

void magsprawdz(int id_dane);   //!< sprawdza plik magazyn pod katem wystepowania podanej liczby, wpisuje ja jesli jej nie ma

void magshow(int id);   //!< wypisuje nazwe magazynu

#endif //mag_h