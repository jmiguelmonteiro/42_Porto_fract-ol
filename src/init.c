/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:01:03 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/06 18:45:15 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_struct(t_fractol *fractol)
{
	fractol->set = 0;
	fractol->cx = 1;
	fractol->cy = 1;
}

static void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init;
	if (!fractol->mlx)
		exit(EXIT_FAILURE);
	fractol->window = mlx_new_window(fractol->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
		"Josemigu's Fract-ol");
	fractol->image = mlx_new_image(fractol->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void	init_all(t_fractol *fractol)
{
	init_struct(fractol);
	init_mlx(fractol);
}
