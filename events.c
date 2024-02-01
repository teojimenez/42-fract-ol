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

int fractol_events(int keycode, t_fractol *fractol)
{
    printf("%d", keycode);
    fractol->nb_iterations++;
    return (0);
}