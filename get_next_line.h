/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:58:52 by juhallyn          #+#    #+#             */
/*   Updated: 2017/07/22 03:11:31 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft.h"
# include <fcntl.h>
# define BUFF_SIZE 40

int		get_next_line(const int fd, char **line);

#endif
