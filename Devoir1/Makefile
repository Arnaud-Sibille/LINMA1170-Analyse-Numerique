SRCS = srcs/advanced_linear_algebra_ops.c srcs/file_ops.c srcs/linear_algebra_ops.c srcs/prints.c srcs/main.c

OBJS = ${SRCS:.c=.o}

NAME = devoir1

CC = gcc

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	
all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
