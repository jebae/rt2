# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 07:58:15 by mhernand          #+#    #+#              #
#    Updated: 2019/07/25 15:34:11 by mhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

INC1 = includes/rtv1_parser.h

INC2 = includes/rtv1.h

CFLAGS = -Wall -Werror -Wextra -g3 # remove g3 flag

#  -fsanitize=address

CC = gcc

SRCS = main.c parser.c start_rtv1.c touch.c draw_sphere.c verify_specs_setup.c\
	verify_shapes.c verify_onearg.c verify_threeargs.c verify_uniform_args.c\
	verify_obj_voc.c verify_obj_voc_checker.c verify_spec_voc.c debugger.c\
	debugger_two.c debugger_three.c verify_oneargs_partwo.c\
	verify_threeargs_partwo.c globals_and_set_vocab.c verify_shapes_two.c\
	create_links.c

OBJS = $(SRCS:.c=.o)

L_FOLD = libft/

L_TARG = libft

M_FOLD = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

superfast:
	@make -j8 all

all: 
	@make $(NAME)

$(NAME):$(OBJS) | $(L_TARG)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(LIBMLX) -fsanitize=address -o $(NAME)
	@touch .gitignore
	@echo "*.o" > .gitignore
	@echo "*.a" >> .gitignore

%.o: %.c $(INC1) $(INC2) 
	$(CC) $(CFLAGS) $< -c

$(L_TARG):
	@make -C $(L_FOLD) all
	@make -C $(M_FOLD)

clean:
	@make -C $(L_TARG) clean
	@make -C $(M_FOLD) clean
	@rm -rf $(OBJS)
	@echo "RTv1 is clean !"

fclean: clean
	@make -C $(L_TARG) fclean
	@rm -rf $(NAME)
	@echo "... and fclean too !"

re: fclean all

.PHONY: all clean fclean all libft
