/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:55:55 by majones           #+#    #+#             */
/*   Updated: 2018/08/11 18:00:36 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*newtetri(char **tetrimino, int num)
{
	t_tetrimino *new;

	new = NULL;
	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (new == NULL)
		return (NULL);
	new->tetrimino = tetrimino;
	new->letter = 'A' + num;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char			**create_map(char **tet, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	tet = ft_memalloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		tet[i] = ft_memalloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			tet[j][i++] = '.';
		}
		tet[j][i] = '\0';
		i = 0;
		j++;
	}
	tet[j] = NULL;
	return (tet);
}

t_tetrimino		*splittet(char **tet)
{
	int			i;
	t_tetrimino	*start;
	t_tetrimino	*ptr;

	i = 1;
	start = NULL;
	ptr = NULL;
	start = newtetri(ft_strsplit(tet[0], '\n'), 0);
	ptr = start;
	while (i < tet_count)
	{
		ptr->next = newtetri(ft_strsplit(tet[i], '\n'), i);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	return (start);
}

char		**build_tet(int length, char *buff)
{
	int		i;
	int		j;
	int		k;
	char	**tetriminos;

	k = 0;
	tetriminos = (char**)ft_memalloc(sizeof(char*) * length + 1);
	i = 0;
	while (i < length)
	{
		j = 0;
		tetriminos[i] = (char*)ft_memalloc(sizeof(char) * 20 + 1);
		while (j < 20)
		{
			tetriminos[i][j] = buff[k];
			k++;
			j++;
		}
		tetriminos[i][j] = '\0';
		i++;
	}
	return (tetriminos);
}
