SRC			= ft_substr ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_strjoin ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_atoi ft_calloc ft_strdup ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd
SRCS		= $(addsuffix .c, ${SRC})
SRCB		= ft_lstmap ft_lstiter ft_lstclear ft_lstdelone ft_lstadd_back ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast
SRCSB		= $(addsuffix .c, ${SRCB})
HEAD		= ./includes/ 
OBJS		= ${SRCS:.c=.o}
OBJSB		= ${SRCSB:.c=.o}
NAME		= libft.a
CC			= cc
RM			= rm -f
AR			= ar rc
RN			= ranlib
CFLAGS		= -Wall -Wextra -Werror

VERDE = \033[1;32m
VERMELHO = \033[5;31m
AZUL = \033[1;36m
NC = \033[0m

all:		$(NAME) $(BONUS)

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}
			@${RN} ${NAME}
			@echo "$(AZUL)Biblioteca $(NAME) criada com sucesso!$(NC)"

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			@${RM} ${OBJS} ${OBJSB}
			@echo "$(VERMELHO)Arquivos objetos limpos!$(NC)"

fclean:		clean
			@${RM} $(NAME)
			@echo "$(VERMELHO)Arquivo $(NAME) eliminada!$(NC)"

re:			fclean all

bonus: ${OBJSB}
			@${AR} ${NAME} ${OBJSB}
			@${RN} ${NAME}

.PHONY:		all clean fclean re bonus
