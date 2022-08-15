/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:23:32 by cgretche          #+#    #+#             */
/*   Updated: 2022/01/14 20:52:09 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *argv)
{
	int		c;
	int		b;
	char	*form;

	form = ".ber";
	b = 4;
	c = ft_strlen(argv);
	while (b != 0)
	{
		if (argv[c] != form[b])
			errors(5);
		c--;
		b--;
	}
	return (0);
}
