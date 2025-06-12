/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:20:49 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/12 09:39:36 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	process_args(argc, argv, &fractol);
	init_all(&fractol);
	mlx_key_hook(fractol.mlx_win, handle_key_input, &fractol);
	mlx_mouse_hook(fractol.mlx_win, handle_mouse_input, &fractol);
	mlx_hook(fractol.mlx_win, DestroyNotify, StructureNotifyMask,
		handle_close, &fractol);
	draw_fractol(&fractol);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
}
