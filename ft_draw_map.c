/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:59:48 by cgretche          #+#    #+#             */
/*   Updated: 2022/01/14 19:14:08 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_select_image(void **img, char ch)
{
	if (ch == '0')
		return (img[1]);
	if (ch == '1')
		return (img[2]);
	if (ch == 'C')
		return (img[3]);
	if (ch == 'E')
		return (img[4]);
	if (ch == 'V')
		return (img[5]);
	else
		return (img[0]);
}

void	ft_draw_map(void *mlx_ptr, void	*win_ptr, void	**img, char **map)
{
	int		i;
	int		x;
	int		y;
	char	*str;
	void	*pic;

	i = 0;
	y = 0;
	while (map[i])
	{
		str = map[i];
		if (str == NULL)
			break ;
		x = 0;
		while (str[x])
		{
			pic = ft_select_image(img, str[x]);
			mlx_put_image_to_window(mlx_ptr, win_ptr, pic, x * 96, y * 128);
			x++;
		}
		y++;
		i++;
	}
}
