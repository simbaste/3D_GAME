/*
** t_coord.h for  in /home/simomb_s/semestre1/rendu/MUL_2014_wolf3d
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Mon Dec 15 14:08:30 2014 stephanedarcy simomba
** Last update Sun Jan  4 19:33:07 2015 stephanedarcy simomba
*/

#ifndef __T_COORD_H__
# define __T_COORD_H__

# define LENGHT 1000
# define HEIGHT 1000

typedef struct s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct	s_param
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img;
  void		*img2;
  char		*data;
  int		bpp;
  int		size_line;
  int		endian;
  float		x;
  float		y;
  float		a;
}		t_param;

typedef struct	s_color
{
  int		nb1;
  int		nb2;
  int		nb3;
  int		nb4;
}		t_color;

int		draw_cas_un(t_coord *pt1, t_coord *pt2, void *img);
int		draw_cas_deux(t_coord *pt1, t_coord *pt2, void *img);
int		draw_cas_trois(t_coord *pt1, t_coord *pt2, void *img);
int		draw_cas_quatre(t_coord *pt1, t_coord *pt2, void *img);
int		draw_line(t_coord *pt1, t_coord *pt2, void *img);
int		mlx_pixel_put_to_image(t_param *mlx, int x, int y, t_color *color);
int		gere_key(int keycode, t_param *mlx);
int		gere_expose(t_param *mlx);
int		init_img(t_param *mlx);
int		gere_map(t_param *mlx);
int		insert_mur(t_param *mlx, float k, int x, int color);
void		user_touch(t_param *mlx, float x, float y);

# define ABS(x) (((x) < 0) ? ((x) * -1) : (x))

#endif /* __T_COORD_H__ */
