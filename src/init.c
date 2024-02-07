/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:04:48 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/31 10:04:48 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_var(t_fractol *f)
{
	f->nb_iterations = 100;
	f->zoom = 1.00;
	f->move_x = 0.00;
	f->move_y = 0.00;
	f->i_color = 1;
}

void	fractol_init(t_fractol *f)
{
	f->mlx_conn = mlx_init();
	if (!f->mlx_conn)
		exit(1);
	f->mlx_window = mlx_new_window(f->mlx_conn, SIZE_X, SIZE_Y, f->name);
	if (!f->mlx_window)
	{
		mlx_destroy_window(f->mlx_conn, f->mlx_window);
		free(f->mlx_conn);
		exit(1);
	}
	f->img.img_ptr = mlx_new_image(f->mlx_conn, SIZE_X, SIZE_Y);
	if (!f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx_conn, f->mlx_window);
		mlx_destroy_image(f->mlx_conn, f->img.img_ptr);
		free(f->mlx_conn);
		exit(1);
	}
	f->img.img_pixel_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bits_px, \
	&f->img.line_length, &f->img.endian);
	init_var(f);
}
