# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 07:58:15 by mhernand          #+#    #+#              #
#    Updated: 2019/11/08 11:47:36 by sabonifa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CFLAGS = -Wall -Werror -Wextra -Ofast #-fsanitize=address

INC = -I includes/

CC = gcc

SRC_DIR = srcs

OBJ_DIR = objects

SRCS = main.c\
	handle/touch.c\
	parser_files/parser.c\
	parser_files/verify_specs_setup.c\
	parser_files/spec_reset.c\
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
	parser_files/verify_threeargs_parthree.c\
	parser_files/verify_threeargs_partfour.c\
	parser_files/verify_threeargs_partfive.c\
	parser_files/globals_and_set_vocab.c\
	parser_files/verify_shapes_two.c\
	parser_files/create_links.c\
	parser_files/last_checks.c\
	raycasting_files/color_op.c\
	raycasting_files/get_normal.c\
	raycasting_files/intersec_functions.c\
	raycasting_files/intersec_functions_2.c\
	raycasting_files/raycast.c\
	raycasting_files/shading.c\
	raycasting_files/vector_op.c\
	raycasting_files/vector_op_2.c\
	raycasting_files/object_manipulation.c\
	raycasting_files/start_rtv1.c\
	raycasting_files/matrix_check.c\
	raycasting_files/multithread.c

SUB_FOLD = parser_files handle raycasting_files

BUILD_DIR = $(addprefix $(OBJ_DIR)/, $(SUB_FOLD))

SRC = $(addprefix $(SRC_DIR)/,$(SRCS))

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJS))

OBJS = $(SRCS:.c=.o)

L_FOLD = libft/

L_TARG = libft

V_FOLD = vectors/

V_TARG = libvector

M_FOLD = minilibx_macos/

LIBMLX = -L ./minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

superfast:
	@make -j8 all

all: objects
	@make $(NAME)

objects : 
	@mkdir -p $(BUILD_DIR)

$(NAME):$(OBJ) | $(L_TARG)
	@$(CC) $(CFLAGS) $(INC) libft/libft.a vectors/libvector.a $(LIBMLX) $(OBJ) -o $(NAME)
	@touch .gitignore
	@printf "\033[32m[ ✔ ] $(NAME)\n\033[0m"
	@echo $(OBJ) > .gitignore
	@echo $(NAME) >> .gitignore

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "$<"

$(L_TARG):
	@make -C $(L_FOLD) all
	@make -C $(V_FOLD) all
	@make -C $(M_FOLD)

clean:
	@make -C $(L_FOLD) clean
	@make -C $(V_FOLD) clean
	@make -C $(M_FOLD) clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR) 2> /dev/null || true
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "RTv1 is clean !"

fclean: clean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "... and fclean too !"
	@make -C $(L_FOLD) fclean
	@make -C $(V_FOLD) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all libft
