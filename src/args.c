/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:42:08 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/19 18:11:50 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_printf("Usage:\n" \
"\t./fractol mandelbrot\n" \
"\t./fractol julia {real} {imaginary}\n" \
"\t\treal and imaginary between -2.0 and 2.0\n" \
"\t./fractol burningship\n\n" \
"\tCursor keys to move fractal\n" \
"\tMouse wheel to zoom in and out\n" \
"\t+/- to increase/decrease max iterations\n" \
"\tC to shift color range\n" \
"\tR to reset view\n");
	exit (EXIT_FAILURE);
}

void	process_args(int argc, char **argv, t_fractol *fractol)
{
	if ((argc == 4) && (ft_strncmp(argv[1], "julia", 6) == 0))
	{
		fractol->set = JULIA;
		if ((ft_atof(argv[2]) < -2.0) || (ft_atof(argv[3]) < -2.0)
			|| (ft_atof(argv[2]) > 2.0) || (ft_atof(argv[3]) > 2.0))
			usage();
		else
		{
			fractol->julia.r = ft_atof(argv[2]);
			fractol->julia.i = ft_atof(argv[3]);
		}
	}
	else if ((argc == 2) && (ft_strncmp(argv[1], "mandelbrot", 11) == 0))
		fractol->set = MANDELBROT;
	else if ((argc == 2) && (ft_strncmp(argv[1], "burningship", 12) == 0))
		fractol->set = BURNINGSHIP;
	else
		usage();
}
