/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:13:43 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/12 09:39:21 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *fractal, int x, int y, int zoom)
{
	double	zoom_factor;
	double	mx;
	double	my;

	if (zoom == ZOOM_IN)
		zoom_factor = 0.95;
	else if (zoom == ZOOM_OUT)
		zoom_factor = 1.05;
	else
		return ;
	mx = map(x, -2, 2, WIDTH);
	my = map(y, 2, -2, HEIGHT);
	fractal->offset_x += mx * (fractal->zoom - fractal->zoom * zoom_factor);
	fractal->offset_y += my * (fractal->zoom - fractal->zoom * zoom_factor);
	fractal->zoom *= zoom_factor;
	return ;
}

int	encode_rgb(t_byte red, t_byte green, t_byte blue)
{
	return (red << 16 | green << 8 | blue);
}

void	my_pixel_put(t_image *i, int x, int y, int color)
{
	int	offset;

	offset = (i->line_len * y) + (x * (i->bits_per_pixel / 8));
	*((unsigned int *)(offset + i->img_pixels_ptr)) = color;
}

void	draw_fractol(t_fractol *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			if (f->set == MANDELBROT)
				calc_mandelbrot(x, y, f);
			else if (f->set == JULIA)
				calc_julia(x, y, f);
			else if (f->set == BURNINGSHIP)
				calc_burningship(x, y, f);
			y++;
		}
		x++;
		y = 0;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img.img_ptr, 0, 0);
}
