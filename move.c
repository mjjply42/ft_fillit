/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:45:00 by majones           #+#    #+#             */
/*   Updated: 2018/08/11 17:31:35 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**arrange_up(int i_min, char **tet)
{
	int i;

	i = 0;
	while (i + i_min < 4)
	{
		tet[i] = tet[i + i_min];
		i++;
	}
	while (i < 4 && i_min > 0)
	{
		tet[i] = "....\0";
		i++;
	}
	return (tet);
}

static char		**arrange_left(int j_min, char **tet)
{
	int tmp;
	int i;
	int j;

	tmp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (tet[i][j + j_min] != '\0')
		{
			tet[i][j] = tet[i][j + j_min];
			j++;
		}
		tmp = j_min;
		while (tmp > 0 && tmp > 0)
		{
			tet[i][4 - tmp] = '.';
			tmp--;
		}
		j = 0;
		i++;
	}
	return (tet);
}

static int		get_y_min(char **tet)
{
	int x;
	int y;
	int y_min;

	x = 0;
	y = 0;
	y_min = 0;
	while (x < 4)
	{
		while (tet[x][y] != '#' && tet[x][y] != '\0')
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
		x++;
	}
	return (y_min);
}

static int		get_x_min(char **tet)
{
	int x;
	int y;
	int x_min;

	x = 0;
	y = 0;
	x_min = 4;
	while (x < 4)
	{
		while (tet[x][y] != '#' && tet[x][y] != '\0')
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
		x++;
	}
	return (x_min);
}

t_tetrimino		*arrange(t_tetrimino *start)
{
	t_tetrimino *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->tetrimino = arrange_left(get_x_min(tmp->tetrimino),\
				tmp->tetrimino);
		tmp->tetrimino = arrange_up(get_y_min(tmp->tetrimino), tmp->tetrimino);
		tmp = tmp->next;
	}
	return (start);
}
