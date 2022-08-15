/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:43:21 by cgretche          #+#    #+#             */
/*   Updated: 2022/01/14 20:52:20 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct so_long
{
	char	**map;
	void	**img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_struct;

void	errors(int e);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*gnl(int fd);
void	count_map(int *count, int *len, char **argv);
int		check_format(char *argv);
char	**ft_save_map(int count, char *argv);
int		check_symbols_c(int c, int len, char **map);
int		check_symbols_e(int c, int len, char **map);
int		check_symbols_2(int c, int len, char **map, int *PEC);
int		check_symbols(int count, int len, char **map);
int		check_area(int count, int len, char **map);
void	**ft_init_image(void *mlx_ptr);
void	ft_draw_map(void *mlx_ptr, void	*win_ptr, void	**img, char **map);
void	*ft_select_image(void **img, char ch);
int		quit(void);
int		ft_key_hook(int key, t_struct *var);
void	ft_putnbr_fd(int n, int fd);
int		ft_walker(t_struct *var, int key);
void	ft_find_player(char **map, int *x, int *y);
void	ft_walker_add(int *x, int	*y, int key);
int		ft_check_c(char **map);
void	ft_putchar_fd(char c, int fd);

#endif