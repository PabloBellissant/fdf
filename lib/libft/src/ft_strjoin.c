/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:23:57 by pabellis          #+#    #+#             */
/*   Updated: 2025/01/23 03:40:10 by pabellis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief Concatenate s1 and s2
 * @param s1 The prefix string.
 * @param s2 The suffic string.
 * @return The new string, NULL if the allocaton fails.
 * @note the returned string must be freed to avoid memory leaks.
 * @warning s1 and s2 must not be NULL.
 * @author Bellissant Pablo
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*newstr;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	newstr = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!newstr)
		return (NULL);
	while (i < s1len)
	{
		newstr[i] = s1[i];
		i += 1;
	}
	while (i < s1len + s2len)
	{
		newstr[i] = s2[i - s1len];
		i += 1;
	}
	newstr[i] = 0;
	return (newstr);
}
