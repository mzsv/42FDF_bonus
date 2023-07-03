# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 20:26:07 by amenses-          #+#    #+#              #
#    Updated: 2023/07/03 18:15:38 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g
IFLAGS			=	-L ./mlx -lmlx -Ilmlx -lXext -lX11 -lm

LIBFT			=	libft/libft.a

SRCS			=	src/fdf_color.c src/fdf_event_hooks.c src/fdf_init.c src/fdf_main.c \
					src/fdf_map.c src/fdf_math.c src/fdf_matrices.c src/fdf_points.c \
					src/fdf_points_utils.c src/fdf_projections.c src/fdf_rendering.c \
					src/fdf_rendering_modes.c src/fdf_terminator.c src/fdf_utils.c \
					libft/get_next_line.c libft/get_next_line_utils.c \

SRCS_BONUS		=	src_bonus/fdf_color_bonus.c src_bonus/fdf_event_hooks_bonus.c \
					src_bonus/fdf_init_bonus.c src_bonus/fdf_main_bonus.c src_bonus/fdf_map_bonus.c \
					src_bonus/fdf_math_bonus.c src_bonus/fdf_matrices_bonus.c src_bonus/fdf_points_bonus.c \
					src_bonus/fdf_points_utils_bonus.c src_bonus/fdf_projections_bonus.c \
					src_bonus/fdf_rendering_bonus.c src_bonus/fdf_rendering_modes_bonus.c \
					src_bonus/fdf_terminator_bonus.c src_bonus/fdf_utils_bonus.c \
					libft/get_next_line.c libft/get_next_line_utils.c \

OBJS			=	$(SRCS:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

NAME			=	fdf

all:				$(NAME)

$(NAME):			$(OBJS)
					$(MAKE) -C libft
					make -C ./mlx
					$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBFT) -o $(NAME)

bonus:				$(OBJS_BONUS)
					$(MAKE) -C libft
					make -C ./mlx
					$(CC) $(CFLAGS) $(OBJS_BONUS) $(IFLAGS) $(LIBFT) -o $(NAME)

clean:
					$(MAKE) clean -C libft
					$(RM) $(OBJS) $(OBJS_BONUS)

fclean:				clean
					$(MAKE) fclean -C libft
					make clean -C ./mlx
					$(RM) $(NAME)

re:					fclean all

.SILENT:
