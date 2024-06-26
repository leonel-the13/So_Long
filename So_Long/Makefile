NAME = so_long

SRCS = g_lgc/*.c get_next_line/*.c

MINILIBX = minilibx

LIBRARY = -L${MINILIBX} -lmlx -lX11 -lXext

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --silent

all:
	@make -C ${MINILIBX}
	@make -C libft_score
	@${CC} ${CFLAGS} ${SRCS} ${LIBRARY} libft_score/libft.a -o ${NAME}
	@clear
clean:
	@make clean -C libft_score
	@make clean -C ${MINILIBX}

fclean: clean
	@make fclean -C libft_score
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
