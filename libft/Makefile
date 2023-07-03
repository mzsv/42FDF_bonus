# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenses- <amenses-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 21:02:54 by amenses-          #+#    #+#              #
#    Updated: 2023/02/20 22:12:20 by amenses-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c ft_putstr_fd.c\
					ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_strjoin.c ft_itoa.c ft_putnbr_fd.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c  ft_isascii.c ft_putendl_fd.c \
					ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_putchar_fd.c \
					ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_split.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
					ft_lstclear.c ft_lstiter.c ft_lstmap.c \
					ft_printf.c \
					ft_printf_utils_0.c ft_printf_utils_1.c \
					ft_printf_utils_2.c ft_printf_utils_3.c \
					ft_printf_utils_4.c ft_printf_utils_5.c \
					ft_printf_utils_6.c ft_printf_utils_7.c \
					get_next_line.c get_next_line_utils.c \

OBJS			= $(SRCS:.c=.o)

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM)  $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.SILENT:
