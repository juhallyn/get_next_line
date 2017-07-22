/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:14:58 by juhallyn          #+#    #+#             */
/*   Updated: 2017/07/22 16:15:13 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int		main(int argc, char **argv)
{
	char		*line;
	const int	fd = open(argv[1], O_RDONLY);

	line = NULL;
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
