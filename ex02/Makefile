# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 10:09:08 by kmeixner          #+#    #+#              #
#    Updated: 2022/07/04 13:54:06 by kmeixner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	moreforms

SRCS		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

CC			=	c++

RM			=	rm

CFLAGS		=	-Wall -Werror -Wextra -std=c++98

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:		
			$(RM) -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re
