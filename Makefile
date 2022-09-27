###############################################################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SBUILDER = ar
SBFLAGS = -crs
CFILES = $(wildcard *.c)
OBJS = ${CFILES:.c=.o}
NAME = libft.a
###############################################################################
RM = rm -f
###############################################################################
.PHONY: clean fclean all
###############################################################################
all:	fclean ${NAME}

${NAME}:
		@${CC} -c ${CFLAGS} ${CFILES}
		@${SBUILDER} ${SBFLAGS} ${NAME} ${OBJS}

re:		fclean all

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${NAME}
		
actions:
		cd ./tester/
		make m
