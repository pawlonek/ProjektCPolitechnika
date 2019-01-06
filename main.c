#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include "funkcje.h"

//*struktura leku
 struct node
  {
     char name[29];
     int mark;
     int roll;
     struct node *next;
  };
  int main()
  {
    int ch,ps,dec=0,len,lines;
    char plik[30];
    char losowy[20];
    char num[20];
    struct node *h,*t,*t1,*w,*w1;
    h=NULL;
//*wstep
    int width = 80;
    char str[] = "Apteka 'Sama Chemia'";
    int length = sizeof(str) - 1;
    int pad = (length >= width) ? 0 : (width - length) / 2;
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

    wypisywanie(h);
    break;
//*dodawanie lekow
case 2:

//dodanie jesli nie mamy pustych miejsc badz pusta liste
    if(h==NULL)
    {
        h=(struct node *)malloc(sizeof(struct node));
        wpisywanie(h);
    break;
    }
//dodanie w puste miejsce na liscie
else 
    wpisywanie2(h);                                                                                  
break;
//*usuwanie lekow
case 3:

    if(h->next!=NULL) 
    t1=h->next;
    if(1==usun(h))
    h=t1;
break;
//*modyfikowanie lekow
case 4:

    zmien(h);
 break;   
//*wychodzenie z programu
case 5:  

    printf("Dziekujemy za skozystanie z naszych uslug.\n");  
    exit(0); 
break;
//*zapisywanie do pliku
case 6:

    zapisdopliku(h);
break;
//*odczyt z pliku
case 7:

    if(h==NULL)
        h=(struct node *)malloc(sizeof(struct node));
    odczyt(h);
break;
//3 rozne sortowania
case 8:

w=h;
bubbleSort(w);
printf("\nLista zostala posortowana\n");
break;

case 9:

w=h;
bubbleSortMark(w);
printf("\nLista zostala posortowana\n");
break;

case 10:

w=h;
bubbleSortName(w);
printf("\nLista zostala posortowana\n");
break;
//suma kontrolna
case 11:

testchsum();
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
