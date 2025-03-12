/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:38:00 by pabellis          #+#    #+#             */
/*   Updated: 2025/02/12 03:38:03 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	vector_init(t_vector *vector, size_t element_size)
{
	vector->element_size = element_size;
	vector->max_elements = 50;
	vector->num_elements = 0;
	vector->data = malloc(element_size * 50);
	if (vector->data == NULL)
		return (-1);
	return (0);
}
