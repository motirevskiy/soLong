/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:13:43 by cgretche          #+#    #+#             */
/*   Updated: 2021/12/30 19:47:00 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map(int *count, int *len, char **argv)
{
	int		fd;
	char	*str;

	*len = 0;
	*count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		errors(4);
	while (1)
	{
		str = gnl(fd);
		if (str[0] == '\0')
		{
			free(str);
			break ;
		}
		if (*len == 0)
			*len = ft_strlen(str);
		if (*len != (int)ft_strlen(str))
			errors(1);
		free(str);
		(*count)++;
	}
	close(fd);
}
