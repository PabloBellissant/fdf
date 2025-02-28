/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:07:37 by pabellis          #+#    #+#             */
/*   Updated: 2025/01/23 03:39:49 by pabellis         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief erases the data in the n bytes of the memory starting at the 
 * location pointed to by s, by writing zeros (bytes containing '\0') 
 * to that area.
 * @param s memory area
 * @param n number of bytes erase.
 * @return a pointer to the memory area s..
 * @author Bellissant Pablo
 */
void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, 0, n));
}
