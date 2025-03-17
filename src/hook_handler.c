/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:00:39 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 23:00:41 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include "mlx.h"
#include "fdf.h"

void	hook_handler(t_data *data)
{
	void	*win;

	win = data->win;
	mlx_hook(win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(win, ButtonPress, ButtonPressMask, mouse_press, data);
	mlx_hook(win, ButtonRelease, ButtonReleaseMask, mouse_release, data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
}
