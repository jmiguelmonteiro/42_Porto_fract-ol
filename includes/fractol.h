/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:06 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/19 17:35:47 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Includes */
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2
# define BURNINGSHIP 3

/*  Window dimensions  */
# define WIDTH 800
# define HEIGHT 800

/*  Mouse codes  */
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/*  Zoom codes  */
# define ZOOM_IN 1
# define ZOOM_OUT 0

/*
 * COLORS
*/
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF

/* Structures */
typedef struct s_image
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fractol
{
	int			set;
	double		offset_x;
	double		offset_y;
	double		zoom;
	int			color_palette;
	int			max_iterations;
	t_complex	julia;
	void		*mlx;
	void		*mlx_win;
	t_image		mlx_img;
}	t_fractol;

typedef unsigned char	t_byte;

/* Functions */
void	process_args(int argc, char **argv, t_fractol *fractol);
double	ft_atof(char *str);
void	init_data(t_fractol *f);
void	init_all(t_fractol *fractol);
void	exit_fractol(int exit_code, t_fractol *f);
double	map(double value, double smin, double smax, double size);

void	zoom(t_fractol *fractal, int x, int y, int zoom);
int		encode_rgb(t_byte red, t_byte green, t_byte blue);
void	my_pixel_put(t_image *i, int x, int y, int color);

int		handle_close(t_fractol *f);
int		handle_key_input(int keysym, t_fractol *f);
int		handle_mouse_input(int mouse_code, int x, int y, t_fractol *f);

void	draw_fractol(t_fractol *f);
void	calc_mandelbrot(int x, int y, t_fractol *f, double magnitude);
void	calc_julia(int x, int y, t_fractol *f, double magnitude);
void	calc_burningship(int x, int y, t_fractol *f, double magnitude);

int		get_color(double smooth_iter, t_fractol *f);
int		get_purple_palette(double smooth_iter, t_fractol *f);
int		get_blue_palette(double smooth_iter);
int		get_fire_palette(double smooth_iter, t_fractol *f);

#endif
