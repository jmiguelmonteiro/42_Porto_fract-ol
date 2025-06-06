/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:42:08 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/06 18:42:54 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_printf("Usage: ./fractol <fractal> [cx cy]\n" \
		"<fractal> can be: julia, mandelbrot\n" \
		"[j1] [j2] can be between -2.0 and 2.0 to set"
		" julia's fractal initial values\n");
	exit (EXIT_FAILURE);
}

void	process_args(int argc, char **argv, t_fractol *fractol)
{
	if ((argc >= 2) && (argc <= 4) && (ft_strncmp(argv[1], "julia", 6) == 0))
	{
		fractol->set = JULIA;
		if (argc >= 3)
		{
			if (argc < 4)
				usage();
			else
			{
				if ((ft_atof(argv[2]) < -2.0) || (ft_atof(argv[3]) < -2.0)
					|| (ft_atof(argv[2]) > 2.0) || (ft_atof(argv[3]) > 2.0))
					usage();
				else
				{
					fractol->cx = ft_atof(argv[2]);
					fractol->cy = ft_atof(argv[3]);
				}
			}
		}
	}
	else if ((argc == 2) && (ft_strncmp(argv[1], "mandelbrot", 11) == 0))
		fractol->set = MANDELBROT;
	else
		usage();
}
