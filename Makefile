# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:54:51 by emamenko          #+#    #+#              #
#    Updated: 2019/02/13 16:32:33 by emamenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libtest.a
SOURCES	=	libtest.c
OBJECTS	=	$(SOURCES:.c=.o)

.PHONY:		$(NAME) all clean fclean re

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
