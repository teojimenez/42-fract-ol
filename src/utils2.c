/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:10:52 by teojimen          #+#    #+#             */
/*   Updated: 2024/02/06 13:10:52 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_error_print(int type)
{
	if (type == 1)
	{
		write(1, "Error!\nFractal Options:", 24);
		write(1, "\n./fractol mandelbrot", 22);
		write(1, "\n./fractol julia <[-2, 2]> <[-1.5, 1.5]>", 41);
		write(1, "\n./fractol tricorn\n", 20);
	}
	else if (type == 2)
	{
		write(1, "Error! Number exceeds the Julia supported numbers\n", 51);
		write(1, "./fractol julia <[-2, 2]> <[-1.5, 1.5]>\n", 41);
	}
	else if (type == 3)
	{
		write(1, "Error!\n", 8);
	}
	return (1);
}

static int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sig;

	sig = 1;
	i = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = sig * -1;
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sig);
}

static int	check_max(char *s, int flag)
{
	if (flag == 1)
	{
		if (ft_atod(s) < -2.0 || ft_atod(s) > 2.0 \
		|| ft_atoi(s) < -2 || ft_atoi(s) > 2)
			return (1);
	}
	else if (flag == 2)
	{
		if (ft_atod(s) < -1.50 || ft_atod(s) > 1.50)
			return (1);
	}
	return (0);
}

int	look_error(char *argv, int flag)
{
	char	*regex;
	int		i;

	i = 0;
	if (!*argv)
		return (ft_error_print(3));
	else if (check_max(argv, flag) == 1)
		return (ft_error_print(2));
	regex = "-.0123456789";
	while (*argv)
	{
		i = 0;
		while (regex[i] != '\0')
		{
			if (regex[i] == *argv)
				break ;
			i++;
		}
		if (regex[i] == '\0' && regex[i - 1] != *argv)
			return (ft_error_print(3));
		argv++;
	}
	return (0);
}
