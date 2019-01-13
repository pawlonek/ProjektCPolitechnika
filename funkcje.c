#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
//uniwersalny zestaw narzedziowy chroniacy brzed bledami nieprzekazania wartosci
#define NODUS  struct node {char name[29]; int mark; int roll;struct node *next;}; struct node *h,*t,*t1,*w,*w1;char num[20];int ps,dec=0;char plik[30];

#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <funkcje.h>

//funkcja zliczajaca chsum pliku i porownuje z istniejacym
testchsum()
{
    char plik[30];
    printf("\nPodaj nazwe pliku dla ktorego chcesz sprawdzic zmiany:");
    scanf("%s",&plik);


    FILE *fpppp = NULL;
    fpppp=fopen(plik,"rb");

    unsigned char checksumm = 0;
    if(fpppp==NULL)
    {
        printf("nie mozna znalezc podanego pliku");
        return;
    }

    while (!feof(fpppp) && !ferror(fpppp)) {
        checksumm ^= fgetc(fpppp);
    }
    fclose(fpppp);

    int checksumkontrol = 0;
    strcat(plik,".chsum");
    FILE *fppppp = fopen(plik,"r");
    if(!fppppp)
    {
        printf("nie znaleziono pliku chsum");
        return;
    }
    fscanf (fppppp, "%d", &checksumkontrol);
    fclose(fppppp);

    if(checksumm==checksumkontrol)
        printf("\nW pliku nie bylo zmian poza programem");
    else
        printf("\n\nW pliku byly zmiany poza programem");
    }

//wpisywanie wartosci do listy
wypisywanie(struct node *start)
{
    NODUS
  if(start==NULL)
   {
        printf("Nie zostaly dodane jeszcze zadne leki");
    }
  w=start;
  while(w!=NULL)
 {
    printf("\nNumer katalogowy leku: %d\nNazwa leku: %s\nCena leku: %d\n",
    w->roll,w->name,w->mark);
    w=w->next;
 }
}

wpisywanie(struct node *g)
{
    NODUS
    //dodanie jesli nie mamy pustych miejsc badz pusta liste
    do{
            printf("\nNumer katalogowy nowego leku( w postaci liczbowej):\t");
            scanf("%s",num);
            dec=atoi(num);
            g->roll=dec;
    }while(dec==0);
        printf("\nNazwa nowego leku:\t");
        scanf("%s",&g->name);
    do{
            printf("\nCena nowego leku( w postaci liczbowej ):\t");
            scanf("%s",num);
            dec=atoi(num);
            g->mark=dec;
    }while(dec==0);
        g->next=NULL;

}

wpisywanie2(struct node *g)
{
    printf("wpis2");
    NODUS
    while(g->next!=NULL)
            {g=g->next;}
        t1=(struct node *)malloc(sizeof(struct node));
        g->next=t1;
        g=t1;
    do{
        printf("\nNumer katalogowy nowego leku( w postaci liczbowej):\t");
        scanf("%s",num);
        dec=atoi(num);
        g->roll=dec;
    }while(dec==0);
        printf("\nNazwa nowego leku:\t");
        scanf("%s",&g->name);
    do{
        printf("\nCena nowego leku( w postaci liczbowej ):\t");
        scanf("%s",num);
        dec=atoi(num);
        g->mark=dec;
    }while(dec==0);
        g->next=NULL;

}

usun(struct node *gc, int psUsun)
{
    NODUS
    if(psUsun==gc->roll)
    {
        gc->mark=NULL;
        gc->roll=NULL;
        free(gc);
        return;
    }
    else
    {
    while(gc->next->roll!=psUsun)
    {
        if(gc->next==NULL)
        {
            printf("nie ma takiego rekordu");
                return 0;
        }
            gc=gc->next;
        }
        t1=gc->next;
        gc->next=t1->next;
        free(t1);
        return;
    }
return;
}

zmien(struct node *tt)
{
        NODUS
        printf("Wpisz numer leku ktory chcesz edytowac\n");
    scanf("%d",&ps);
    while(tt->roll!=ps)
    {
        if(tt->next!=NULL)    
            tt=tt->next;
        else
            break;
    }
    if(tt->roll==ps)
    {
        printf("\nNowy numer leku:\t");
        scanf("%d",&tt->roll);
        printf("\nNowa nazwa leku:\t");
        scanf("%s",&tt->name);
        printf("\nNowa cena leku:\t");
        scanf("%d",&tt->mark);
    }
    else
        printf("\nNie ma takiego leku w bazie");

}

zapisdopliku(struct node *gg)
{
    NODUS
    if (gg==NULL)
        {return;}
    printf("\nPodaj nazwe pliku do kturego chcesz zapisac baze:");
    scanf("%s",&plik);
    FILE *fp = NULL;
    fp = fopen(plik, "w+");
    while(gg!=NULL)
    {
        fprintf(fp, "%d\n%s\n%d\n",gg->roll,gg->name,gg->mark);
        gg=gg->next;
    }
    fclose(fp);
//checksum

    FILE *fpp = NULL;
    fpp=fopen(plik,"rb");

    unsigned char checksum = 0;
    if(fpp!=NULL)
    {
        while (!feof(fpp) && !ferror(fpp)) {
            checksum ^= fgetc(fpp);
    }}

    fclose(fpp);
//koniec checksum
//zapis czecksum
    strcat(plik,".chsum");
    FILE *fppp = fopen(plik,"w+");
    fprintf(fppp,"%u",checksum);
    fclose(fppp);
//koniec zapisu checksum
    printf("Zapisano baze.\n");

}


bubbleSort(struct node *start) 
{ 
    NODUS
    int swapped; 
    struct node *nodePrev; 
    struct node *nodeNext = NULL; 
  
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        nodePrev = start; 
  
        while (nodePrev->next != nodeNext) 
        { 
            if (nodePrev->roll > nodePrev->next->roll) 
            {  
                swap(nodePrev, nodePrev->next); 
                swapped = 1; 
            } 
            nodePrev = nodePrev->next; 
        } 
        nodeNext = nodePrev; 
    } 
    while (swapped); 
} 

swap(struct node *a, struct node *b) 
{ 
    NODUS
    int TempPosition = a->roll; 
    a->roll = b->roll; 
    b->roll = TempPosition; 
    char TempName[29];
    strcpy(TempName, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, TempName);
    int TempNum = a->mark; 
    a->mark = b->mark; 
    b->mark = TempNum;
} 

bubbleSortMark(struct node *start) 
{ 
    NODUS
    int swapped; 
    struct node *nodePrev; 
    struct node *nodeNext = NULL; 
  
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        nodePrev = start; 
  
        while (nodePrev->next != nodeNext) 
        { 
            if (nodePrev->mark > nodePrev->next->mark) 
            {  
                swap(nodePrev, nodePrev->next); 
                swapped = 1; 
            } 
            nodePrev = nodePrev->next; 
        } 
        nodeNext = nodePrev; 
    } 
    while (swapped); 
} 

bubbleSortName(struct node *start) 
{ 
    NODUS
    int swapped; 
    struct node *nodePrev; 
    struct node *nodeNext = NULL; 
  
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        nodePrev = start; 
  
        while (nodePrev->next != nodeNext) 
        { 
            if (strcmp(nodePrev->name,nodePrev->next->name)>0) 
            {  
                swap(nodePrev, nodePrev->next); 
                swapped = 1; 
            } 
            nodePrev = nodePrev->next; 
        } 
        nodeNext = nodePrev; 
    } 
    while (swapped); 
} 
//wczytywanie bazy z pliku
odczyt(struct node *ww)
{
    NODUS
    printf("\nCzy napewno chcesz wczytac baze lekow? Pamietaj, niezapisane zmiany w obecnej bazie nie zostana zachowane. Wcisnij t by kontynuowac.\n");
    char pytwsiudmym;
    scanf("%s",&pytwsiudmym);
    if(pytwsiudmym=='t')
    {
        printf("\nPodaj nazwe pliku z ktorego chcesz odczytac baze:");
        scanf("%s",&plik);
        FILE * ffpp;
        char * line = NULL;
        size_t len = 0;
        ssize_t read;
        int linia=0;
        int powtarzalnosc=0;
        ffpp = fopen(plik, "r");
        if (ffpp == NULL)
            return;
        while ((read = getline(&line, &len, ffpp)) != -1) {
            linia++;
            if(linia==1)
            {
                if(powtarzalnosc==1)
                {
                    w1=(struct node *)malloc(sizeof(struct node));
                    ww->next=w1;
                    ww=ww->next;
                }
                ww->roll=atoi(line);
            }
            if(linia==2)
            {
                strcpy(ww->name,strtok(line, "\n"));
            }
            if(linia==3)
            {
                ww->mark=atoi(line);
                linia=0;
                powtarzalnosc=1;
            }
        }

        fclose(ffpp);
        if (line)
            free(line);
    }
    else
        printf("\nNic straconego, wroc tu gdy zapiszesz wszystkie swoje zmiany.\n");
    return;
}