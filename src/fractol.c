/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:20:49 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/07 17:17:57 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_input(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed!!!\n", keysym);
		exit_fractol(EXIT_SUCCESS, f);
	} else if (keysym == XK_r)
		color_screen(f, encode_rgb(255, 0, 0));
	else if (keysym == XK_g)
		color_screen(f, encode_rgb(0, 255, 0));
	else if (keysym == XK_b)
		color_screen(f, encode_rgb(0, 0, 255));
	mlx_put_image_to_window(f->mlx, f->mlx_win, f->mlx_img.img_ptr, 0, 0);
	ft_printf("The %d key has been pressed!!!\n", keysym);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	(void)argc;
	(void)argv;
	
	init_all(&fractol);
	mlx_key_hook(fractol.mlx_win, handle_key_input, &fractol);
//	process_args(argc, argv, &fractol);
	mlx_loop(fractol.mlx);

	return (EXIT_SUCCESS);
}
