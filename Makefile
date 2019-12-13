NAME = rt

CFLAGS = -Wall -Werror -Wextra -Ofast

LIBFT_PATH = ./libft
LIBVECTOR_PATH = ./libvector
LIBIMG_PATH = ./libimg
PARSER_PATH = ./parser

INC = -I includes\
	-I $(LIBFT_PATH)/includes\
	-I $(LIBVECTOR_PATH)\
	-I $(PARSER_PATH)/includes\
	-I $(LIBIMG_PATH)/includes\

LIB = -L $(LIBFT_PATH) -lft\
	-L $(PARSER_PATH) -lparse\
	-L $(LIBVECTOR_PATH) -lvector\
	-L $(LIBIMG_PATH) -limg\

CC = gcc

SRC_DIR = srcs

OBJ_DIR = objects

SRC_CEL_SHADING = cel_shading.c\
	face.c\

SRC_INTERSECT_NORMAL = box.c\
	pyramid.c\
	rectangle.c\
	ring.c\
	triangle.c\

SRC_LIGHT = distant_light.c\
	spherical_light.c\

SRC_SET_LIGHT = distant_light.c\
	spherical_light.c\

SRC_RENDER = anti_aliasing.c\
	multithread.c\
	render.c\

SRC_ROTATE = box.c\
	q_rotate.c\
	quaternion_operator.c\
	rotate_object_axis.c\
	sphere.c\
	rectangle.c\
	cone.c\
	cylinder.c\
	plane.c\
	pyramid.c\
	ring.c\
	triangle.c\

SRC_SET_OBJECT = box.c\
	common.c\
	cone.c\
	cylinder.c\
	plane.c\
	pyramid.c\
	rectangle.c\
	ring.c\
	sphere.c\
	triangle.c\

SRC_SHADING = diffuse_specular.c\
	reflection.c\
	refraction.c\
	shading.c\
	shadow.c\

SRC_TEXEL = bump_mapping.c\
	texel.c\
	texture_mapping.c\

SRC_TRACE = ray.c\
	trace.c\
	trace_record.c\

SRC_TRANSLATE = box.c\
	cone.c\
	cylinder.c\
	plane.c\
	pyramid.c\
	rectangle.c\
	ring.c\
	sphere.c\
	triangle.c\

SRC_UV_MAPPING = cone.c\
	cylinder.c\
	rectangle.c\
	sphere.c\

SRCS = color_op.c\
	get_normal.c\
	intersec_functions.c\
	intersec_functions_2.c\
	mat3_op.c\
#main.c\

# objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/intersect_normal_, $(SRC_INTERSECT_NORMAL:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_LIGHT:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/set_, $(SRC_SET_LIGHT:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_RENDER:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/rot_, $(SRC_ROTATE:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/set_, $(SRC_SET_OBJECT:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_SHADING:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_TEXEL:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_TRACE:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/transl_, $(SRC_TRANSLATE:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/uv_, $(SRC_UV_MAPPING:.c=.o))
OBJS += $(addprefix $(OBJ_DIR)/, $(SRC_CEL_SHADING:.c=.o))

# compile objs
HEADERS = ./includes/raycast.h\
	./includes/rt.h\
	./includes/rt_struct.h\
	./$(LIBFT_PATH)/includes/libft.h\
	./$(LIBVECTOR_PATH)/libvector.h\
	./$(PARSER_PATH)/includes/parse.h\
	./$(LIBIMG_PATH)/includes/libimg.h\

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/intersect_normal_%.o : $(SRC_DIR)/intersect_normal/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/light/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/set_%.o : $(SRC_DIR)/set_light/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/render/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/set_%.o : $(SRC_DIR)/render/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/rot_%.o : $(SRC_DIR)/rotate/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/set_%.o : $(SRC_DIR)/set_object/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/shading/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/texel/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/trace/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/transl_%.o : $(SRC_DIR)/translate/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/uv_%.o : $(SRC_DIR)/uv_mapping/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/cel_shading/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# command
SDL = ./SDL2.framework

superfast:
	make -j8 all

all: $(NAME)

$(NAME) : deps $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(LIB) $(OBJS) -o $(NAME)
	@printf "\033[32m[ ✔ ] $(NAME)\n\033[0m"

$(SDL) :
	@if [ ! -d ./SDL2.framework ]; \
	then curl https://www.libsdl.org/release/SDL2-2.0.10.dmg \
	-o SDL2-2.0.10.dmg ; hdiutil attach SDL2-2.0.10.dmg ; \
	cp -r /Volumes/SDL2/SDL2.framework . ; \
	hdiutil detach /Volumes/SDL2 ; fi; \

$(OBJ_DIR) : 
	@mkdir -p $@

deps :
	@make -C $(LIBFT_PATH) all
	@make -C $(LIBVECTOR_PATH) all
	@make -C $(LIBIMG_PATH) all
	@make -C $(PARSER_PATH) all
	rm -rf $(SDL)

TEST_INC = $(INC) -I srcs/__tests__ -I $(UNITY_PATH)/include

TEST_LIB = $(LIB) -L ./minilibx_macos -lmlx -L $(UNITY_PATH)/lib -lunity -framework OpenGL -framework Appkit

TEST_SRC = srcs/__tests__/*/*.c\
	srcs/__tests__/*.c\

CONTENTS = contents

$(CONTENTS) :
	curl -L https://www.dropbox.com/sh/a85xtpsaokehu2y/AAAMvXC4yQKq0aAubntNgynFa?dl=1 -o $@.zip
	unzip $@.zip -x / -d $@
	rm -f $@.zip

test : $(CONTENTS) $(OBJS)
	$(CC) -fsanitize=address -D UNITY_MEMORY_OVERRIDES_H_ -D UNITY_INCLUDE_CONFIG_H $(CFLAGS) $(TEST_INC) $(TEST_LIB) $(TEST_SRC) $(OBJS) -o test

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBVECTOR_PATH) clean
	@make -C $(LIBIMG_PATH) clean
	@make -C $(PARSER_PATH) clean
	@rm -rf $(OBJ_DIR) 2> /dev/null || true
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "RTv1 is clean !"

fclean: clean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "... and fclean too !"
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIBVECTOR_PATH) fclean
	@make -C $(LIBIMG_PATH) fclean
	@make -C $(PARSER_PATH) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean all libft test
