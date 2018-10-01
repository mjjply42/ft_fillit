/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:45:26 by majones           #+#    #+#             */
/*   Updated: 2018/08/11 18:01:51 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	puttet(char **tet)
{
	int i;

	i = 0;
	while (tet[i] != NULL)
	{
		ft_putstr(tet[i]);
		ft_putchar('\n');
		i++;
	}
}

static int	square_size(int a)
{
	int size;

	size = 2;
	while (size * size < a)
		size++;
	return (size);
}

void		free_tet(char **tet, int tet_size)
{
	int i;

	i = 0;
	while (i < tet_size)
	{
		ft_strdel(&tet[i]);
		i++;
	}
	ft_strdel(tet);
}

char		read_open(char *argv, char *buff)
{
	int fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	read(fd, buff, BUFF_SIZE);
	return (*buff);
}

int			main(int argc, char **argv)
{
	t_tetrimino *start;
	char		**tet;
	char		buff[BUFF_SIZE + 1];

	if (argc != 2)
	{
		ft_putstr("usage: fillit [map_file]\n");
		return (0);
	}
	start = NULL;
	tet = NULL;
	read_open(argv[1], buff);
	if ((tet_count = (char_check(buff))) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	tet = build_tet(tet_count, buff);
	start = splittet(tet);
	free_tet(tet, tet_count + 1);
	puttet(solve(start, square_size(tet_count * 4), NULL));
	return (0);
}
