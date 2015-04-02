/*
** flag_c.c for flag_c.c in /home/simomb_s
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Thu Nov 13 12:55:16 2014 stephanedarcy simomba
** Last update Thu Nov 13 13:26:09 2014 stephanedarcy simomba
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

int     flag_c(int i, va_list ap)
{
  int  result;

  result = va_arg(ap, int);
  my_putchar((char)result);
  i = i + 1;
  return (i);
}
