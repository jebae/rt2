# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almoraru <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 10:41:01 by almoraru          #+#    #+#              #
#    Updated: 2019/09/05 21:37:03 by almoraru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC_DIR = srcs

OBJ_DIR = srcs

COLOR = \x1b[1;34m

COLOR2 = \x1b[1;35m

COLOR3 = \x1b[0;32m

COLOR4 = \x1b[0;36m

COLOREND = \033[0;0m

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/parse.c $(SRC_DIR)/ft_mem.c $(SRC_DIR)/init.c\
$(SRC_DIR)/check.c $(SRC_DIR)/check_time.c $(SRC_DIR)/update_parser.c

NAME = parse

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:%.c=%.o)

LIB_PATH = libft/


HEADER_PATH = includes/

INCLUDES = $(HEADER_PATH)/

INCLUDE = -I $(LIB_PATH)includes\
	-I $(HEADER_PATH)\

all: $(NAME)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDES)
	@$(CC) -c $< -o $@ $(FLAGS) $(INCLUDE)

$(NAME): $(OBJECTS)
	@make -C libft
	@$(CC) -o $@ $^ $(FLAGS) -L libft/ -lft $(INCLUDE)
	@echo "$(COLOR)RTv1 : Parser installed baby$(COLOREND)"
clean:
	@echo "$(COLOR3)Cleaning objects!$(COLOREND)"
	@make clean -C libft
	@rm -f $(OBJECTS)

fclean: clean
	@echo "$(COLOR)Removing :("
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(COLOR4)You murderer!$(COLOREND)"

re: fclean all

.PHONY: all clean fclean re
