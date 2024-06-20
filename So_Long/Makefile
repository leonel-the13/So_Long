NAME = so_long

GAME_LOGIC = g_lgc/*.c

GET_NEXT_LINE = get_next_line/*.c

MINILIBX = minilibx/

LIBRARY = -Lminlibx -lmlx -framework OpenGL AppKit

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes/

all:
	@make -C ${MINILIBX}
	@${CC} ${CFLAGS} ${GAME_LOGIC} ${GET_NEXT_LINE} ${LIBRARY} -o ${NAME}

clean:

fclean: clean
	@make fclean -C ${MINILIBX}
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
