/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:11:54 by cgretche          #+#    #+#             */
/*   Updated: 2022/01/14 20:47:37 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(int e)
{
	if (e == 1)
	{
		write(1, "map error\n", 11);
		exit (0);
	}
	else if (e == 2)
	{
		write(1, "symbols error\n", 15);
		exit (0);
	}
	else if (e == 3)
	{
		write(1, "more than one character\n", 25);
		exit (0);
	}
	else if (e == 4)
	{
		write(1, "open map error\n", 16);
		exit (0);
	}
	else if (e == 5)
	{
		write(1, "invalid format map\n", 20);
		exit (0);
	}
}
