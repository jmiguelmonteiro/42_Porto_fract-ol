/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:06 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/10 18:02:14 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Includes */
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <X11/keysym.h>

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2

/*  Window dimensions  */
# define W_SIZE 800

/*  Mouse codes*/
# define SCROLL_UP 4
# define SCROLL_DOWN 5

/* Structures */
typedef struct s_image
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_fractol
{
	int		set;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		max_iterations;
	void	*mlx;
	void	*mlx_win;
	t_image	mlx_img;
}	t_fractol;

typedef unsigned char	byte;

/* Functions */
void	process_args(int argc, char **argv, t_fractol *fractol);
double	ft_atof(char *str);
void	init_data(t_fractol *f);
void	init_all(t_fractol *fractol);
void	exit_fractol(int exit_code, t_fractol *f);

int		encode_rgb(byte red, byte green, byte blue);
void	my_pixel_put(t_image *i, int x, int y, int color);

int		handle_key_input(int keysym, t_fractol *f);
int		handle_mouse_input(int mouse_code, int x, int y, t_fractol *f);

void	draw_fractol(t_fractol *f);
void	calc_mandelbrot(t_fractol *f);

#endif
