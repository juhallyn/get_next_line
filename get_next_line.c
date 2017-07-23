/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:29:21 by juhallyn          #+#    #+#             */
/*   Updated: 2017/07/23 15:09:26 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		init_line(char **str, char **line, char *chptr)
{
	char *tmp;

	if (!*str || !str)
		return (0);
	tmp = *str;
	*line = ft_strsub(*str, 0, chptr - *str);
	*str = ft_strdup(chptr + 1);
	ft_strdel(&tmp);
	return (1);
}

static char		*ft_chr2(const char *s, int tf, char **chptr)
{
	char	*sptr;
	int		i;
	char	c;

	i = 0;
	if (!s)
		return (NULL);
	sptr = (char *)s;
	c = (char)tf;
	if (*sptr == c)
	{
		*chptr = sptr;
		return (sptr);
	}
	while (sptr[i++])
	{
		if (sptr[i] == c)
		{
			*chptr = &sptr[i];
			return (&sptr[i]);
		}
	}
	*chptr = NULL;
	return (NULL);
}

static int		check_and_dup(char **str, char **line)
{
	if (ft_strlen(*str) == 0 || !*str)
	{
		ft_strdel(str);
		return (0);
	}
	*line = ft_strdup(*str);
	ft_strdel(str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*str = NULL;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*chptr;
	char			*memory;

	chptr = NULL;
	memory = NULL;
	if (fd == -1)
		return (-1);
	while (!(ft_chr2(str, '\n', &chptr)) && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		memory = str;
		str = ft_strjoin(str, buff);
		ft_strdel(&memory);
	}
	if (ret == -1)
		return (-1);
	else if (!chptr && str)
		return (check_and_dup(&str, line));
	return (init_line(&str, line, chptr));
	return (0);
}
