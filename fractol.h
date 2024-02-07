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
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-mac/mlx.h"
# include "fractol.h"

// * DEFINES
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define P_ORANGE 0xE9BE9F
# define P_BLUE 0xA1BCC7
# define P_GREEN 0x9BC1B2
# define BLUE1 0x00065D
# define BLUE2 0x020A73
# define BLUE3 0x052296
# define BLUE4 0x1659BF
# define BLUE5 0x51A3E4
# define BLUE6 0xE0F5F1
# define SIZE_X 800
# define SIZE_Y 800
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49

// * STRUCTS
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int		bits_px;
	int		endian;
	int		line_length;
}	t_img;

typedef struct s_fractol
{
	char			*name;
	void			*mlx_conn;
	void			*mlx_window;
	int				nb_iterations;
	struct s_img	img;
	float			zoom;
	double			move_x;
	double			move_y;
	double			julia1;
	double			julia2;
	int				i_color;
}	t_fractol;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

// * UTILS
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atod(char *str);

// * FUNCTIONS
void	fractol_init(t_fractol *fractol);
void	render(t_fractol *fractol);
void	fractol_events(t_fractol *fractol);
int		look_error(char *argv, int flag);

#endif