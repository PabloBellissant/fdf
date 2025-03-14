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

static int	set_line_on_vector(char *line, t_vector *map, size_t line_num);

int	open_map(t_data *data, int fd)
{
	char		*line;
	size_t		line_num;
	size_t		line_len;
	size_t		actual_len;

	if (vector_init(&data->map, sizeof(t_vector)) == -1)
		return (0);
	line_num = 0;
	line_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		actual_len = set_line_on_vector(line, &data->map, line_num);
		if (actual_len > line_len)
			line_len = actual_len;
		free(line);
		line = get_next_line(fd);
		++line_num;
	}
	data->map_data.size_x = line_len;
	data->map_data.size_y = line_num;
	return (0);
}

char	*get_color_hexa(char *str)
{
	if (!str)
		return (NULL);
	while (*str && *str != ' ' && *str != ',')
		++str;
	if (*str != ',')
		return (NULL);
	++str;
	if (*str == '0' && *(str + 1) == 'x')
		return (str + 2);
	return (NULL);
}

static int	set_line_on_vector(char *line, t_vector *map, size_t line_num)
{
	t_vector	*vec;
	t_point		point;
	char		**splited;
	size_t		i;

	splited = ft_split(line, ' ');
	vec = malloc(sizeof(t_vector));
	if (vector_init(vec, sizeof(t_point)) == -1)
	{
		free_tab(splited);
		return (0);
	}
	i = 0;
	while (splited[i])
	{
		if (*(splited[i]) != '\n')
		{
			point.x = i;
			point.y = line_num;
			point.z = ft_atoi(splited[i]);
			point.color.color = convert_hexa(get_color_hexa(splited[i] + 1));
			vector_add(vec, &point);
		}
		++i;
	}
	vector_add(map, vec);
	return (i);
}
