# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 20:04:08 by mhernand          #+#    #+#              #
#    Updated: 2019/11/16 14:57:21 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
     ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
     ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
     ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c \
     ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
     ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c \
     ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c \
	 ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	 ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	 ft_strequ.c ft_strnequ.c ft_putchar.c ft_putendl_fd.c\
	 ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	 ft_putstr_fd.c ft_itoa.c ft_strjoin.c ft_strsplit.c ft_strsub.c \
	 ft_strtrim.c ft_putchar.c ft_putnbr_fd.c \
	 ft_strclen.c get_next_line.c ft_delsplit.c ft_charfreq.c ft_countstrings.c\
	 ft_iseven.c ft_strfree.c ft_swap_double.c ft_abs_double.c\

OBJECTS = $(SRCS:.c=.o)

superfast:
	@make -j8 all

all:
	@make $(NAME)

$(NAME):$(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJECTS)
	
fclean: clean 
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all
