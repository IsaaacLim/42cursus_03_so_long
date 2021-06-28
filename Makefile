NAME	=	so_long

SRCS	=	test.c
OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
#CFLAGS	=	-c -Wall -Werror -Wextra -g3 #(exclude -c?)

MLX		=	-L. -lmlx -lm -lbsd -lX11 -lXext
MLXDIR	=	mlx_linux
MLXLIB	=	$(MLXDIR)/libmlx.a

all : $(MLXLIB) $(NAME)

$(MLXLIB):
	make -C $(MLXDIR)/

# From 42Docs > Getting Started
## To link with the required internal Linux API
#$(NAME): $(OBJ)
#	$(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(MLX)
## For object files (Doesn't seem to matter if it's used/not)
#%.o: %.c
#	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make clean -C $(MLXDIR)/
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
