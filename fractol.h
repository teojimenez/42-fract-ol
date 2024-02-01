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
# include "minilibx-mac/mlx.h"
# include "fractol.h"

#include <stdio.h> //delete

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00

//var
# define SIZE_X 800
# define SIZE_Y 800
# define NB_ITERATIONS 2000

typedef struct s_img
{
	void *img_ptr;
	char *img_pixel_ptr;
	int bits_per_pixel;
	int endian;
	int line_length;
}	t_img;

typedef struct s_fractol
{
	char	*name;
	void *mlx_conn;
	void *mlx_window;
	int		nb_iterations;
	struct	s_img img;
}t_fractol;

typedef struct s_complex
{
	double x;
	double y;
} t_complex;

// * UTILS
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// * FUNCTIONS
void	fractol_init(t_fractol *fractol);
void	render(t_fractol *fractol);
int		fractol_events(int keycode, t_fractol *fractol);

#endif