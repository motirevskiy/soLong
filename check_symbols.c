/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:17:58 by cgretche          #+#    #+#             */
/*   Updated: 2022/01/14 20:47:02 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_symbols_c(int c, int len, char **map)
{
	int	l;

	l = 0;
	while (l < len)
	{
		if (map[c][l] == 'C')
			return (1);
		else
			l++;
	}
	return (0);
}

int	check_symbols_e(int c, int len, char **map)
{
	int	l;

	l = 0;
	while (l < len)
	{
		if (map[c][l] == 'E')
			return (1);
		else
			l++;
	}
	return (0);
}

int	check_symbols_2(int c, int len, char **map, int *PEC)
{
	int	l;

	l = 0;
	while (l < len)
	{
		if (PEC[1] != 1)
			PEC[1] = check_symbols_e(c, len, map);
		if (PEC[2] != 1)
			PEC[2] = check_symbols_c(c, len, map);
		if (map[c][l] == 'P' && PEC[0] != 1)
		{
			PEC[0] = 1;
			l++;
		}
		else if (map[c][l] == 'P' && PEC[0] == 1)
			errors(3);
		else if (map[c][l] != 'C' && map[c][l] != 'E' && map[c][l]
		!= 'V' && map[c][l]
		!= 'P' && map[c][l] != '1' && map[c][l] != '0' && map[c][l] != '\n')
			errors(2);
		else
			l++;
	}
	return (PEC[0] * PEC[1] * PEC [2]);
}

int	check_symbols(int count, int len, char **map)
{
	int	pec[3];
	int	l;
	int	c;

	c = 0;
	l = 0;
	while (c < 3)
	{
		pec[c] = 0;
		c++;
	}
	while (l < count)
	{
		c = check_symbols_2(l, len, map, pec);
		l++;
	}
	if (c == 0)
		errors(2);
	return (0);
}
