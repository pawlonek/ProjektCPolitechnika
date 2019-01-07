
//funkcja zliczajaca chsum pliku i porownuje z istniejacym. 3-43
void testchsum()
{
char plik[30];
printf("\nPodaj nazwe pliku dla ktorego chcesz sprawdzic zmiany:");
scanf("%s",&plik);


FILE *fpppp = NULL;
fpppp=fopen(plik,"rb");

unsigned char checksumm = 0;
if(fpppp==NULL)
{printf("nie mozna znalezc podanego pliku");
return;}

while (!feof(fpppp) && !ferror(fpppp)) {
   checksumm ^= fgetc(fpppp);
}
fclose(fpppp);
//printf("%u",checksumm);


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
//printf("%d",checksumkontrol);


if(checksumm==checksumkontrol)
printf("\nW pliku nie bylo zmian poza programem");
else
printf("\n\nW pliku byly zmiany poza programem");

}
//skrypty odpowiadajace za sortowanie 45-
