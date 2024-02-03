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
int rgbToInt(int red, int green, int blue) {
    // Asegurarse de que los valores estén en el rango correcto (0-255)
    red = (red < 0) ? 0 : ((red > 255) ? 255 : red);
    green = (green < 0) ? 0 : ((green > 255) ? 255 : green);
    blue = (blue < 0) ? 0 : ((blue > 255) ? 255 : blue);

    // Combinar los componentes en un solo entero (formato: 0xRRGGBB)
    int colorInt = (red << 16) | (green << 8) | blue;

    return colorInt;
}

void	handle_input(t_fractol *fractol, int x, int y)
{
	t_complex z;
	t_complex c;
	int i;
	double	temp_real;
	double	temp_img;
	int color;

	i = -1;

	z.x = 0;
	z.y = 0;
	c.x = (map(2, -2, SIZE_X, 0, x) * fractol->zoom) + fractol->moveX * fractol->zoom;
	c.y = (map(-2, 2, SIZE_Y, 0, y) * fractol->zoom) + fractol->moveY * fractol->zoom;
	// c.x = (map(2, -2, SIZE_X, 0, x) * fractol->zoom) + fractol->moveX;
	// c.y = (map(-2, 2, SIZE_Y, 0, y) * fractol->zoom) + fractol->moveY;

	if(!ft_strncmp(fractol->name, "julia", 5))
	{
		c.x = fractol->julia1;
		c.y = fractol->julia2;	
		z.x = (map(2, -2, SIZE_X, 0, x) * fractol->zoom) + fractol->moveX;
		z.y = (map(-2, 2, SIZE_Y, 0, y) * fractol->zoom) + fractol->moveY;
	}

	// z.x = 0;
	// z.y = 0;

	//hay que escalar el punto a el tamaño de la pantalla
	// x-> new_min: -2
	// y-> new_min: +2
	// map(double new_max, double new_min, double old_max, double old_min, double num_unscaled)
	// z.x = map(2, -2, SIZE_X, 0, x) * fractol->zoom;
	// z.y = map(-2, 2, SIZE_Y, 0, y) * fractol->zoom;

	// c.x = map(2, -2, SIZE_X, 0, x) * fractol->zoom;
	// c.y = map(-2, 2, SIZE_Y, 0, y) * fractol->zoom;

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
		if(!ft_strncmp(fractol->name, "tricorn", 7))
			temp_img = -2 * z.x * z.y;
		else
			temp_img = 2 * z.x * z.y;
		z.x = temp_real + c.x;
		z.y = temp_img + c.y;

		//operations


		/* COLORES */
		//los que hacen mas iteraciones son los que mas cerca del fractal estan
		//y viceversa

		//maximo en 2000 para que sea mas oscuro
		//color = rgbToInt((int)map(255, 50, 170, 0, i*5), test, test);
		//aqui es 50 porque mas abajo de 50 es negro y le multiplicamos i * 5
		//indiferente entre multiplicar los otros valores

		if((z.x * z.x) + (z.y * z.y) > 4)//escapes the values ? hypotenusa
		{
			//  && i >= (fractol->nb_iteratins / 2o)
			//color //segun la la longitud alterna entre unos valores o otros
			// double map(double new_max, double new_min, double old_max, double old_min, double num_unscaled)
			int test = (int)map(2000, 0, 170, 0, i);
			if(fractol->i_color == 1)
				color = rgbToInt((int)map(255, 50, 170, 0, i*5), test, test);
			else if(fractol->i_color == 2)
				color = rgbToInt(test, (int)map(255, 50, 170, 0, i*5), test);
			else
				color = rgbToInt(test, test, (int)map(255, 50, 170, 0, i*5));
			
			// if (i < 1)1
			// 	color = BLUE1;
			// else if (i < 2)
			// 	color = BLUE2;
			// else if (i < 3)
			// 	color = BLUE3;
			// else if (i < 4)
			// 	color = BLUE4;
			// else if (i < 5)
			// 	color = BLUE5;
			// else if (i < 129)
			// {
			// 	int test = (int)map(255, 0, 170, 0, i);
			// 	color = rgbToInt(test, test, 255);
			// }
			// else if (i < 159)
			// 	color = 0xFFFFFF;
			// else if (i < 165)
			// 	color = 0x0E18C2B;
			// else if (i < 166)
			// 	color = 0x009EB2;
			// else if (i < 167)
			// 	color = 0x00FFEB;
			// else if (i < 168)
			// 	color = HOLA;
			// else if (i < 169)
			// 	color = BLUE6;
			// else
			// 	color = WHITE;
			// color = map(P_GREEN, WHITE, NB_ITERATIONS, 0, i);
			//pixel_put() //outside
			// mlx_pixel_put(fractol->mlx_conn, fractol->mlx_window, x, y, WHITE);
			my_pixel_put(x, y, &fractol->img, color);
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
	// t_complex try;

	// x = 400;
	// y = 50;

	// while(x < 430)
	// {
	// 	try.x = map(2, -2, SIZE_X, 0, x);
	// 	try.y = map(-2, 2, SIZE_Y, 0, y);
	// 	my_pixel_put(x, y, &fractol->img, GREEN);
	// 	x++;
	// }
	mlx_put_image_to_window(fractol->mlx_conn, fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}



// MANDELBROT SET

// Z empieza en 0 y que se va modificando cuando iteramos los puntos
// C es el punto en que estamos situados en el mapa (coordenadas) (C no varia)

//JULIA SET

// Z es es el punto en que estamos situados en el mapa (coordenadas)  y que se va modificando cuando iteramos los puntos
//C es el punto que le pasamos como parametro y que es estatico (Porque c no varia)