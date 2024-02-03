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

int close_handler(t_fractol *fractol)
{
    mlx_destroy_window(fractol->mlx_conn, fractol->mlx_window); //destroy img
	mlx_clear_window(fractol->mlx_conn, fractol->mlx_window);
    mlx_destroy_image(fractol->mlx_conn, fractol->img.img_ptr); //destroy windw
    // free(fractol->mlx_conn); //sino da leaks
    exit(0); //sale de forma correcta
	// return (0);
}
int mouse_handler(int keycode, int x, int y, t_fractol *fractol)
{
	x = 0;
	y = 0;
	if(keycode == 5) //zoom up
        fractol->zoom *= 0.95;
    else if(keycode == 4) //zoom up
        fractol->zoom *= 1.05;
	
	//arriba 5 zooom up
	//abajo 4 zoom down
	mlx_clear_window(fractol->mlx_conn, fractol->mlx_window);
	render(fractol);
	return (0);
}

int key_handler(int keycode, t_fractol *fractol)
{
    if (keycode == KEY_ESC)
        close_handler(fractol);
	printf("\n%i", keycode);
    if (keycode == KEY_LEFT)
        fractol->moveX -= (0.5 * fractol->zoom);
    else if (keycode == KEY_RIGHT)
        fractol->moveX += (0.5 * fractol->zoom);
    else if (keycode == KEY_UP)
        fractol->moveY += (0.5 * fractol->zoom);
    else if (keycode == KEY_DOWN)
        fractol->moveY -= (0.5 * fractol->zoom);
	if (keycode == 49)
	{
		if(fractol->i_color == 3)
			fractol->i_color = 1;
		else
			fractol->i_color++;
	}
    mlx_clear_window(fractol->mlx_conn, fractol->mlx_window);
    render(fractol);
    return (0);
}



void fractol_events(t_fractol *fractol)
{
    mlx_mouse_hook(fractol->mlx_window, mouse_handler, fractol);
    mlx_hook(fractol->mlx_window, 02, 0, key_handler, fractol);
    // mlx_hook(fractol->mlx_window, 04, 0, mouse_handler, fractol);
    mlx_hook(fractol->mlx_window, 17, 0, close_handler, fractol);
}