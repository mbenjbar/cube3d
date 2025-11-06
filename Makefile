CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS_LINUX = -L./minilibx-linux -lmlx -lXext -lX11 -lm
L_FLAGS = -lmlx -lXext -lX11 -lm -lz
SRC = main.c ./parssing/get_next_line/get_next_line.c ./parssing/get_next_line/get_next_line_utils.c ./parssing/split.c \
./parssing/parssing.c ./parssing/colors.c ./parssing/map_content.c ./parssing/parse_map1.c \
./parssing/parse_map2.c ./parssing/parse_map3.c \
./parssing/parssing_utils.c ./parssing/textures1.c ./parssing/textures2.c ./parssing/parse_map4.c ./parssing/ft_gc.c \
./play/exit.c ./play/init.c ./play/key.c ./play/rendering.c ./play/get_distance.c \
./play/draw.c ./play/direction.c ./play/move.c

NAME  = Cub3D
RM = rm -f

all: ${NAME} 

${NAME}: ${SRC}
	make -C ./libft/
	# make -C ./minilibx/  
	${CC} ${SRC} ./libft/libft.a -o $(NAME) ${CFLAGS}  ${MLX_FLAGS_LINUX}


clean:
	make -C ./libft/ clean

fclean: clean
	${RM} $(NAME)
	make -C ./libft/ fclean

re: fclean all

# -L = Look for library files (like libmlx.a or libmlx.so) inside the folder ./minilibx-linux.
# -l → tells which libraries to link
# L_FLAGS = -lmlx -lXext -lX11 -lm -lz are linker flags that tell the compiler which libraries to use when building the project.

# -lmlx links the MiniLibX graphics library.

# -lXext and -lX11 link the X Window system extensions used by MiniLibX on Linux.

# -lm links the math library (for functions like sin, cos, tan, etc.).

# -lz links the zlib compression library, sometimes required when handling images.
# Together, they make sure the program can compile and run all its graphical and mathematical operations correctly.