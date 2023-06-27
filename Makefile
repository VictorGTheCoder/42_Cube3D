NAME = cube3D

INCLUDES = includes

LINUX_FLAGS = -lm -lX11 -lXext -lpthread

MAC_FLAGS = -framework OpenGL -framework AppKit

SRCS =  $(addprefix srcs/, main.c parsing.c parse_utils.c) \
		$(addprefix srcs/render/, init_window.c ray_caster.c utils.c) \
		$(addprefix includes/get_next_line/, get_next_line.c get_next_line_utils.c) \
		srcs/map_parser.c

LIBS = $(addprefix includes/, libft/libft.a)
OBJS	= ${SRCS:.c=.o}
CFLAGS	=  -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C includes/libft
	make -C includes/mlx_opengl
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) includes/mlx_opengl/libmlx.a -lz $(MAC_FLAGS) -o $(NAME) -fsanitize=address


all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C includes/mlx_opengl

fclean:		clean
			$(RM) $(NAME)
			make fclean -C includes/libft

re:			fclean all

.PHONY: all clean fclean re