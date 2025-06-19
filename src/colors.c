/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:46:25 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/19 17:36:36 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	get_rainbow_palette2(double t, int *r, int *g, int *b)
{
	if (t < 4.0 / 6.0)
	{
		*g = (int)(255 * (4 - 6 * t));
		*b = 255;
	}
	else if (t < 5.0 / 6.0)
	{
		*r = (int)(255 * (6 * t - 4));
		*b = 255;
	}
	else
	{
		*r = 255;
		*b = (int)(255 * (6 - 6 * t));
	}
}

static int	get_rainbow_palette(double smooth_iter, int r, int g, int b)
{
	double	t;

	t = fmod(smooth_iter * 0.05, 1.0);
	if (t < 1.0 / 6.0)
	{
		r = 255;
		g = (int)(255 * 6 * t);
	}
	else if (t < 2.0 / 6.0)
	{
		r = (int)(255 * (2 - 6 * t));
		g = 255;
	}
	else if (t < 3.0 / 6.0)
	{
		g = 255;
		b = (int)(255 * (6 * t - 2));
	}
	else
		get_rainbow_palette2(t, &r, &g, &b);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(double smooth_iter, t_fractol *f)
{
	if (f->color_palette == 0)
		return (get_fire_palette(smooth_iter, f));
	else if (f->color_palette == 1)
		return (get_blue_palette(smooth_iter));
	else if (f->color_palette == 2)
		return (get_purple_palette(smooth_iter, f));
	return (get_rainbow_palette(smooth_iter, 0, 0, 0));
}
