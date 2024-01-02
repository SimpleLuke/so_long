NAME = so_long
CC = cc
CFLAG = -Wall -Werror -Wextra
SRC = so_long.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH = mlx_linux
RM = rm -rf

#%.o:%.c
	#$(CC) $(CFLAG) -I/usr/include -Imlx-linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): mlx $(LIBFT) $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib \
		-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
mlx:
	git submodule init
	git submodule update
	make -C $(MLX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft mlx
