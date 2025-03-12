/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_rad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:38:04 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 23:38:07 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PI_DIV_180 0.017453293f

/**
 * @brief convert a degree to a radian
 * @param degrees The degree to convert.
 * @return the radiant, in float.
 * @author Bellissant Pablo
 */
float	to_rad(float degrees)
{
	return (degrees * PI_DIV_180);
}
