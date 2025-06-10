/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:50:04 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/10 17:47:23 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calc_mandelbrot(t_fractol *f)
{
	int		i;
	double	x_temp;

	i = 0;
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	while ((f->zx * f->zx + f->zy * f->zy <= 4) && (++i < f->max_iterations))
//	while (++i < f->max_iterations)
	{
		x_temp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = x_temp;
 		if (f->zx * f->zx + f->zy * f->zy >= __DBL_MAX__)
			break ;
	}
	if (i == f->max_iterations)
		my_pixel_put(&f->mlx_img, f->x, f->y, 0x000000);
	else
//		my_pixel_put(&f->mlx_img, f->x, f->y, i % 0xFFFFFF);
		my_pixel_put(&f->mlx_img, f->x, f->y, (f->color * i));
}
