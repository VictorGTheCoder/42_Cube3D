NAME = cube3D

INCLUDES = includes

LINUX_FLAGS = -lm -lX11 -lXext -lpthread

MAC_FLAGS = -framework OpenGL -framework AppKit

SRCS =  $(addprefix srcs/, main.c display.c render.c init_window.c) \
		$(addprefix srcs/game_tools/, hook.c utils.c draw_segment.c) \
		$(addprefix includes/get_next_line/, get_next_line.c get_next_line_utils.c) \
		$(addprefix srcs/parsing/, copy_file_utils.c map_parser.c parse_utils.c parsing.c args_manager.c) \
		$(addprefix srcs/render2D/, mini_map.c 2D_player_render.c 2D_wall_render.c draw_ray.c) \
		$(addprefix srcs/render3D/, ray_caster.c get_color.c 3D_wall_render.c get_color_near.c 3D_wall_render_near.c find_pixel_screen.c) 

LIBS 	= $(addprefix includes/, libft/libft.a)
OBJS	= ${SRCS:.c=.o}
CFLAGS	=  -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f
LEAKS   = leaks_cube3D
PROD	= test

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C includes/mlx
	make -C includes/libft
	make -C includes/mlx_opengl
	cp includes/mlx/libmlx.dylib .
	$(CC)   $(CFLAGS) $(OBJS) $(LIBS) -lz -L includes/mlx -lmlx $(MAC_FLAGS) -o $(NAME) -fsanitize=address -O2

$(LEAKS): $(OBJS)
	$(CC)   $(CFLAGS) $(OBJS) $(LIBS) -lz -L includes/mlx -lmlx $(MAC_FLAGS) -o $(LEAKS)

$(PROD): $(OBJS)
	$(CC)   $(CFLAGS) $(OBJS) $(LIBS) -L includes/mlx -lmlx $(MAC_FLAGS) -o $(NAME) -fsanitize=address


all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C includes/mlx_opengl

fclean:		clean
			$(RM) $(NAME)
			make fclean -C includes/libft

re:			fclean all

.PHONY: all clean fclean re