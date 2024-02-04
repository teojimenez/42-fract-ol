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

void	ft_zoom(double x, double y, t_fractol *fractal)
{
	fractal->moveX = (x / fractal->zoom) - (x / (fractal->zoom * 2.5));
	fractal->moveX = (y / fractal->zoom) - (y / (fractal->zoom * 2.5));
	fractal->zoom *= 2.5;
	// fractal->iterations++;
}

void	ft_dezoom(double x, double y, t_fractol *fractal)
{
	fractal->moveX = (x / fractal->zoom) - (x / (fractal->zoom / 2.5));
	fractal->moveY = (y / fractal->zoom) - (y / (fractal->zoom / 2.5));
	fractal->zoom /= 2.5;
	// fractal->iterations--;
}

int mouse_handler(int keycode, int x, int y, t_fractol *fractol)
{
	
    // printf("X->%i\n", x);
    // printf("Y->%i\n", y);
    // x = 0;
	// y = 0;
    if (keycode == 4)
		ft_zoom(((double) x / 800 * 1000 - 500),
			((double) y / 800 * 1000 - 500), fractol);
	else if (keycode == 5)
		ft_dezoom(((double) x / 800 * 1000 - 500),
			((double) y / 800 * 1000 - 500), fractol);
	// if(keycode == 5) //zoom up
    // {
    //     // fractol->zoom *= 0.95;
    //     // fractol->zoom *= 0.95;

    //     printf("X->%i\n", x);
    //     printf("Y->%i\n", y);
    //     printf("ARRIBA\n");
    //     if(x > 400)
    //         fractol->moveX += ((x / 700) * fractol->zoom);//este
    //     else
    //         fractol->moveX -= ((x / 700) * fractol->zoom);

    //     if(y > 400)
    //         fractol->moveY += ((y / 700) * fractol->zoom);
    //     else
    //         fractol->moveY -= ((y / 700) * fractol->zoom); //este
    // }
    // else if(keycode == 4) //zoom up
    // {
    //     // fractol->zoom *= 1.05;
    //     // fractol->zoom *= 1.05;
    //     printf("X->%i\n", x);
    //     printf("Y->%i\n", y);
    //     if(x > 400)
    //         fractol->moveX -= ((x / 700) * fractol->zoom);
    //     else
    //         fractol->moveX += ((x / 700) * fractol->zoom);

    //     if(y > 400)
    //         fractol->moveY -= ((y / 700) * fractol->zoom);
    //     else
    //         fractol->moveY += ((y / 700) * fractol->zoom);
    // }
	
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
	// printf("\n%i", keycode);
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