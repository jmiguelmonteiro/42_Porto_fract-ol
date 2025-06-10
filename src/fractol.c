/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:20:49 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/10 15:54:37 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_all(&fractol);
	process_args(argc, argv, &fractol);
	mlx_key_hook(fractol.mlx_win, handle_key_input, &fractol);
	mlx_mouse_hook(fractol.mlx_win, handle_mouse_input, &fractol);
	draw_fractol(&fractol);
	mlx_loop(fractol.mlx);

	return (EXIT_SUCCESS);
}
