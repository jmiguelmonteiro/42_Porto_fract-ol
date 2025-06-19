/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:34:14 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/19 17:35:09 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_fire_palette(double smooth_iter, t_fractol *f)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = smooth_iter / f->max_iterations;
	if (t < 0.33)
	{
		r = 255;
		g = (int)(255 * (t / 0.33));
		b = 0;
	}
	else if (t < 0.66)
	{
		r = 255;
		g = 255;
		b = (int)(255 * ((t - 0.33) / 0.33));
	}
	else
	{
		r = 255 - (int)(255 * ((t - 0.66) / 0.34));
		g = 255 - (int)(128 * ((t - 0.66) / 0.34));
		b = 255;
	}
	return ((r << 16) | (g << 8) | b);
}

int	get_blue_palette(double smooth_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = fmod(smooth_iter * 0.1, 1.0);
	r = (int)(128 + 127 * sin(t * 2 * M_PI));
	g = (int)(128 + 127 * sin(t * 2 * M_PI + M_PI / 3));
	b = (int)(200 + 55 * sin(t * 2 * M_PI + 2 * M_PI / 3));
	return ((r << 16) | (g << 8) | b);
}

int	get_purple_palette(double smooth_iter, t_fractol *f)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = smooth_iter / f->max_iterations;
	r = (int)(128 + 127 * cos(t * 4 * M_PI));
	g = (int)(50 + 100 * sin(t * 6 * M_PI));
	b = (int)(200 + 55 * sin(t * 3 * M_PI));
	return ((r << 16) | (g << 8) | b);
}
