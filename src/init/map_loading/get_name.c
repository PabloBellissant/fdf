/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simple_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:33:47 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/14 03:33:48 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*get_name(char *str)
{
	char	*new;
	char	*to_clear;
	char	*output;

	if (!str)
		return (NULL);
	new = ft_strdup(str);
	if (!new)
		return (NULL);
	to_clear = new;
	if (ft_strrchr(new, '/') != NULL)
		new = ft_strrchr(new, '/') + 1;
	if (ft_strrchr(new, '.') != NULL)
		*ft_strrchr(new, '.') = 0;
	if (ft_strlen(new) > 15)
	{
		new[12] = '.';
		new[13] = '.';
		new[14] = '.';
		new[15] = 0;
	}
	output = ft_strdup(new);
	free(to_clear);
	return (output);
}
