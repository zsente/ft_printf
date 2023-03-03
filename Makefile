# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zoesente <zoesente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 15:29:02 by zoesente          #+#    #+#              #
#    Updated: 2023/01/24 15:55:00 by zoesente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= ft_printf.c

OBJ 		= $(SRC:.c=.o)

CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Wall -Werror -Wextra

LIB_PATH	= libft/
DEP 		= libft.a
NAME		= libftprintf.a

all :		$(NAME)

$(NAME): 	$(DEP) $(OBJ)
			ar rc $(NAME) $(OBJ)

$(DEP):
			@make -C $(LIB_PATH)
			mv $(LIB_PATH)$(DEP) $(NAME)

clean:
			@make fclean -C $(LIB_PATH)
			$(RM) $(OBJ)

fclean: 
			$(RM) $(LIB_PATH)$(DEP)
			$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
