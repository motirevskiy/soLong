/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:16:33 by cgretche          #+#    #+#             */
/*   Updated: 2022/01/14 20:44:33 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_save_map(int count, char *argv)
{
	int		i;
	int		fd;
	char	**map;

	map = malloc(sizeof(char *) * count + 1);
	if (!map)
		exit(0);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (i < count)
	{
		map[i] = gnl(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
