###############################################################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SBUILDER = ar
SBFLAGS = -crs
CFILES = $(wildcard *.c)
OBJS = ${CFILES:.c=.o}
NAME = libft.a
SHELL=/bin/bash
###############################################################################
RM = rm -f
###############################################################################
.PHONY: clean fclean all actions
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
		cd tester && make m
		cd libft-unit-test && make f
		cd libft-war-machine && ./grademe.sh
