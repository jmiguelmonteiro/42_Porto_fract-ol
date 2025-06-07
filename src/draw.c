/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:13:43 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/07 17:18:39 by josemigu         ###   ########.fr       */
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

void	color_screen(t_fractol *f, int color)
{
	for (int y = 0; y < W_HEIGHT; ++y)
	{
		for (int x = 0; x < W_WIDTH; ++x)
		{
//			mlx_pixel_put(f->mlx, f->mlx_win, x, y, color);
			my_pixel_put(&f->mlx_img, x, y, color);
		}
	}
}

