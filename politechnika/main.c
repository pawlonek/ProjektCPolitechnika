/*! plik glowny */
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include "funkcje.h"


  int main()
  {
    int ch/*!< zmienna sterujaca menu */,ps/*!< zmienna uzywana przy usuwaniu rekordow */,dec=0/*!< zmienna testujaca poprawnosc danych wejsciowych*/,len/*!< dugosc linii */,lines/*!< ilosc linii wczytanych */;
    char plik[30];  /*!< przechowywacz nazwy pliku wczytywanego */
    char losowy[20];    /*!< przechowanie nazwy podczas zmiany pola */
    char num[20];   /*!< przechowanie danych wejsciowych, tymczasowe */
    struct node *h,*t,*t1,*w,*w1;
    h=NULL; /*!< glowica listy */
//*wstep
    int width = 80; /*!< stopka naglowka */
    char str[] = "Apteka 'Sama Chemia'";
    int length = sizeof(str) - 1; /*!< szerokosc naglowka */
    int pad = (length >= width) ? 0 : (width - length) / 2; /*!< odstep naglowka */
    printf("%*.*s%s\n", pad, pad, " ", str);
//*menu
while(1)
{
    printf("\n\n1.Wyswietl leki\n2:Dodaj nowy lek\n3.Usun stary lek\n4.Zmien informacje o leku\n5.Zakoncz\n6.Zapisz baze lekow\n7.Wczytaj baze lekow\n8.Posortuj baze po numerze indeksu\n9.Posortuj baze po cenie\n10.Posortuj baze alfabetycznie\n11.Sprawdz plik pod wzgledem zmian poza programem.");
    printf("\nPodaj cyfre odpowiadajaca twojemu wyborowi=");
    scanf("%d",&ch);
    printf("\n");
//*menu wyboru      
switch(ch)
     
{
//*wyswietlanie lekow
case 1: 

    wypisywanie(h); //!< funkcja wypisujaca dane
    break;
//*dodawanie lekow
case 2:

//dodanie jesli nie mamy pustych miejsc badz pusta liste
    if(h==NULL)
    {
        h=(struct node *)malloc(sizeof(struct node));
        wpisywanie(h);  //!< dodanie pola do listy
    break;
    }
//dodanie w puste miejsce na liscie
else 
    wpisywanie2(h);      //!< dodanie pola do listy w nietypowej sytuacji                                                                            
break;
//*usuwanie lekow
case 3:
    if(h->next!=NULL) 
    t1=h->next;
    printf("Wpisz numer leku ktory chcesz usunac\n");
    scanf("%d",&ps);
//usuwanie 1 rekordu w pustej tabeli wywolywalo rzesze bledow dlatego dla tego 1 przypadku potrzebne jest nastepne 6 linijek
    if(h->roll==ps)
        if(h->next!=NULL)
        h=t1;
        else
        h=NULL;
    else
    usun(h,ps); //!< usun pole o wskazanym indexie ( ps )

break;
//*modyfikowanie lekow
case 4:

    zmien(h); //!< zmien pole o wskazanym indexie
 break;   
//*wychodzenie z programu
case 5:  

    printf("Dziekujemy za skozystanie z naszych uslug.\n");  
    exit(0); //!< wyjdz z programu
break;
//*zapisywanie do pliku
case 6:

    zapisdopliku(h);    //!< zapisz liste do pliku
break;
//*odczyt z pliku
case 7:

    if(h==NULL)
        h=(struct node *)malloc(sizeof(struct node));
    odczyt(h);  //!< wczytaj funkcje z pliku
break;
//3 rozne sortowania
case 8:

w=h;
bubbleSort(w);  //!< sortuj liste po indexie
printf("\nLista zostala posortowana\n");
break;

case 9:

w=h;
bubbleSortMark(w);  //!< sortuj liste po cenie
printf("\nLista zostala posortowana\n");
break;

case 10:

w=h;
bubbleSortName(w);  //!< sortuj liste po nazwie
printf("\nLista zostala posortowana\n");
break;
//suma kontrolna
case 11:

testchsum();    //!< sprawdz sume kontrolna pliku
break;
//niesamowicie prosty sposob radzenia sobie z wykrzaczeniem petli gdy wpisana zostanie niewlasciwa wartosc
default:
scanf("%s",&losowy);
break;
}
}
//nie powinno nigdy zajsc, ale tak na wszelki wypadek
return 0;
}
