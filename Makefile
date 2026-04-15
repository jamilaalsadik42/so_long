NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra
INC = -Iincludes -Iget_next_line -Iminilibx-linux
MLX_DIR = minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRC = src/main.c src/error.c src/map_check.c \
	src/map_read.c src/helper.c\
    get_next_line/get_next_line.c \
    get_next_line/get_next_line_utils.c\
	src/map_elements.c\
	src/map_path.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all