/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:58:51 by elpastor          #+#    #+#             */
/*   Updated: 2021/12/07 19:00:19 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*get_str(char *tmp)
{
	char	*str;

	if (get_bn(tmp) != -1)
	{
		str = ft_substr(tmp, 0, (get_bn(tmp) + 1));
		tmp = ft_substrf(tmp, (get_bn(tmp) + 1), ft_strlen(tmp));
	}
	else
	{
		str = ft_substr(tmp, 0, ft_strlen(tmp));
		tmp = ft_substrf(tmp, 0, 0);
	}
	return (str);
}

int	check_error(int fd, char **buf, char **tmp)
{
	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
		return (0);
	*buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!(*buf))
		return (0);
	if (!(*tmp))
	{
		*tmp = (char *)malloc(1);
		if (!(*tmp))
			return (0);
		*tmp[0] = 0;
	}
	return (read(fd, *buf, BUFFER_SIZE));
}


char	*get_next_line(int fd)
{
	char		*buf;
	static char	*tmp;
	int			i;

	i = check_error(fd, &buf, &tmp);
	if (i < 1 && !ft_strlen(tmp))
	{
		free(buf);
		return (NULL);
	}
	if (i > 0)
		buf[i] = 0;
	while (i > 0 && get_bn(tmp) == -1)
	{
		buf[i] = 0;
		tmp = ft_strjoin(tmp, buf);
		ft_bzero(buf, BUFFER_SIZE);
		if (get_bn(tmp) == -1)
			i = read(fd, buf, BUFFER_SIZE);
	}
	if (i > 0)
		tmp = ft_strjoin(tmp, buf);
	free(buf);
	return (get_str(tmp));
}


/*
char	*get_next_line(int fd)
{
	char		*buf;
	static char	*tmp;
	char		*str;
	int			i;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > 1024)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!tmp)
	{
		tmp = (char *)malloc(1);
		if (!tmp)
			return (NULL);
		tmp[0] = 0;
	}
	i = read(fd, buf, BUFFER_SIZE);
	if (i < 1 && !ft_strlen(tmp))
	{
		free(buf);
		return (NULL);
	}
	if (i > 0)
		buf[i] = 0;
	while (i > 0 && get_bn(tmp) == -1)
	{
		buf[i] = 0;
		tmp = ft_strjoin(tmp, buf);
		ft_bzero(buf, BUFFER_SIZE);
		if (get_bn(tmp) == -1)
			i = read(fd, buf, BUFFER_SIZE);
	}
	if (i > 0)
		tmp = ft_strjoin(tmp, buf);
	if (get_bn(tmp) != -1)
	{
		str = ft_substr(tmp, 0, (get_bn(tmp) + 1));
		tmp = ft_substrf(tmp, (get_bn(tmp) + 1), ft_strlen(tmp));
	}
	else
	{
		str = ft_substr(tmp, 0, ft_strlen(tmp));
		tmp = ft_substrf(tmp, 0, 0);
	}
	free(buf);
	return (str);
}*/
