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

static ssize_t	set_line_on_vector(char *line, t_vector *map, size_t line_num);
static int		fill_map_vector(char *line, t_vector *vec, size_t line_num);
static char		*get_color_hexa(char *str);

int	open_map(t_data *data, int fd)
{
	char		*line;
	ssize_t		line_num;
	ssize_t		line_len;
	ssize_t		actual_len;

	if (vector_init(&data->map, sizeof(t_vector)) == -1)
		return (-1);
	line_num = 0;
	line_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		actual_len = set_line_on_vector(line, &data->map, line_num);
		free(line);
		if (actual_len == -1)
			return (-1);
		if (actual_len > line_len)
			line_len = actual_len;
		line = get_next_line(fd);
		++line_num;
	}
	data->map_data.size_x = line_len;
	data->map_data.size_y = line_num;
	data->map_data.z_multiple = 1.0f;
	return (0);
}

static char	*get_color_hexa(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != ',')
		++i;
	if (str[i] != ',')
		return (NULL);
	++i;
	if (str[i] == '0' && str[i + 1] == 'x')
		return (str + i + 2);
	return (NULL);
}

static ssize_t	set_line_on_vector(char *line, t_vector *map, size_t line_num)
{
	t_vector	vec;
	ssize_t		i;

	if (vector_init(&vec, sizeof(t_point)) == -1)
		return (-1);
	i = fill_map_vector(line, &vec, line_num);
	if (vector_add(map, &vec) == -1)
	{
		free_vector(&vec);
		return (-1);
	}
	return (i);
}

static int	fill_map_vector(char *line, t_vector *vec, size_t line_num)
{
	size_t	i;
	t_point	point;
	char	*new_line;

	new_line = ft_strtok(line, " ");
	point.is_pressed = false;
	point.y = line_num;
	i = 0;
	while (new_line != NULL)
	{
		point.x = i;
		point.z = ft_atoi(new_line);
		point.color.c = convert_hexa(get_color_hexa(new_line + 1));
		if (vector_add(vec, &point) == -1)
			return (-1);
		new_line = ft_strtok(NULL, " ");
		++i;
	}
	return (i);
}
