NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address
SRC_DIR = ./srcs
INCLUDE_DIR = ./include
SRC = 	$(SRC_DIR)/*.c \

MLXDIR = ./minilibx-linux
MLX = $(MLXDIR)/libmlx_Linux.a

OBJ = $(SRC:.c=.o)

RM = rm -rf

%.o:%.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -I$(INCLUDE_DIR) -c $< -o $@ 

$(NAME): $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -lXext -lX11 -o cub3d
$(MLX):
	$(MAKE) -C $(MLXDIR)

all: $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLXDIR)

fclean: clean
	$(RM) $(NAME) $(MLX)

bonus: all

re: fclean all