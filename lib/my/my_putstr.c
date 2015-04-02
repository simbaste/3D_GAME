/*
** my_putstr.c for my_putstr.c in /home/simomb_s/Piscine_C_J04
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Fri Oct  3 22:08:07 2014 stephanedarcy simomba
** Last update Wed Nov 26 12:41:30 2014 stephanedarcy simomba
*/

#include <stdlib.h>
#include "my.h"

int	my_putstr(char* str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
