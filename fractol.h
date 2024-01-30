/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teojimenez <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:23:01 by teojimene         #+#    #+#             */
/*   Updated: 2024/01/30 18:23:01 by teojimene        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "fractol.h"
# include "minilibx-mac/mlx.h"

# define SIZE_X
# define SIZE_Y
# define NB_ITERATIONS

typedef struct s_img
{

}	t_img;

typedef struct s_fractol
{
	char	*name;
	struct	s_img *img;
}t_fractol;

#endif