/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 07:48:40 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 07:48:42 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_fabs(float val)
{
	if (val < 0)
		return (-val);
	return (val);
}
