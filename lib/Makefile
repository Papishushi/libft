# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 18:09:59 by dmoliner          #+#    #+#              #
#    Updated: 2023/01/08 18:13:37 by dmoliner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
NAME = libft.a
RM = rm -rf
################################################################################
##								MANDATORY									  ##
################################################################################
CFILES = \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #

################################################################################
##									BONUS									  ##
################################################################################
CBONUS = \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS = $(CFILES:.c=.o)
BOBJS = $(CBONUS:.c=.o)
################################################################################

################################################################################
.PHONY: all re fclean clean bonus bclean
################################################################################
all:        bonus $(NAME)

$(NAME): $(OBJS)
			@$(AR) $(NAME) $(OBJS)

%.o:%.c
			$(CC) $(CFLAGS) -c $^ -o $@

bonus: $(OBJS) $(BOBJS)
			@$(AR) $(NAME) $(OBJS) $(BOBJS)


re:     	fclean all

fclean: clean
			@$(RM) $(NAME)

clean:	bclean
			@$(RM) $(OBJS)

bclean:
			@$(RM) $(BOBJS)

# $<: rule target file (input)
# $@: rule source file (output)
