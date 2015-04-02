/*
** enven.c for  in /home/simomb_s/semestre1/rendu/MUL_2014_wolf3d
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Mon Dec 15 15:50:34 2014 stephanedarcy simomba
** Last update Sun Jan  4 21:48:49 2015 stephanedarcy simomba
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "my.h"
#include "t_coord.h"

int		direction(int key, t_param *mlx)
{
  float		x;
  float		y;

  x = -1;
  y = -1;
  if (key == 65362)
    {
      x = mlx->x + (0.1 * cos((mlx->a / 180) * 3.14f));
      y = mlx->y + (0.1 * sin((mlx->a / 180) * 3.14f));
    }
  else if (key == 65364)
    {
      x = mlx->x - (0.1 * cos((mlx->a / 180) * 3.14f));
      y = mlx->y - (0.1 * sin((mlx->a / 180) * 3.14f));
    }
  if (key == 65363)
    mlx->a = mlx->a - 10;
  if (key == 65361)
    mlx->a = mlx->a + 10;
  user_touch(mlx, x, y);
  return (1);
}

int		gere_key(int keycode, t_param *mlx)
{
  if (keycode == 65307)
    exit(1);
  direction(keycode, mlx);
  return (0);
}

int		gere_expose(t_param *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img2, 0, 0);
  return (0);
}
