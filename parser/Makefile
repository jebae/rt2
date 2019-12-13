# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almoraru <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 10:41:01 by almoraru          #+#    #+#              #
#    Updated: 2019/12/13 15:35:49 by jebae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SD = srcs

OBJ_DIR = srcs

COLOR = \x1b[1;34m

COLOR2 = \x1b[1;35m

COLOR3 = \x1b[0;32m

COLOR4 = \x1b[0;36m

COLOREND = \033[0;0m

SRCS = $(SD)/parse.c $(SD)/ft_mem.c $(SD)/init.c $(SD)/check.c 	  \
$(SD)/check_time.c $(SD)/update_parser.c $(SD)/string_functions.c 				\
$(SD)/string_checks.c $(SD)/number_functions.c $(SD)/handle_vec_utils.c		   \
$(SD)/parse_camera.c $(SD)/parse_objects.c $(SD)/parse_lights.c


NAME = libparse.a

FLAGS = -Wall -Wextra -Werror -g3 # remove flag

OBJECTS = $(SRCS:%.c=%.o)

LIB_PATH = ../libft/


HEADER_PATH = includes/

INCLUDES = $(HEADER_PATH)/

INCLUDE = -I $(LIB_PATH)includes\
	-I $(HEADER_PATH)\
	-I ../includes\
	-I ../libvector\
	-I ../libimg/includes\
	-I ../SDL2/include\

all: $(NAME)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SD)/%.c $(INCLUDES)
	@$(CC) -c $< -o $@ $(FLAGS) $(INCLUDE)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@echo "$(COLOR)RTv1 : Parser installed baby$(COLOREND)"
clean:
	@echo "$(COLOR3)Cleaning objects!$(COLOREND)"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "$(COLOR)Removing :("
	@rm -f $(NAME)
	@echo "$(COLOR4)You murderer!$(COLOREND)"

re: fclean all

.PHONY: all clean fclean re
