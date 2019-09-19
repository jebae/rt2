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

INC1 = rtv1_parser.h

INC2 =  rtv1.h

CFLAGS = -Wall -Werror -Wextra -g3 # remove g3 flag

# LIB_A = libft/libft.a

# MLX_A = minilibx_macos/mlx.a

CPPFLAGS = -I includes/

#  -fsanitize=address

CC = gcc

SRC_DIR = srcs

OBJ_DIR = objects

SRCS = main.c start_rtv1.c\
	handle/touch.c\
	parser_files/parser.c\
	parser_files/verify_specs_setup.c\
	parser_files/verify_shapes.c\
	parser_files/verify_onearg.c\
	parser_files/verify_threeargs.c\
	parser_files/verify_uniform_args.c\
	parser_files/verify_obj_voc.c\
	parser_files/verify_obj_voc_checker.c\
	parser_files/verify_spec_voc.c\
	parser_files/debugger.c\
	parser_files/debugger_two.c\
	parser_files/debugger_three.c\
	parser_files/verify_oneargs_partwo.c\
	parser_files/verify_threeargs_partwo.c\
	parser_files/globals_and_set_vocab.c\
	parser_files/verify_shapes_two.c\
	parser_files/create_links.c

SUB_FOLD = parser_files handle

BUILD_DIR = $(addprefix $(OBJ_DIR)/, $(SUB_FOLD))

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))

OBJS = $(SRCS:.c=.o)

L_FOLD = libft/

L_TARG = libft

M_FOLD = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

superfast:
	@make -j8 all

all: objects
	@make $(NAME)

objects : 
	@mkdir -p $(BUILD_DIR)

$(NAME):$(OBJ) | $(L_TARG)
	@$(CC) $(CFLAGS) $(CPPFLAGS) libft/libft.a $(LIBMLX) -fsanitize=address $(OBJ) -o $(NAME)
	@touch .gitignore
	@echo $(OBJ) > .gitignore
	@echo $(NAME) >> .gitignore

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(L_TARG):
	@make -C $(L_FOLD) all
	@make -C $(M_FOLD)

clean:
	@make -C $(L_TARG) clean
	@make -C $(M_FOLD) clean
	@rm -rf $(OBJ)
	@echo "RTv1 is clean !"

fclean: clean
	@make -C $(L_TARG) fclean
	@rm -rf $(NAME)
	@echo "... and fclean too !"

re: fclean all

.PHONY: all clean fclean all libft
