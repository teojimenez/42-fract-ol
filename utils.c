/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:54:41 by teojimen          #+#    #+#             */
/*   Updated: 2024/01/31 09:54:41 by teojimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		len_s1;

	len_s1 = ft_strlen(s1);
	i = 0;
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	while (i < n && (int)i <= len_s1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
double	ft_decim(char *str, double nb)
{
	double i;

	i = 10.0;
    while (*str >= '0' && *str <= '9')
    {
        nb = nb + (*str - '0') / i;
        i *= 10.0;
        str++;
    }
	if(*str)
		return (0);
	return (nb);
}

double ft_atod(char *str)
{
	double	nb;
	double	sig;

	sig = 1;
	nb = 0;
	if (*str == '-')
	{
		sig = sig * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if(*str == '.')
	{
		str++;
		nb = ft_decim(str, nb);
	}
	else
		return(0.0);

	return (nb * sig);
}

int check_max(char *s, int flag)
{
	if(flag == 1)
	{
		if(ft_atod(s) < -2.0 || ft_atod(s) > 2.0)//mal flag 1
			return (1);
	}
	else if(flag == 2)
	{
		if(ft_atod(s) < -1.50 || ft_atod(s) > 1.50)//mal flag 2
			return (1);
	}
	return (0);
}

int	look_error(char *argv, int flag)
{
	char	*regex;
	int		i;

	i = 0;
	if (check_max(argv, flag) == 1)
	{
		write(1, "Error! Number exceeds the Julia supported numbers\n\
		./fractol julia <[-2, 2]> <[-1.5, 1.5]>\n", 86);
		return (1);
	}
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
			return (1);
		argv++;
	}
	return (0);
}
