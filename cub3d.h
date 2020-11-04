/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 21:18:15 by davi              #+#    #+#             */
/*   Updated: 2020/05/09 20:22:51 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define PI 3.1416
# define ROTSPED 10
# define MOVSPED 2
# define VIEW_ANG 60
# define WDH_TEXT 64
# define MAP_SIZE 16
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include "mlx/mlx_int.h"

typedef struct	s_map3d
{
	char		*resolut;
	char		*txt_no;
	char		*txt_so;
	char		*txt_we;
	char		*txt_ea;
	char		*txt_sie;
	char		*rgb_flr;
	char		*rgb_clg;
	int			color_flr;
	int			color_clg;
}				t_map3d;

typedef struct	s_map2d
{
	char		**matrix;
	char		*string;
	int			mtx_wdh;
	int			mtx_lgh;
	void		*img;
	int			map_wdh;
	int			map_lgh;
	int			mapy;
	int			mapx;
}				t_map2d;

typedef struct	s_play2d
{
	int			init;
	char		ini_ply;
	double		degres;
	int			starty;
	int			startx;
	double		posy;
	double		posx;
	int			wdh;
}				t_play2d;

typedef struct	s_error
{
	int			file;
	int			func;
	int			err;
}				t_error;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	int			wdh;
	int			lgh;
}				t_window;

typedef struct	s_mmpi
{
	int			bpp;
	int			size_line;
	int			endian;
	char		*dst;
}				t_mmpi;

typedef struct	s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	float		qtt_wdh;
	int			bpp;
	int			size_line;
}				t_texture;

typedef struct	s_center_sprit
{
	char		*txt_sprit;
	int			init;
	int			nsprits;
	int			visibles;
}				t_center_sprit;

typedef struct	s_unity_sprit
{
	int			mtxy;
	int			mtxx;
	int			mapy;
	int			mapx;
	float		ang;
	float		distanc2d;
	int			visible;
	int			mid;
	int			hgt;
	int			wdh;
	float		ratio;
	int			startx;
	int			endx;
}				t_unity_sprit;

typedef struct	s_save_bmp
{
	int			status;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_save_bmp;

void			cub3d(char *pnt);
int				fill_maps(char *pnt);
int				string_map2d(char *ptr);
int				fill__map2d(void);
int				build_matrix2d(void);
int				filter_maps(char *ptr);
int				fill__map3d(char *ptr);
int				null_ptr_map3d(char *ptr);
void			error(void);
void			file_error(int file);
void			func_error(int func);
void			type_error(int err);
int				set_error(int file, int func, int err);
int				valid_maps(void);
int				valid_map3d(void);
int				valid__map3d_part2(void);
int				valid_content_map3d(char *ptr);
int				valid_map2d(void);
int				let_matrix_map2d(void);
int				verifica_map2d(void);
int				horizontal_map2d(int lgh, int wdh);
int				vertical_map2d(int lgh, int wdh);
int				ver_extension_file(char *ptr, char *ext);
int				valid_rgb(char *ptr);
int				valid_resolut(char *ptr);
int				memory_free(void);
void			free_gmap23ds(void);
int				init_window(void);
int				events_mlx(char *pt);
int				key_pressed(int keycode);
int				key_pressed2(int keycode, double *vars);
void			my_mlx_pixel_image(void *img, int x, int y, int color);
void			build_map2d(void);
int				mini_map2d(void);
int				init_player2d(char let, int posy, int posx);
int				ver_posplay2d(void);
int				posplay2d_part2(int *y, int *x, int width, int height);
void			raycasting(void);
int				ver_point2d(double *y, double *x);
void			project3d(double *x, double *y, float n, int num);
void			wall_3d(int height, int num, int x, int y);
int				convert_rgb(char *ptr);
char			*image_texture(char *ptr, int x);
int				init_texture(void);
void			config_init_minimap(void);
int				esc_close(int keycode);
char			*texture_wall(int x, int y);
char			*div_wall(int x, int y, int width, int height);
unsigned int	get_color(char *texture, int y, int x);
char			*point_supleft(int x, int y, int width, int height);
char			*point_supright(int x, int y, int width, int height);
char			*point_lessleft(int x, int y, int width, int height);
char			*point_lessright(int x, int y, int width, int height);
void			init_sprit(void);
void			visibles_sprits(void);
void			insert_sprits_visibles(void);
void			sprit_3d(int num, t_unity_sprit *spr);
void			set_init_sprit(t_unity_sprit *spr, int y, int x);
void			set_visibles_sprit(t_unity_sprit *spr);
void			bubblesort_sprits_visibles(int cont);
int				ver_flag_save(char *ptr, char *ext);
int				save_bmp_file(void);
int				x_close(void);
#endif
