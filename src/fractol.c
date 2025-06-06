/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:20:49 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/06 16:13:42 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_printf("Usage: ./fractol <fractal> [j1] [j2]\n" \
		"<fractal> can be: julia, mandelbrot\n" \
		"[j1] [j2] can be between -2.0 and 2.0 to set"
		" julia's fractal initial values\n");
	exit (1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		usage();
	return (0);
}
