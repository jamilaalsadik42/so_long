NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra
INC = -Iincludes -Iget_next_line -Iminilibx-linux

MLX_DIR = minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRC = src/core/main.c src/core/error.c src/map/map_check.c \
	src/map/map_read.c src/core/helper.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	src/map/map_elements.c src/map/map_path.c\
	src/map/map_walls.c src/render/draw.c\
	src/render/render_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	chmod +x $(MLX_DIR)/configure
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all