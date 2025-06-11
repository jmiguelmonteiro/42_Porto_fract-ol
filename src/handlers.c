/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:14:48 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/11 19:15:53 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_close(t_fractol *f)
{
	exit_fractol(EXIT_SUCCESS, f);
	return (0);
}

int	handle_key_input(int keysym, t_fractol *f)
{
	ft_printf("The %d key has been pressed!!!\n", keysym);
	if (keysym == XK_Escape)
		handle_close(f);
	else if (keysym == 65432)
		f->offset_x -= 0.5 * f->zoom;
	else if (keysym == 65430)
		f->offset_x += 0.5 * f->zoom;
	else if (keysym == 65431)
		f->offset_y -= 0.5 * f->zoom;
	else if (keysym == 65433)
		f->offset_y += 0.5 * f->zoom;
	else if (keysym == 65451)
	{
		if (f->max_iterations * 1.2 <= 120)
			f->max_iterations *= 1.2;
	}
	else if (keysym == 65453)
	{
		if (f->max_iterations * 0.8 >= 20)
			f->max_iterations *= 0.8;
	}
	else if (keysym == 65438)
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
