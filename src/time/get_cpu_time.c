/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_proc_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabellis <mail@bellissantpablo.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:36:47 by pabellis          #+#    #+#             */
/*   Updated: 2025/03/06 03:36:48 by pabellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

ssize_t	get_cpu_time(void)
{
	int		fd;
	char	tab[200];
	size_t	i;

	fd = open("/proc/self/sched", O_RDONLY);
	if (fd == -1 || read(fd, tab, 200) == -1)
	{
		close(fd);
		return (-1);
	}
	i = 140;
	while (ft_isdigit(tab[i]) == 0)
		++i;
	if (close(fd) == -1)
		return (-1);
	return (ft_atoi(tab + i));
}
