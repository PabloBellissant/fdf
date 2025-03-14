/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:45:09 by pabellis          #+#    #+#             */
/*   Updated: 2024/12/16 04:04:04 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

# define BUFFER_SIZE 2048

static void	clear_tab(char *tab, size_t size, int t);
static ssize_t	find_newline(char *str, int replace_by_endline);
static ssize_t	ft_read(int fd, char *bu, char *output, ssize_t i);
static size_t	secure_strlen(char *str);
static char		*secure_strjoin(char *s1, char *s2);

char	*get_next_line(int fd)
{
	static char		bu[BUFFER_SIZE + 1];
	char			*output;
	ssize_t			i;
	ssize_t			j;

	i = BUFFER_SIZE;
	output = NULL;
	while (i >= BUFFER_SIZE)
	{
		i = ft_read(fd, bu, output, i);
		if (i == -3)
			return (output);
		j = find_newline(bu, 1);
        if (i == -2)
          output = NULL;
        else
			output = secure_strjoin(output, bu);
		if (!output || i == -2)
			return (NULL);
		if (j != -1)
			ft_memmove(bu, bu + j + 1, secure_strlen(bu + j + 1) + 1);
		else
			bu[0] = 0;
		clear_tab(bu + secure_strlen(bu), BUFFER_SIZE - secure_strlen(bu), 1);
	}
	if (i == 0)
		output = secure_strjoin(output, "\n");
	return (output);
}

static ssize_t	ft_read(int fd, char *bu, char *output, ssize_t i)
{
	size_t	bu_len;
	size_t	output_len;

	bu_len = secure_strlen(bu);
	if (find_newline(bu, 0) == -1 && bu_len < 1)
	{
		if (read(fd, bu + bu_len, BUFFER_SIZE) == -1)
		{
			free(output);
			clear_tab(bu, BUFFER_SIZE, 1);
			return (-2);
		}
		i = secure_strlen(bu);
		output_len = secure_strlen(output);
		if (i == 0 && output_len != 0)
			i = -1;
		if (i == 0 && output_len == 0)
			return (-3);
	}
	if (find_newline(bu, 0) != -1)
		return (0);
	return (i);
}

static ssize_t	find_newline(char *str, int replace_by_endline)
{
	ssize_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (replace_by_endline == 1)
				str[i] = 0;
			return (i);
		}
		++i;
	}
	return (-1);
}

static void	clear_tab(char *tab, size_t size, int t)
{
	size_t	i;

	if (t != 1)
		return ;
	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		++i;
	}
}

static size_t	secure_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	return (i);
}

static char	*secure_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*newstr;

	s1len = secure_strlen(s1);
	s2len = secure_strlen(s2);
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
