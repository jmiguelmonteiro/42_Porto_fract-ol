/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:13:43 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/10 16:28:59 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(byte red, byte green, byte blue)
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
	f->x = 0;
	f->y = 0;
	while (f->x < W_SIZE)
	{
		while (f->y < W_SIZE)
		{
			if (f->set == MANDELBROT)
			calc_mandelbrot(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img.img_ptr, 0, 0);
}
