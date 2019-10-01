gcc -I . \
	-I /usr/local/include -L /usr/local/lib -lmlx \
	-framework OpenGL -framework AppKit -o sand *.c
