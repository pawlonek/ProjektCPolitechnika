
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>

#define _GNU_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include "fun.c"
//*oznacza poczatek bloku, #koniec

  int main()
{
printf("%d",test(6,6));


return 0;
}