/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_degrees.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:03:57 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/11 22:04:04 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _180_DIV_PI 57.295779513f

/**
 * @brief convert a radian to a degrees.
 * @param degrees The degree to convert.
 * @return the radiant, in float.
 * @author Bellissant Pablo
 */
float	to_degrees(float radian)
{
	return (radian * _180_DIV_PI);
}
