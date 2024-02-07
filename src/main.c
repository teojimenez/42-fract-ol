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

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) \
	|| (argc == 2 && !ft_strncmp(argv[1], "tricorn", 7)) \
	|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		if (ft_strlen(argv[1]) > ft_strlen(fractol.name))
			return (ft_error_print(1));
		if (argc == 4)
		{
			if (look_error(argv[2], 1) == 1 || look_error(argv[3], 2) == 1)
				return (1);
			fractol.julia1 = ft_atod(argv[2]);
			fractol.julia2 = ft_atod(argv[3]);
		}
		fractol_init(&fractol);
		render(&fractol);
		fractol_events(&fractol);
		mlx_loop(fractol.mlx_conn);
	}
	else
		return (ft_error_print(1));
	return (0);
}
