/*
** my_map.c for  in /home/simomb_s/semestre1/rendu/MUL_2014_wolf3d
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Tue Dec 16 00:29:10 2014 stephanedarcy simomba
** Last update Sun Jan  4 21:49:12 2015 stephanedarcy simomba
*/

#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "my.h"
#include "t_coord.h"

int		map[15][15] =
  {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

float		gere_mur(t_param *t, float X, float Y)
{
  int		x;
  int		y;
  float		k;

  k = 1;
  x = t->x + (k * (X - t->x));
  y = t->y + (k * (Y - t->y));
  while (map[x][y] == 0)
    {
      x = t->x + (k * (X - t->x));
      y = t->y + (k * (Y - t->y));
      k += 0.01;
    }
  return (k);
}

void		my_funct(t_param *mlx, int color1, int color2, float a)
{
  static float	n;
  float		tmp;
  float		x;
  float		y;
  float		i;
  float		k;

  i = 0;
  while (i <= LENGHT)
    {
      x = 0.5;
      y = ((1 * ((LENGHT / 2) - i)) / LENGHT);
      tmp = x;
      x = (tmp * cos(a)) - (y * sin(a));
      y = (tmp * sin(a)) + (y * cos(a));
      x = x + mlx->x;
      y = y + mlx->y;
      k = gere_mur(mlx, x, y);
      if (k < n)
	insert_mur(mlx, k, i, color1);
      else
	insert_mur(mlx, k, i, color2);
      n = k;
      ++i;
    }
}

int		gere_map(t_param *mlx)
{
  int		color1;
  int		color2;
  float		a;

  color1 = 25;
  color2 = 40;
  init_img(mlx);
  a = ((mlx->a / 180) * M_PI);
  my_funct(mlx, color1, color2, a);
  return (0);
}

void            user_touch(t_param *mlx, float x, float y)
{
  int		i;
  int		j;

  i = (int)x;
  j = (int)y;
  if (x >= 0 && x <= 14 && y >= 0 && y <= 14 && map[i][j] == 0)
    {
      mlx->x = x;
      mlx->y = y;
    }
  gere_map(mlx);
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2, 0, 0);
}
