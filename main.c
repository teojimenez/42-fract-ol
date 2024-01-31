/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:22:30 by teojimene         #+#    #+#             */
/*   Updated: 2024/01/30 18:22:30 by teojimene        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol fractol;
	
	if(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))//mandelbrot
	{
		fractol.name = argv[1];
		fractol_init(&fractol);
		render(&fractol);
		mlx_loop(fractol.mlx_conn);
	}
	// else
		// exit(1);
	return (0);
}