#include <stdio.h>

int main(void)
{
  int number;
  printf("ml' nob:\n");

  if(scanf("%d", &number) !=1)
  {
    printf("luj\n");
    return 1;
  }

  if(1 <= number && number <= 9)
  {
    if(number == 1)
      printf("Qapla'\nnoH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
    else if(number == 2)
      printf("Qapla'\nbortaS bIr jablu'DI' reH QaQqu' nay'.\n");
    else if(number == 3)
      printf("Qapla'\nQu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
    else if(number == 4)
      printf("Qapla'\nbISeH'eghlaH'be'chugh latlh Dara'laH'be'.\n");
    else if(number == 5)
      printf("Qapla'\nqaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
    else if(number == 6)
      printf ("Qapla'\nSuvlu'taHvIS yapbe' HoS neH.\n");
    else if(number == 7)
      printf ("Qapla'\nHa'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
    else if(number == 8)
      printf ("Qapla'\nHeghlu'meH QaQ jajvam.\n");
    else
      printf ("Qapla'\nleghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
  }
  else
    printf ("luj\n");

  return 0;
}

