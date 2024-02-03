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

#include "fractol.h"

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_conn = mlx_init();
   	if(!fractol->mlx_conn)
		exit(1); //leave
	fractol->mlx_window = mlx_new_window(fractol->mlx_conn, SIZE_X, SIZE_Y, fractol->name);
	if(!fractol->mlx_window)
	{
		mlx_destroy_window(fractol->mlx_conn, fractol->mlx_window);  //destroy windw
		free(fractol->mlx_conn);
		exit(1);
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_conn, SIZE_X, SIZE_Y);
	if(!fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_conn, fractol->mlx_window); //destroy img
		mlx_destroy_image(fractol->mlx_conn, fractol->img.img_ptr); //destroy windw
		free(fractol->mlx_conn);
		exit(1);
	}
	fractol->img.img_pixel_ptr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bits_per_pixel, \
	&fractol->img.line_length, &fractol->img.endian); 
	
	fractol->nb_iterations = 50;
	fractol->zoom = 1.00;
	fractol->moveX = 0.00;
	fractol->moveY = 0.00;
	fractol->i_color = 1;

}
