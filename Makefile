# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 00:46:36 by abelov            #+#    #+#              #
#    Updated: 2023/12/05 00:46:38 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a
CC		=	gcc
CFLAGS  =	-gdwarf-2 -g3 -ggdb3 \
				-Wall -Wextra -Werror \
				-pthread \
				-ffunction-sections \
				-fdata-sections \
				-MMD -fcf-protection=none -mmanual-endbr
AR				=	ar
ARFLAGS 		=	rcs
LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a
RM 			:=	rm -rf

SRC_FILES := ft_printf.c \
				ft_print_unsigned.c \
				ft_print_hex.c

OBJ_DIR			=	obj
OBJS			=	$(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@


$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
					@cp	$(LIBFT) $(NAME)
					$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -pv $(OBJ_DIR)

all:				$(NAME)


$(OBJ_DIR)/main.o:	src/main.c $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

main:				$(OBJ_DIR)/main.o $(NAME)
					$(CC) -lm $^ -o $@
					./main

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR) a.out main

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all main

.PHONY:				all bonus clean fclean re libft
