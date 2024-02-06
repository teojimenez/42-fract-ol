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
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) \
	|| (argc == 2 && !ft_strncmp(argv[1], "tricorn", 7)) \
	|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];

		if(argc == 4)
		{
			if (look_error(argv[2], 1) == 1 || look_error(argv[3], 2) == 1)
				return (0);
			fractol.julia1 = ft_atod(argv[2]);
			fractol.julia2 = ft_atod(argv[3]);
		}
		fractol_init(&fractol);
		render(&fractol);
		fractol_events(&fractol);
		mlx_loop(fractol.mlx_conn);
	}
	else
	{
		write(1, "Error!\nFractal Options:\n./fractol mandelbrot\n./fra", 51);
		write(1, "ctol julia <[-2, 2]> <[-1.5, 1.5]>\n./fractol tricorn\n", 54);
	}
	return (0);
}
