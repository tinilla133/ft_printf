# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvizcaya <fvizcaya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 14:12:08 by fvizcaya          #+#    #+#              #
#    Updated: 2024/04/10 13:06:17 by fvizcaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

NAME = libftprintf.a

SRC = \
	ft_printf.c print_decimal.c print_base.c print_chars.c \
	print_pointer.c aux_functions.c
	
OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

BONUS_CACHE = .cache

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	
$(BONUS_CACHE): $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)
	@touch $(BONUS_CACHE)

# bonus: $(BONUS_CACHE)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS) $(BONUS_CACHE)

fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus