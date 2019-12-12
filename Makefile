# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/05 07:58:15 by mhernand          #+#    #+#              #
#    Updated: 2019/12/10 18:44:01 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

CFLAGS = -Wall -Werror -Wextra -Ofast #-fsanitize=address

INC = -I includes/ -I libft/ -I libvector/ -I parser/includes/ -I libimg/includes/

CC = gcc

SRC_DIR = srcs

OBJ_DIR = objects

SRCS = main.c\
	handle/touch.c\
	raycasting_files/color_op.c\
	raycasting_files/get_normal.c\
	raycasting_files/intersec_functions.c\
	raycasting_files/intersec_functions_2.c\
	raycasting_files/raycast.c\
	raycasting_files/shading.c\
	raycasting_files/vector_op.c\
	raycasting_files/vector_op_2.c\
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

V_FOLD = libvector/

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

TEST_INC = $(INC) -I srcs/__tests__ -I $(UNITY_PATH)/include

TEST_LIB = -L ./libft -lft -L ./libvector -lvector $(LIBMLX) -L $(UNITY_PATH)/lib -lunity -L ./libimg -limg

TEST_SRC = srcs/handle/*.c\
	srcs/raycasting_files/*.c\
	srcs/raycasting_files/*/*.c\
	srcs/__tests__/*/*.c\
	srcs/__tests__/*.c\

CONTENTS = contents

$(CONTENTS) :
	curl -L https://www.dropbox.com/sh/a85xtpsaokehu2y/AAAMvXC4yQKq0aAubntNgynFa?dl=1 -o $@.zip
	unzip $@.zip -x / -d $@
	rm -f $@.zip

test : $(CONTENTS)
	$(CC) -D UNITY_MEMORY_OVERRIDES_H_ -D UNITY_INCLUDE_CONFIG_H $(CFLAGS) $(TEST_INC) $(TEST_LIB) $(TEST_SRC) -o test

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

.PHONY: all clean fclean all libft test
