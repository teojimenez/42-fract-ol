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

int rgbToInt(int red, int green, int blue) 
{
    red = (red < 0) ? 0 : ((red > 255) ? 255 : red);
    green = (green < 0) ? 0 : ((green > 255) ? 255 : green);
    blue = (blue < 0) ? 0 : ((blue > 255) ? 255 : blue);

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
	c.x = (map(2, -2, SIZE_X, 0, x) * fractol->zoom) + fractol->moveX;
	c.y = (map(-2, 2, SIZE_Y, 0, y) * fractol->zoom) + fractol->moveY;

	if(!ft_strncmp(fractol->name, "julia", 5))
	{
		c.x = fractol->julia1;
		c.y = fractol->julia2;	
		z.x = (map(2, -2, SIZE_X, 0, x) * fractol->zoom) + fractol->moveX;
		z.y = (map(-2, 2, SIZE_Y, 0, y) * fractol->zoom) + fractol->moveY;
	}
	while(++i < fractol->nb_iterations)
	{
		// ? real part -> x^2 - y^2 -> z
		// * imaginary part -> 2xyi -> c
		
		temp_real = (z.x * z.x) - (z.y * z.y);
		if(!ft_strncmp(fractol->name, "tricorn", 7))
			temp_img = -2 * z.x * z.y;
		else
			temp_img = 2 * z.x * z.y;
		z.x = temp_real + c.x;
		z.y = temp_img + c.y;
		if((z.x * z.x) + (z.y * z.y) > 4)
		{
			int test = (int)map(2000, 0, 170, 0, i);
			if(fractol->i_color == 1)
				color = rgbToInt((int)map(255, 50, 170, 0, i*5), test, test);
			else if(fractol->i_color == 2)
				color = rgbToInt(test, (int)map(255, 50, 170, 0, i*5), test);
			else
				color = rgbToInt(test, test, (int)map(255, 50, 170, 0, i*5));
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		my_pixel_put(x, y, &fractol->img, BLACK);
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
		x = -1;
		while(++x < SIZE_X)
			handle_input(fractol, x, y);
	}
	mlx_put_image_to_window(fractol->mlx_conn, fractol->mlx_window, fractol->img.img_ptr, 0, 0);
}

// * MANDELBROT SET
// Z empieza en 0 y que se va modificando cuando iteramos los puntos
// C es el punto en que estamos situados en el mapa (coordenadas) (C no varia)
// * JULIA SET
// Z es es el punto en que estamos situados en el mapa (coordenadas)  y que se va modificando cuando iteramos los puntos
//C es el punto que le pasamos como parametro y que es estatico (Porque c no varia)