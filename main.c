/*
** main.c for  in /home/simomb_s/semestre1/rendu/MUL_2014_wolf3d
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Mon Dec 15 14:07:19 2014 stephanedarcy simomba
** Last update Sun Jan  4 21:48:14 2015 stephanedarcy simomba
*/

#include <unistd.h>
#include <X11/X.h>
#include <stdlib.h>
#include "mlx.h"
#include "my.h"
#include "t_coord.h"

void		mur_down(t_param *mlx, int y, int h, int color)
{
  int		c;
  int		i;
  int		z;

  i = 0;
  while (i < h)
    {
      c = 0;
      while (c < (mlx->bpp / 8))
	{
	  z = y + (i * mlx->size_line);
	  mlx->data[c + z] = color;
	  c++;
	}
      i++;
    }
}

int		insert_mur(t_param *mlx, float k, int x, int color)
{
  int		c;
  int		h;
  int		i;
  int		z;
  int		y;

  h = (HEIGHT / (2 * k));
  y = ((HEIGHT / 2) * mlx->size_line) + (x * mlx->bpp / 8);
  i = 0;
  while (i < h)
    {
      c = 0;
      while (c < (mlx->bpp / 8))
	{
	  z = y - (i * mlx->size_line);
	  mlx->data[c + z] = color;
	  ++c;
	}
      ++i;
    }
  mur_down(mlx, y, h, color);
  return (0);
}

int		main()
{
  t_param	mlx;

  if ((mlx.mlx_ptr = mlx_init()) == 0)
    return (-1);
  if ((mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, LENGHT, HEIGHT, "Wolf3d")) == 0)
    return (-1);
  if ((mlx.img = mlx_new_image(mlx.mlx_ptr, LENGHT, HEIGHT)) == NULL)
    return (0);
  if ((mlx.img2 = mlx_new_image(mlx.mlx_ptr, LENGHT, HEIGHT)) == NULL)
      return (0);
  mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, &mlx.endian);
  init_img(&mlx);
  mlx.x = 3.5;
  mlx.y = 1.5;
  mlx.a = 180;
  gere_map(&mlx);
  mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
  mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img2, 0, 0);
  mlx_hook(mlx.win_ptr, KeyPress, KeyRelease, gere_key, &mlx);
  mlx_expose_hook(mlx.win_ptr, gere_expose, &mlx);
  mlx_loop(mlx.mlx_ptr);
  return (0);
}
