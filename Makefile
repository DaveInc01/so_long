NAME = so_long

SRCS = $(wildcard *.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))
CC = gcc
INLCUDES = -Imlx -I.
CFLAGS = -Wall -Wextra -Werror -g $(INLCUDES)

MLX_PATH = mlx

RM = rm -f

MLX_LIB = $(MLX_PATH)/libmlx.dylib

MLX_LINK = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
MACH_EXTRA	= install_name_tool -change @loader_path/libbass.dylib @loader_path/bass/libbass.dylib $(NAME) \
				&& install_name_tool -change libmlx.dylib @loader_path/${MLX_PATH}/libmlx.dylib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

.DEFAULT_GOAL=all

$(MLX_LIB):
	@$(MAKE) -C $(MLX_PATH)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LINK)
	@$(MACH_EXTRA)

clean:
	@${RM} ${OBJS}

fclean: clean
	@$(MAKE) -C $(MLX_PATH) clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
