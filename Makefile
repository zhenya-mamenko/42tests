# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:54:51 by emamenko          #+#    #+#              #
#    Updated: 2019/02/16 11:33:31 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		$(NAME) all clean fclean re

NAME	=	libtest.a
SOURCES	=	libtest.c
OBJECTS	=	$(SOURCES:.c=.o)

all:		$(NAME)

$(NAME):
			gcc -Wall -Werror -Wextra -c $(SOURCES) 
			ar rc $(NAME) $(OBJECTS)
			ranlib $(NAME)

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all
