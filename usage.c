/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 13:56:44 by majones           #+#    #+#             */
/*   Updated: 2018/08/12 14:06:30 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fillit [File containing between 2 and 12 Tetriminos]");
	ft_putendl("        Note : If file contains more than 12 Tetriminos,");
	ft_putendl("               The program will run slowly.");
}
