SRC = get_next_line.c cub3d.c sfill_map.c sfill_map2.c error.c file_error.c func_error.c type_error.c valid_maps.c valid_maps2.c free.c window.c mapmage.c player2d.c events.c raycasting.c project3d.c project3d_part2.c texture.c sprit.c sprit2.c bmp.c
NAME = cub3d.a
HEADER = cub3d.h
NUM = $(expr $(cat map.cub | wc -l) - 11)
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	@(cd mlx/ ; make)
	@(cd gnl/ ; cp get_next_line.c ../)
	@(cd libft/ ; make ; cp libft.a ../cub3d.a)
	@gcc -g -Wall -Wextra -Werror -c $(SRC)
	@ar rcs $(NAME) $(OBJS)
	@(rm get_next_line.c)
	@gcc -g main.c cub3d.a mlx/libmlx.a mlx/libmlx_Linux.a -lbsd -lm -lXext -lX11 -o cub3D
clean:	
	@if [ $(VERO)=1 ]; then rm $(OBJS); VERO=0; fi
	@(cd libft ; make clean)
	@(cd mlx ; make clean)

fclean: clean
	@if [ $(VERA)=1 ]; then rm $(NAME) cub3D; VERA=0; fi
	@(cd libft/ ; make fclean)

re: fclean all
