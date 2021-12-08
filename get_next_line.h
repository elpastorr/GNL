/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:03:20 by elpastor          #+#    #+#             */
/*   Updated: 2021/12/08 15:26:30 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*get_tmp(int i, char *buf, char *tmp, int fd);
char	*get_str(char **tmp);
int		get_bn(const char *s);
void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_substrf(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif
