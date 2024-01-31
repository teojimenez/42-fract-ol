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

void	handle_input(t_fractol *fractol, int x, int y)
{
	t_complex z;
	t_complex c;
	int i;

	i = -1;

	z.x = 0;
	z.y = 0;

	//hay que escalar el punto a el tamaño de la pantalla
	// x-> new_min: -2
	// y-> new_min: +2
	// map(double new_max, double new_min, double old_max, double old_min, double num_unscaled)
	c.x = map(2, -2, 800, 0, x);
	c.y = map(-2, 2, 800, 0, y);
	while(++i < NB_ITERATIONS)
	{
		//z^2 + c

		// z^2 = x^2 - y^2 + 2xyi
		// ? real part -> x^2 - y^2 -> z
		// * imaginary part -> 2xyi -> c
		// result = z 

		//operations
		if((z.x * z.x) + (z.y * z.y) > 2)//escapes the values ? hypotenusa
		{
			//color //segun la la longitud alterna entre unos valores o otros
			//pixel_put() //outside
			//return ; porque no esta dentro y no hay que verificar nada mas
		}
		//estamos dentro de los valores de mandelbrot
		//pixel_put() //inside

	}

}

void	render(t_fractol *fractol)
{
	int y;
	int x;

	y = -1;
	x = -1;

	while(++y < SIZE_Y)
	{
		while(++x < SIZE_X)
		{
			handle_input(fractol, x, y);
		}
		
	}


	// mlx_put_image_to_window()
}