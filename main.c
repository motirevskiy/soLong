/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:50:10 by cgretche          #+#    #+#             */
/*   Updated: 2022/01/14 20:50:12 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit(void)
{
	exit(0);
	return (0);
}

void	**ft_init_image(void *mlx_ptr)
{
	int		i;
	int		j;
	void	**img;

	i = 0;
	j = 0;
	img = (void **)malloc(sizeof(void *) * 6);
	img[0] = mlx_xpm_file_to_image(mlx_ptr, "img/player.xpm", &i, &j);
	img[1] = mlx_xpm_file_to_image(mlx_ptr, "img/sand.xpm", &i, &j);
	img[2] = mlx_xpm_file_to_image(mlx_ptr, "img/wall.xpm", &i, &j);
	img[3] = mlx_xpm_file_to_image(mlx_ptr, "img/item.xpm", &i, &j);
	img[4] = mlx_xpm_file_to_image(mlx_ptr, "img/exit.xpm", &i, &j);
	img[5] = mlx_xpm_file_to_image(mlx_ptr, "img/enemy.xpm", &i, &j);
	return (img);
}

int	main(int argc, char **argv)
{
	int			count;
	int			len;
	t_struct	var;

	if (argc != 2)
		errors(4);
	count_map(&count, &len, argv);
	check_format(argv[1]);
	var.map = ft_save_map(count, argv[1]);
	check_symbols(count, len, var.map);
	check_area(count, len, var.map);
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, len * 96, count * 128, "So_long");
	var.img = ft_init_image(var.mlx_ptr);
	ft_draw_map(var.mlx_ptr, var.win_ptr, var.img, var.map);
	mlx_key_hook(var.win_ptr, ft_key_hook, &var);
	mlx_hook(var.win_ptr, 17, 0L, &quit, &var);
	mlx_loop(var.mlx_ptr);
	return (0);
}
