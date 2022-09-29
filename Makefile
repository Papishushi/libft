###############################################################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SBUILDER = ar
SBFLAGS = -crs
MFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BFILES = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS = ${MFILES:.c=.o}
BOBJS = ${BFILES:.c=.o}
NAME = libft.a
SHELL=/bin/bash
###############################################################################
RM = rm -f
###############################################################################
.PHONY: clean bclean fclean all bonus actions
###############################################################################
all:	fclean ${NAME} bonus

${NAME}:
		@${CC} -g -c ${CFLAGS} ${MFILES}
		@${SBUILDER} ${SBFLAGS} ${NAME} ${OBJS}

bonus:
		@${CC} -g -c ${CFLAGS} ${BFILES}
		@${SBUILDER} ${SBFLAGS} ${NAME} ${BOBJS}

re:		fclean all

clean:
		@${RM} ${OBJS}

bclean:
		@${RM} ${BOBJS}

fclean:	clean bclean
		@${RM} ${NAME}

actions:
		cd tester && make
		##cd libft-unit-test && make f
		##cd libft-war-machine && ./grademe.sh
