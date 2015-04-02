/*
** my_strlen.c for my_strlen.c in /home/simomb_s/Piscine_C_J04
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Thu Oct  2 15:18:25 2014 stephanedarcy simomba
** Last update Mon Nov 10 15:56:44 2014 stephanedarcy simomba
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (*str != '\0')
    {
      i = i + 1;
      str = str + 1;
    }
  return (i);
}
