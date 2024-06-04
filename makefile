NAME =		minishell

CC =		cc

FLAGS =		-Wall -Werror -Wextra

SRC = 		readline_test.c exec_ext.c builtins.c

OBJ = ${SRC:.c=.o}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	make -s -C libft
	${CC} ${FLAGS} ${OBJ} ./libft/libft.a -lreadline -o ${NAME}

all:	${NAME}

clean:
	make clean -s -C libft
	rm -f ${OBJ}

fclean:	clean
	make fclean -s -C libft
	rm -f ${NAME}

re: fclean all