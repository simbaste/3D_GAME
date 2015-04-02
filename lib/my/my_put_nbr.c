/*
** my_put_nbr.c for my_put_nbr.c in /home/simomb_s/Piscine_C_J03
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Oct  1 18:21:16 2014 stephanedarcy simomba
** Last update Mon Nov 10 16:09:19 2014 stephanedarcy simomba
*/

#include "my.h"

int	my_put_nbr(long nb)
{
  int b;
  long int	n;

  b = 1;
  n = nb;
  if (n < 0)
    {
      my_putchar('-');
      n = n * -1;
    }
  while ((n / b) >= 10)
    b = b * 10;
  while (b > 0)
    {
      my_putchar((n / b) % 10 + '0');
      b = b / 10;
    }
  return (0);
}
