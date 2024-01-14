BIN = bin
NAME = so_long
CC = cc
CFLAG = -Wall -Werror -Wextra -g
SRC = src/main.c \
	  src/init.c \
	  src/color.c \
	  src/close.c \
	  src/player_movment.c \
	  src/movement_utils.c \
	  src/render.c \
	  src/render_utils.c \
	  src/map.c \
	  src/map_utils.c \
	  src/map_utils2.c \
	  src/path.c \
	  src/image.c \
	  src/debug.c \
	  src/sprite.c \
	  src/sprite_utils.c \
	  src/animation.c \
	  src/animation_utils.c \
	  src/utils.c \
	  src/enemy.c \
	  src/text.c \
	  src/game_utils.c
OBJ = $(SRC:src/%c=$(BIN)/%o)
INCS = includes
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)
LFLAGS = -L$(LIBFT) -lft -L$(MLX_PATH)
IFLAGS = -I$(INCS) -I$(LIBFT_PATH) -I$(MLX_PATH)
UNAME := $(shell uname)
MLX_PATH = mlx_linux
MLX_NAME = libmlx_Linux.a
MLX = $(MLX_PATH)$(MLX_NAME)
RM = rm -rf

ifeq ($(UNAME), Darwin)
	CC = gcc
	LFLAGS += -lmlx -framework OpenGL -framework Appkit
else ifeq ($(UNAME), FreeBDS)
	CC = clang
	LFLAGS += -lmlx -lbsd -lXext -lX11 -lm
else
	CC = gcc
	CFLAG += -D Linux
	LFLAGS += -lmlx_Linux -lbsd -lXext -lX11 -lm
endif

all: $(MLX) $(NAME)

$(BIN)/%.o: src/%.c
	$(CC) -c $< $(CFLAG) $(IFLAGS) -o $@

$(NAME): $(BIN) $(OBJ) | $(LIBFT)
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

$(MLX):
	@git submodule init
	@git submodule update
	@make -sC $(MLX_PATH)

$(BIN):
	mkdir -p $(BIN)

$(LIBFT):
	@make all -C $(LIBFT_PATH) --no-print-directory

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH) --no-print-directory

re: fclean all

test:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) ./map/map.ber

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME		: $(NAME)\n"
	@printf "CC			: $(CC)\n"
	@printf "CFLAG		: $(CFLAG)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "IFLAGS		: $(IFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: all clean fclean re $(LIBFT)
