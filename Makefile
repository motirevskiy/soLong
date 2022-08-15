# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 14:44:41 by cgretche          #+#    #+#              #
#    Updated: 2022/01/14 18:21:11 by cgretche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

SRCS_FILES	= 	so_long.c \
			save_map.c \
			main.c \
			gnl.c \
			errors.c \
			count_map.c \
			ft_draw_map.c \
			ft_key_hook.c \
			ft_putnbr_fd.c \
			check_symbols.c \
			check_area.c

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

INCLUDE		=	-I.

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

# LIB = ./libft/libft.a

.PHONY:		all libft clean fclean re

all:		$(NAME)

libft:
	@$(MAKE) -C $(dir $(LIB))

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJS) 
			$(CC) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(INCLUDE) -o $(NAME) $(OBJS)
			@echo "\033[36;1m\n< Compiled so_long >\n\033[0m"
			@echo "\033[36;1m\n< Done >\n\033[0m"

clean:
			@$(RM) $(OBJS)
# @$(MAKE) -C $(dir $(LIB)) clean
			@echo "\033[32;1m\n< Cleaning succeed >\n\033[0m"

fclean:		clean
# @$(MAKE) -C $(dir $(LIB)) fclean
			@$(RM) $(NAME)
			@echo "\033[32;1m\n< All created files were deleted >\n\033[0m"

re:			fclean all
			@echo "\033[35;1m\n< Remake done >\n\033[0m"