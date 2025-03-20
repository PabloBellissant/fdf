/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:25:05 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/17 08:25:06 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	normalize_value(int *value, int min, int max)
{
	if (*value >= max)
		*value = min;
	else if (*value < min)
		*value += max;
}

void	normalize_float_value(float *value, float max)
{
	if (*value >= max)
		*value = 0;
	else if (*value < 0)
		*value += max;
}
