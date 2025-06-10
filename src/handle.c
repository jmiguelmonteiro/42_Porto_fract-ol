/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:14:48 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/10 15:54:07 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

int	handle_key_input(int keysym, t_fractol *f)
{
	ft_printf("The %d key has been pressed!!!\n", keysym);
	if (keysym == XK_Escape)
		exit_fractol(EXIT_SUCCESS, f);
	else if (keysym == XK_Right)
		f->offset_x -= 42 / f->zoom;
	else if (keysym == XK_Left)
		f->offset_x += 42 / f->zoom;
	else if (keysym == XK_Up)
		f->offset_y += 42 / f->zoom;
	else if (keysym == XK_Down)
		f->offset_y -= 42 / f->zoom;
	else if (keysym == XK_r)
		init_data(f);
	draw_fractol(f);
	return (0);
}

int	handle_mouse_input(int mouse_code, int x, int y, t_fractol *f)
{
	if (mouse_code == SCROLL_UP)
		zoom(f, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(f, x, y, -1);
	draw_fractol(f);
	return (0);
}
