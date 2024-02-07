/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:41:07 by teojimen          #+#    #+#             */
/*   Updated: 2024/02/07 12:41:07 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_math(t_fractol *f, t_complex *z, t_complex *c)
{
	double		temp_real;
	double		temp_img;

	temp_real = ((*z).x * (*z).x) - ((*z).y * (*z).y);
	if (!ft_strncmp(f->name, "tricorn", 7))
		temp_img = -2 * (*z).x * (*z).y;
	else
		temp_img = 2 * (*z).x * (*z).y;
	(*z).x = temp_real + (*c).x;
	(*z).y = temp_img + (*c).y;
}

int	ft_color(t_fractol *f, int i)
{
	int	test;

	test = (int)map(2000, 0, 170, i);
	if (f->i_color == 1)
		return (rgb_to_int((int)map(255, 50, 170, i * 5), test, test));
	else if (f->i_color == 2)
		return (rgb_to_int(test, (int)map(255, 50, 170, i * 5), test));
	else
		return (rgb_to_int(test, test, (int)map(255, 50, 170, i * 5)));
}

void	ft_init_c(t_complex *c, int x, int y, t_fractol *f)
{
	(*c).x = (map(2, -2, SIZE_X, x) * f->zoom) + f->move_x;
	(*c).y = (map(-2, 2, SIZE_Y, y) * f->zoom) + f->move_y;
	if (!ft_strncmp(f->name, "julia", 5))
	{
		(*c).x = f->julia1;
		(*c).y = f->julia2;
	}
}

void	ft_init_z(t_complex *z, int x, int y, t_fractol *f)
{
	(*z).x = 0;
	(*z).y = 0;
	if (!ft_strncmp(f->name, "julia", 5))
	{
		(*z).x = (map(2, -2, SIZE_X, x) * f->zoom) + f->move_x;
		(*z).y = (map(-2, 2, SIZE_Y, y) * f->zoom) + f->move_y;
	}
}

int	rgb_to_int(int red, int green, int blue)
{
	if (red < 0)
		red = 0;
	else if (red > 255)
		red = 255;
	if (green < 0)
		green = 0;
	else if (green > 255)
		green = 255;
	if (blue < 0)
		blue = 0;
	else if (blue > 255)
		blue = 255;
	return ((red << 16) | (green << 8) | blue);
}
