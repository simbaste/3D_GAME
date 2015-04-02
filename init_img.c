/*
** init_img.c for  in /home/simomb_s/semestre1/rendu/MUL_2014_wolf3d
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Mon Dec 15 16:56:51 2014 stephanedarcy simomba
** Last update Sun Jan  4 21:51:14 2015 stephanedarcy simomba
*/

#include <unistd.h>
#include <stdlib.h>
#include "mlx.h"
#include "my.h"
#include "t_coord.h"

int		init_img(t_param *mlx)
{
  int		g;
  int		a;

  a = 0;
  if ((mlx->img2 = mlx_xpm_file_to_image(mlx->mlx_ptr, "gun.xpm", &g, &g)) == NULL)
    return (-1);
  while (a < (mlx->size_line * (HEIGHT / 2)))
    {
      mlx->data[a++] = 255;
      mlx->data[a++] = 100;
      mlx->data[a++] = 105;
      mlx->data[a++] = 0;
    }
  while (a < (mlx->size_line * HEIGHT))
    {
      mlx->data[a++] = 100;
      mlx->data[a++] = 105;
      mlx->data[a++] = 55;
      mlx->data[a++] = 0;
    }
  return (0);
}
