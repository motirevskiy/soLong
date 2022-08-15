/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:14:26 by cgretche          #+#    #+#             */
/*   Updated: 2021/12/30 19:33:50 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_area(int count, int len, char **map)
{
	int	l;
	int	c;

	l = 0;
	c = 0;
	while (l < len)
	{
		if (map[0][l] != '1' || map[count - 1][l] != '1')
			errors(1);
		l++;
	}
	while (c < count)
	{
		if (map[c][0] != '1' || map[c][len - 1] != '1')
			errors(1);
		c++;
	}
	return (0);
}
