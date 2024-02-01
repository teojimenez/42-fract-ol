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

#include "fractol.h"

// [0..799] [-2..+2]
double map(double new_max, double new_min, double old_max, double old_min, double num_unscaled)
{
	return (new_max - new_min) * (num_unscaled - old_min) / (old_max - old_min) + new_min;
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;
	offset = (y * img->line_length) + (x * img->bits_per_pixel / 8);
	*(unsigned int *)(img->img_pixel_ptr + offset) = color;

}

/* Por cada posicion del plano, iteramos tantas veces como se indique a partir
del punto proporcionado, mapeado a nivel del plano. En esas iteraciones verificamos si esos puntos
estarias dentro o fuera del fractal, en caso de estar fuera, nos vamos de la funcion puesto que
si un punto ya esta fuera, los otros tambien lo estaran */
void	handle_input(t_fractol *fractol, int x, int y)
{
	t_complex z;
	t_complex c;
	int i;
	double	temp_real;
	double	temp_img;
	// int color;
	i = -1;

	z.x = 0.0;
	z.y = 0.0;

	//hay que escalar el punto a el tamaño de la pantalla
	// x-> new_min: -2
	// y-> new_min: +2
	// map(double new_max, double new_min, double old_max, double old_min, double num_unscaled)
	c.x = map(2, -2, SIZE_X, 0, x);
	c.y = map(-2, 2, SIZE_Y, 0, y);

/* pinta {x, y} en la posicion indicada hasta que encuentra uno que esta fuera y sale | 
sale cuando el f(z) es mas grande que la hypotenusa = h = ^(x^2 + y^2)
*/
	while(++i < fractol->nb_iterations)
	{
		//z^2 + c

		// z^2 = x^2 - y^2 + 2xyi
		// ? real part -> x^2 - y^2 -> z
		// * imaginary part -> 2xyi -> c
		

		temp_real = (z.x * z.x) - (z.y * z.y);
		temp_img = 2 * z.x * z.y;

		z.x = temp_real + c.x;
		z.y = temp_img + c.y;

		//operations
		if((z.x * z.x) + (z.y * z.y) > 4)//escapes the values ? hypotenusa
		{
			//color //segun la la longitud alterna entre unos valores o otros
			// color = map(RED, WHITE, NB_ITERATIONS, 0, i);
			//pixel_put() //outside
			// mlx_pixel_put(fractol->mlx_conn, fractol->mlx_window, x, y, WHITE);
			my_pixel_put(x, y, &fractol->img, WHITE);
			return ; //porque no esta dentro y no hay que verificar nada mas
		}
		//estamos dentro de los valores de mandelbrot
		my_pixel_put(x, y, &fractol->img, BLACK);
		// mlx_pixel_put(fractol->mlx_conn, fractol->mlx_window, x, y, BLACK);
		//pixel_put() //inside
	}

}

void	render(t_fractol *fractol)
{
	int y;
	int x;

	y = -1;
	x = -1;
	//por cada posicion del plano
	while(++y < SIZE_Y)
	{
		x = -1;
		while(++x < SIZE_X)
		{
			handle_input(fractol, x, y);
		}
	}
	t_complex try;

	x = 400;
	y = 50;

	while(x < 430)
	{
		try.x = map(2, -2, SIZE_X, 0, x);
		try.y = map(-2, 2, SIZE_Y, 0, y);
		my_pixel_put(x, y, &fractol->img, GREEN);
		x++;
	}
	mlx_put_image_to_window(fractol->mlx_conn, fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}