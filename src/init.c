/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:01:03 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/10 18:07:13 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_fractol *f)
{
	f->color = 0xFCBE11;
	f->offset_x = 0;
	f->offset_y = 0;
	f->zoom = 1500;
	f->max_iterations = 42;
}

static void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit_fractol(EXIT_FAILURE, f);
	f->mlx_win = mlx_new_window(f->mlx, 
		W_SIZE, W_SIZE, "Josemigu's Fract-ol");
	if (!f->mlx_win)
		exit_fractol(EXIT_FAILURE, f);
	f->mlx_img.img_ptr = mlx_new_image(
		f->mlx,
		W_SIZE,
		W_SIZE);
	if (!f->mlx_img.img_ptr)
		exit_fractol(EXIT_FAILURE, f);
	f->mlx_img.img_pixels_ptr = mlx_get_data_addr(
		f->mlx_img.img_ptr,
		&f->mlx_img.bits_per_pixel,
		&f->mlx_img.line_len,
		&f->mlx_img.endian);
}

void	init_all(t_fractol *f)
{
	init_data(f);
	init_mlx(f);
}
