/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:25:06 by josemigu          #+#    #+#             */
/*   Updated: 2025/06/06 18:43:02 by josemigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Includes */
# include <mlx.h>
# include <libft.h>
# include <math.h>

/*  Fractal sets	*/
# define MANDELBROT 1
# define JULIA 2

/*  Window dimensions  */
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 600

/* Structure */
typedef struct s_fractol
{
	int		set;
	double	cx;
	double	cy;
	void	*mlx;
	void	*window;
	void	*image;
}	t_fractol;

/* Functions */
void	process_args(int argc, char **argv, t_fractol *fractol);
double	ft_atof(char *str);
void	init_all(t_fractol *fractol);

#endif
