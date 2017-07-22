/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:29:21 by juhallyn          #+#    #+#             */
/*   Updated: 2017/07/18 17:39:23 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static int		init_line(char **str, char **line, char *chptr, int ret)
{
	char *tmp;

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

int				get_next_line(int const fd, char **line)
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
	else if (str && !chptr && *buff != '\0')
	{
		if (ft_strlen(str) == 0)
		{
			ft_strdel(&str);
			return (0);
		}
		*line = ft_strdup(str);
		ft_strdel(&str);
		return (1);
	}
	if (str && ret != 0)
		return (init_line(&str, line, chptr, ret));
	return (0);
}

int		main(int argc, char **argv)
{
	char		*line;
	const int	fd = open(argv[1], O_RDONLY);

	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
		// sleep(1);
	}
	return (0);
}
