/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 02:19:22 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/13 02:19:24 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int	convert_hexa(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (!str)
		return (WHITE);
	while (ft_isalnum(str[i]))
	{
		result *= 16;
		if (ft_isdigit(str[i]))
			result += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			result += str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			result += str[i] - 'a' + 10;
		else
			return (WHITE);
		i++;
	}
	return (result);
}
