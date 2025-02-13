# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleortiz <aleortiz@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 18:30:26 by aleortiz          #+#    #+#              #
#    Updated: 2025/02/13 20:27:02 by aleortiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpipex.a
#----------------------FLAGS---------------------------#
LIBCC = ar rcs
CFLAGS = -g -Wall -Werror -Wextra  -I$(HEADERPH) -I$(HEADERL)\
#		 -g -fsanitize=address,undefined\

#----------------------REMOVE--------------------------#
RM = rm -f
#----------------------PATHS---------------------------#
PRMA = ./utils
HEADERP = ./utils
HEADERPH = ./utils/src
HEADERL = ./utils/libftb
SOURCE = ./src
#------------------------------------------------------#
#                      GROUP                           #
#                      FILES                           #
#------------------------------------------------------#
FILES = $(SOURCE)/ft_mainpipex.c\
		$(SOURCE)/ft_utilspipex.c
#------------------------------------------------------#
#                                                      #
#------------------------------------------------------#
MAIN = $(SOURCE)/pipex.c
#------------------------------------------------------#
#                      CREATE                          #
#                      OBJECTS                         #
#------------------------------------------------------#
OBJ = $(FILES:.c=.o)

#----------------------RULES---------------------------#
all: $(NAME)

makeprintf:
	@make -C $(HEADERP)
	@cp $(HEADERP)/libftprintf.a .
	@mv libftprintf.a $(NAME)

%.o : $(SOURCE)/%.c
	@cc $(CFLAGS) -c $< -o $@

$(NAME): makeprintf $(OBJ)
	@$(LIBCC) $(NAME) $(OBJ)

Cpipex : $(NAME) clean
	@cc $(CFLAGS) $(MAIN) $(NAME) -o pipex

memory : Cpipex
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./pipex Makefile cat "grep Cpipex" out.txt

clean:
	@$(RM) -R $(OBJ)
	@make clean -C $(HEADERP)

fclean: clean
	@$(RM) pipex
	@$(RM) $(HEADERL)/libft.a
	@$(RM) $(HEADERP)/libftprintf.a
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
