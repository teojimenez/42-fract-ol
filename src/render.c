/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:41:32 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/31 11:41:32 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	map(double n_max, double n_min, double o_max, double nb)
{
	return ((n_max - n_min) * (nb - 0) / (o_max - 0) + n_min);
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * img->bits_px / 8);
	*(unsigned int *)(img->img_pixel_ptr + offset) = color;
}

void	handle_input(t_fractol *fractol, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	ft_init_c(&c, x, y, fractol);
	ft_init_z(&z, x, y, fractol);
	while (++i < fractol->nb_iterations)
	{
		ft_math(fractol, &z, &c);
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = ft_color(fractol, i);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		my_pixel_put(x, y, &fractol->img, BLACK);
	}
}

void	render(t_fractol *f)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
			handle_input(f, x, y);
	}
	mlx_put_image_to_window(f->mlx_conn, f->mlx_window, f->img.img_ptr, 0, 0);
}

// ? real part -> x^2 - y^2 -> z
// * imaginary part -> 2xyi -> c
// * MANDELBROT SET
// Z empieza en 0 y que se va modificando cuando iteramos los puntos
// C es el punto en que estamos situados en el mapa (coordenadas) (C no varia)
// * JULIA SET
// Z es es el punto en que estamos situados en el mapa (coordenadas) 
// y que se va modificando cuando iteramos los puntos
// C es el punto que le pasamos como parametro y que es estatico
// (Porque c no varia)
