/*! plik sterujacy baza magazyn */
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>

#include "magazyn.h"

#include <sys/types.h>
#include <unistd.h>

struct nmag *h,*t,*t1,*w,*w1;

void magsprawdz(int id_dane)//!< sprawdza plik magazyn pod katem wystepowania podanej liczby, wpisuje ja jesli jej nie ma
{
        FILE * fpmag;   /*!< przechowanie pliku magazyn */
        char * line = NULL; /*!< przechowanie wczytanej linii */
        size_t len = 0;
        ssize_t read;
        int linia=0;    /*!< suma przesnkcji */
        int powtarzalnosc=0;    /*!< przechowanie informacji o wykonaniu petli */
        fpmag = NULL;
        w=(struct nmag *)malloc(sizeof(struct nmag));
        fpmag = fopen("magazyn.txt", "r");
        if (fpmag != NULL)
        {
        while ((read = getline(&line, &len, fpmag)) != -1) {
            linia++;
            if(linia==1)
            {
                if(powtarzalnosc==1)
                {
                w1=(struct nmag *)malloc(sizeof(struct nmag));
                w1->prev=w;
                w=w1;
                }
               w->id=atoi(line);
            }
            if(linia==2)
            {
                strcpy(w->name,strtok(line, "\n"));
                linia=0;
                powtarzalnosc=1;
            }
        }
        fclose(fpmag);
        if (line)
            free(line);
        }
     t=w;
    int znalazl_pole=0; /*!< przechowuje informacje o tym czy znaleziono podany rekord w liscie */
    
    if(id_dane==t->id)
          znalazl_pole=1;
          
    while(t->prev!=NULL)
    {
        t=t->prev;
        if(id_dane==t->id)
            {znalazl_pole=1;
            break;}
    }

    if(znalazl_pole==0)
    {
        if(t->id!=NULL)
        {
            w1=(struct nmag *)malloc(sizeof(struct nmag));
            w1->prev=t;
            t=w1;
        }
        t->id=id_dane;
    printf("\nNie znaleziono magazynu przypisanego do tego leku. Podaj nazwe tego magazynu:\t");
    scanf("%s",&t->name);
    }
    if(znalazl_pole==0)
    {
    FILE *ffpmag = NULL;    /*!< zapisuje plik magazyn , typ a */
    ffpmag = fopen("magazyn.txt", "a");
        fprintf(ffpmag, "%d\n%s\n",t->id,t->name);
    fclose(ffpmag);
    }
    return;
    }


void magshow(int id_wyswietl)//!< wypisuje nazwe magazynu
    {
        FILE * ffppmag; /*!< przechowanie pliku magazyn , uzywane przy wypisywaniu */
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        int linia=0;
        int powtarzalnosc=0;
        ffppmag = NULL;
        w=(struct nmag *)malloc(sizeof(struct nmag));
        ffppmag = fopen("magazyn.txt", "r");
        if (ffppmag != NULL)
        {
        while ((read = getline(&line, &len, ffppmag)) != -1) {
            linia++;
            if(linia==1)
            {
                if(powtarzalnosc==1)
                {
                w1=(struct nmag *)malloc(sizeof(struct nmag));
                w1->prev=w;
                w=w1;
                }
               w->id=atoi(line);
            }
            if(linia==2)
            {
                strcpy(w->name,strtok(line, "\n"));
                linia=0;
                powtarzalnosc=1;
            }
        }
        fclose(ffppmag);
        if (line)
            free(line);
        }
int wystapienie=0;
if(w->id==id_wyswietl)
{wystapienie=1;
printf("\nLek znajduje sie w magazynie %s\n",w->name);}
while(w->prev != NULL && wystapienie==0)
{
w=w->prev;
if(w->id==id_wyswietl)
{wystapienie=1;
printf("\nLek znajduje sie w magazynie %s\n",w->name);}
}
if(wystapienie==0)
{
printf("\nLek nie znajduje sie w zadnym z naszych magazynow");
}


        return;
    }
