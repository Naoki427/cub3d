NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g
# CFLAGS += -g -fsanitize=address
SRC_DIR = ./srcs
INCLUDE_DIR = ./include
SRC = 	$(SRC_DIR)/back_track.c $(SRC_DIR)/check_map.c $(SRC_DIR)/color.c $(SRC_DIR)/file.c $(SRC_DIR)/hook.c \
		$(SRC_DIR)/main.c $(SRC_DIR)/map_int.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/map.c $(SRC_DIR)/n_utils.c \
		$(SRC_DIR)/player.c $(SRC_DIR)/r_utils.c $(SRC_DIR)/raycast.c $(SRC_DIR)/start.c $(SRC_DIR)/test.c $(SRC_DIR)/vector.c \
		$(SRC_DIR)/struct.c


OBJ = $(SRC:.c=.o)

RM = rm -rf

%.o:%.c
	$(CC) $(CFLAGS)  -I$(INCLUDE_DIR) -I./minilibx_opengl_20191021 -c $< -o $@ 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -o cub3d

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

bonus: all

re: fclean all