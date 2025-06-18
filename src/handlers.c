/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:14:48 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/18 18:10:48 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_iterations(int keysym, t_fractol *f)
{
	if (keysym == 61)
	{
		if (f->max_iterations * 1.2 <= 1200)
			f->max_iterations *= 1.2;
	}
	else if (keysym == 45)
	{
		if (f->max_iterations * 0.8 >= 20)
			f->max_iterations *= 0.8;
	}
}

int	handle_close(t_fractol *f)
{
	exit_fractol(EXIT_SUCCESS, f);
	return (0);
}

int	handle_key_input(int keysym, t_fractol *f)
{
	ft_printf("%d\n", keysym);
	if (keysym == XK_Escape)
		handle_close(f);
	else if (keysym == 65363)
		f->offset_x -= 0.5 * f->zoom;
	else if (keysym == 65361)
		f->offset_x += 0.5 * f->zoom;
	else if (keysym == 65362)
		f->offset_y -= 0.5 * f->zoom;
	else if (keysym == 65364)
		f->offset_y += 0.5 * f->zoom;
	else if (keysym == 45 || keysym == 61)
		handle_iterations(keysym, f);
	else if (keysym == 99)
		f->color_palette = (f->color_palette + 1) % 4;
	else if (keysym == XK_r)
		init_data(f);
	draw_fractol(f);
	return (0);
}

int	handle_mouse_input(int mouse_code, int x, int y, t_fractol *f)
{
	if (mouse_code == SCROLL_UP)
		zoom(f, x, y, ZOOM_IN);
	else if (mouse_code == SCROLL_DOWN)
		zoom(f, x, y, ZOOM_OUT);
	draw_fractol(f);
	return (0);
}
