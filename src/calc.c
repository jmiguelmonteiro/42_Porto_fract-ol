/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:50:04 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/11 17:34:51 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(int x, int y, t_fractol *f)
{
	int			iter;
	double		r_temp;
	int			color;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = map(x, -2, 2, WIDTH) * f->zoom + f->offset_x;
	c.i = map(y, 2, -2, HEIGHT) * f->zoom + f->offset_y;
	while (++iter < f->max_iterations)
	{
		r_temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2. * z.r * z.i + c.i;
		z.r = r_temp;
		if ((z.r * z.r + z.i * z.i) > 4)
		{
			color = map(iter, BLACK, WHITE, f->max_iterations);
			my_pixel_put(&f->mlx_img, x, y, color);
			return ;
		}
	}
	my_pixel_put(&f->mlx_img, x, y, 0x000000);
}

void	calc_julia(int x, int y, t_fractol *f)
{
	int			iter;
	double		r_temp;
	int			color;
	t_complex	z;
	t_complex	c;

	iter = 0;
	c.r = f->julia.r;
	c.i = f->julia.i;
	z.r = map(x, -2, 2, WIDTH) * f->zoom + f->offset_x;
	z.i = map(y, 2, -2, HEIGHT) * f->zoom + f->offset_y;
	while (++iter < f->max_iterations)
	{
		r_temp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2. * z.r * z.i + c.i;
		z.r = r_temp;
		if ((z.r * z.r + z.i * z.i) > 4)
		{
			color = map(iter, BLACK, WHITE, f->max_iterations);
			my_pixel_put(&f->mlx_img, x, y, color);
			return ;
		}
	}
	my_pixel_put(&f->mlx_img, x, y, 0x000000);
}

void	calc_burningship(int x, int y, t_fractol *f)
{
	int			iter;
	double		r_temp;
	int			color;
	t_complex	z;
	t_complex	c;

	iter = 0;
	z.r = 0.0;
	z.i = 0.0;
	c.r = map(x, -2, 2, WIDTH) * f->zoom + f->offset_x;
	c.i = map(y, 2, -2, HEIGHT) * f->zoom + f->offset_y;
	while (++iter < f->max_iterations)
	{
		r_temp = z.r * z.r - z.i * z.i + c.r;
		z.i = fabs(2. * z.r * z.i) + c.i;
		z.r = fabs(r_temp);
		if ((z.r * z.r + z.i * z.i) > 4)
		{
			color = map(iter, BLACK, WHITE, f->max_iterations);
			my_pixel_put(&f->mlx_img, x, y, color);
			return ;
		}
	}
	my_pixel_put(&f->mlx_img, x, y, 0x000000);
}
