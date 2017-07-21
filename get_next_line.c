/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:57:51 by juhallyn          #+#    #+#             */
/*   Updated: 2017/07/21 16:49:59 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>
	//printf("%s",  str);

int		init_line(char *str, char *chptr, char **line, int ret)
{
	*line = ft_strsub(str, 0, chptr - str);
	ft_putendl(*line);
	str = chptr;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	char			*chptr;
	char			*memory;

	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		memory = str;
		str = ft_strjoin(str, buff);
		chptr = ft_strchr(str, '\n');
		if (chptr)
			return (init_line(str, chptr, line, ret));
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char		*line;
	const int	fd = open(argv[1], O_RDONLY);

	get_next_line(fd, &line);
	get_next_line(fd, &line);
	return (0);
}
