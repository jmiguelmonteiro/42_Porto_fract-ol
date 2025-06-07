/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:06 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/07 16:51:02 by josemigu         ###   ########.fr       */
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
# define W_HEIGHT 600
# define W_WIDTH 600

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
	double	cx;
	double	cy;
	void	*mlx;
	void	*mlx_win;
	t_image	mlx_img;
}	t_fractol;

typedef unsigned char	byte;

/* Functions */
void	process_args(int argc, char **argv, t_fractol *fractol);
double	ft_atof(char *str);
void	init_all(t_fractol *fractol);
void	exit_fractol(int exit_code, t_fractol *f);

void	color_screen(t_fractol *f, int color);
int		encode_rgb(byte red, byte green, byte blue);

#endif
