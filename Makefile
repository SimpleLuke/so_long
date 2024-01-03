NAME = so_long
CC = cc
CFLAG = -Wall -Werror -Wextra
SRC = src/main.c src/draw_shape.c src/color.c src/close.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = mlx_linux/
MLX_NAME = libmlx_Linux.a
MLX = $(MLX_PATH)$(MLX_NAME)
RM = rm -rf

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

all: $(MLX) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib \
		-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(MLX):
	@git submodule init
	@git submodule update
	@make -sC $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
