/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:28:03 by teojimen          #+#    #+#             */
/*   Updated: 2024/02/01 12:28:03 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx_conn, fractol->mlx_window);
	mlx_clear_window(fractol->mlx_conn, fractol->mlx_window);
	mlx_destroy_image(fractol->mlx_conn, fractol->img.img_ptr);
	exit(0);
}

int	mouse_handler(int keycode, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if (keycode == 4)
		fractol->zoom *= 1.20;
	else if (keycode == 5)
		fractol->zoom *= 0.80;
	mlx_clear_window(fractol->mlx_conn, fractol->mlx_window);
	render(fractol);
	return (0);
}

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		close_handler(fractol);
	else if (keycode == KEY_LEFT)
		fractol->move_x -= (0.5 * fractol->zoom);
	else if (keycode == KEY_RIGHT)
		fractol->move_x += (0.5 * fractol->zoom);
	else if (keycode == KEY_UP)
		fractol->move_y += (0.5 * fractol->zoom);
	else if (keycode == KEY_DOWN)
		fractol->move_y -= (0.5 * fractol->zoom);
	else if (keycode == KEY_SPACE)
	{
		if (fractol->i_color == 3)
			fractol->i_color = 1;
		else
			fractol->i_color++;
	}
	mlx_clear_window(fractol->mlx_conn, fractol->mlx_window);
	render(fractol);
	return (0);
}

void	fractol_events(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->mlx_window, mouse_handler, fractol);
	mlx_hook(fractol->mlx_window, 02, 0, key_handler, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, close_handler, fractol);
}
