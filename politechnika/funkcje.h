/*! Naglowek pliku funkcyjnego */
#ifndef fun_h
#define fun_h
    /** Struktura listy lekow. 
     *  Lista przesowajaca jednokierunkowa przechowywujaca nazwy, ceny i indexy lekow
     */
 struct node
  {
     char name[29];  /**< nazwa leku */
     int mark;    /**< cena leku */
     int roll;    /**< index leku */
     struct node *next; /**< link do nastepnego pola */
  };

void testchsum();//!< sprawdza sume kontrolna

void wypisywanie(struct node *start);//!< wypisuje liste lekow

void wpisywanie(struct node *g);//!< wpisuje lek do listy

void wpisywanie2(struct node *g);//!< wpisuje lek do listy w nietypowej sytuacji

void usun(struct node *gc, int psUsun);//!< usuwa wybrane pole listy lekow

void zmien(struct node *tt);//!< zmienia wartosci wybranego pola lekow

void zapisdopliku(struct node *gg);//!< zapisuje liste lekow do pliku

void bubbleSort(struct node *start);//!< sortowanie po indexie

void swap(struct node *a, struct node *b);//!< zamienia wartosci 2 pol listy

void bubbleSortMark(struct node *start);//!< sortuje liste po cenie

void bubbleSortName(struct node *start);//!< sortuje liste po nazwie leku

void odczyt(struct node *ww);//!< wczytuje liste z pliku

#endif //fun_h
