#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

//*oznacza poczatek bloku, #koniec

//*struktura leku
 struct node
  {
     char name[29];
     int mark;
     int roll;
     struct node *next;
  };
//#struktura leku
  int main()
  {
    int i,n,ch,ps,x,k;
    k=0;
    //zmienne do obslugi plikow
    char plik[30];
    int konieclini;

  struct node *h,*t,*t1,*w,*q;
  h=NULL;
//*wstep
    int width = 80;
    char str[] = "Apteka 'Sama Chemia'";
    int length = sizeof(str) - 1;
    int pad = (length >= width) ? 0 : (width - length) / 2;
    printf("%*.*s%s\n", pad, pad, " ", str);
//#wstep
//*menu
while(1)
 {
     
    printf("\n\n1.Wyswietl leki\n2:Dodaj nowy lek\n3.Usun stary lek\n4.Zmien informacje o leku\n5.Zakoncz\n6.Zapisz baze lekow\n7.Wczytaj baze lekow\n");
    printf("\nPodaj cyfre odpowiadajaca twojemu wyborowi=");
    scanf("%d",&ch);
//*menu wyboru      
      switch(ch)
     
{
//#menu
//*wyswietlanie lekow
case 1:    
//na wypadek braku lekow w liscie
  if(h==NULL)
   {
    printf("Nie zostaly dodane jeszcze zadne leki");
  }
  w=h;
  while(w!=NULL)
 {
    printf("\nNumer katalogowy leku: %d\nNazwa leku: %s\nCena leku: %d\n",
    w->roll,w->name,w->mark);
    w=w->next;
 }
break;
//#wyswietlanie lekow
//*dodawanie lekow
case 2:
//dodanie jesli nie mamy pustych miejsc badz pusta liste
    if(h==NULL)
 {
    h=t=(struct node *)malloc(sizeof(struct node));
    printf("\nNumer katalogowy nowego leku:\t");
    scanf("%d",&t->roll);
    printf("\nNazwa nowego leku:\t");
    scanf("%s",&t->name);
    printf("\nCena nowego leku:\t");
    scanf("%d",&t->mark);
    t->next=NULL;
break;
}
//dodanie w puste miejsce na liscie
else
  {
    t1=(struct node *)malloc(sizeof(struct node));

    printf("\nNumer katalogowy nowego leku:\t");
    scanf("%d",&t1->roll);
    printf("\nNazwa nowego leku:\t");
    scanf("%s",&t1->name);
    printf("\nCena nowego leku:\t");
    scanf("%d",&t1->mark);
    t1->next=t->next;
    t->next=t1;
    t=t1;
                                                                                         
}


break;
//#dodawanie lekow
//*usuwanie lekow
case 3:
    printf("Wpisz numer leku ktory chcesz usunac\n");
    scanf("%d",&ps);
    t=h;
 while(t->roll!=ps-1)
   {
     t=t->next;
    }
     t1=t->next;
     t->next=t1->next;
     free(t1);
 break;
//#usuwanie lekow
//*modyfikowanie lekow
case 4:
    printf("Wpisz numer leku ktory chcesz edytowac\n");
   scanf("%d",&ps);
   t=h;
 while(t->roll!=ps)
   {
   t=t->next;
   }
  printf("\nNowy numer leku:\t");
  scanf("%d",&t->roll);
  printf("\nNowa nazwa leku:\t");
  scanf("%s",&t->name);
  printf("\nNowa cena leku:\t");
  scanf("%d",&t->mark);
 break;
//#modyfikowanie lekow     
//*wychodzenie z programu
case 5:  
printf("\nDziekujemy za skozystanie z naszych uslug.\t");  
exit(0);
           
 break;
//#wychodzenie z programu
//*zapisywanie do pliku
case 6:
if (h==NULL)
{break;}
printf("\nPodaj nazwe pliku do kturego chcesz zapisac baze:");
scanf("%s",&plik);
FILE *fp = NULL;
fp = fopen(plik, "w+");
w=h;
while(w!=NULL)
{
fprintf(fp, "%d ,%s ,%d\n",w->roll,w->name,w->mark);
w=w->next;
}
fclose(fp);
break;
//#zapis do pliku
//*odczyt z pliku
case 7:
printf("\nCzy napewno chcesz wczytac baze lekow? Pamietaj, niezapisane zmiany w obecnej bazie nie zostana zachowane. Wcisnij t by kontynuowac.\n");
char pytwsiudmym;
scanf("%s",&pytwsiudmym);
if(pytwsiudmym=='t')
{
w=h;
printf("\nPodaj nazwe pliku z kturego chcesz odczytac baze:");
scanf("%s",&plik);
FILE *fp = NULL;
fp = fopen(plik, "r");
if (fp == NULL) 
{ 
printf("Blad wczytywania pliku"); 
break;
} 
int countfile=0;
char chr;
//while (fgets(buffer, sizeof buffer, fp)) {
//    ++countfile;}
chr = getc(fp);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == 'n')
        {
            countfile = countfile + 1;
        }
        //take next character from file.
        chr = getc(fp);
    }

printf("%f",countfile);
//{
//konieclini=fscanf(fp, "%f ,%s ,%f\n", w->roll,w->name,w->mark);
//w=w->next;
//}
fclose(fp);
}
else
{printf("\nNic straconego, wroc tu gdy zapiszesz wszystkie swoje zmiany.\n");}
break;

}
}
}
