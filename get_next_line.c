/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:58:51 by elpastor          #+#    #+#             */
/*   Updated: 2021/12/06 18:19:22 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*tmp;
	char		*str;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!tmp)
	{
		tmp = malloc(1);
		if (!tmp)
			return (NULL);
		tmp[0] = 0;
	}
	i = read(fd, buf, BUFFER_SIZE);
	if (i >= 0)
		buf[i] = '\0';
	while (i > 0 && get_bn(buf) == -1)
	{
		buf[i] = '\0';
		tmp = ft_strjoin(tmp, buf);
		i = read(fd, buf, BUFFER_SIZE);
	}
	tmp = ft_strjoin(tmp, buf);
	str = ft_substr(tmp, 0, (get_bn(tmp) + 1));
	tmp = ft_substrf(tmp, (get_bn(tmp) + 1), ft_strlen(tmp));
	free(buf);
	return (str);
}
