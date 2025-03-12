/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:25:14 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/02 19:25:16 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"

static int	set_line_on_vector(char *line, t_vector *vec, size_t line_num);

int	open_map(t_data *data, int fd)
{
	t_vector	*map;
	char		*line;
	size_t		line_num;
	size_t		line_len;

	map = malloc(sizeof(t_vector) + 1);
	if (map == NULL)
		return (-1);
	if (vector_init(map, sizeof(t_point)) == -1)
	{
		free(map);
		return (0);
	}
	line_num = 0;
	line_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_len = set_line_on_vector(line, map, line_num);
		free(line);
		line = get_next_line(fd);
		++line_num;
	}
	data->map = map;
	data->map_data.size_x = line_len;
	data->map_data.size_y = line_num;
	return (0);
}

static int	set_line_on_vector(char *line, t_vector *vec, size_t line_num)
{
	t_point	*point;
	char	**splited;
	size_t	i;

	splited = ft_split(line, ' ');
	i = 0;
	while (splited[i])
	{
		point = malloc(sizeof(t_point));
		if (point == NULL)
		{
			free_tab(splited);
			//free full vector
			return (-1);
		}
		point->x = i;
		point->y = line_num;
		point->z = ft_atoi(splited[i]);
		vector_add(vec, point);
		++i;
	}
	return (i);
}
