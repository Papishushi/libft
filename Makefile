###############################################################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SBUILDER = ar
SBFLAGS = -crs
CFILES = $(wildcard *.c)
OBJS = ${CFILES:.c=.o}
HFILES = libft.h
NAME = libft.a
###############################################################################
RM = rm -f
###############################################################################
.PHONY: clean fclean all test
###############################################################################
all:		fclean ${NAME}

${NAME}:
		@${CC} -c ${CFLAGS} ${CFILES}
		@${SBUILDER} ${SBFLAGS} ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS}

fclean:		clean
		@${RM} ${NAME}
