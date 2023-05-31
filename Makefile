# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 21:43:24 by rennacir          #+#    #+#              #
#    Updated: 2023/05/31 23:08:35 by rennacir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
# CFLAGS = -Wall -Wextra -Werror -
PARS = $(addprefix parsing/, parsing.c error.c)
TOOLS = $(addprefix tools/, ft_atoi.c ft_isdigit.c ft_split.c ft_strjoin.c \
		actual_time.c my_usleep.c print_func.c ft_strcmp.c is_died.c \
		destroy_func.c check_num_of_eat.c init_each_philo.c)

SRCS =  philo.c $(PARS) $(TOOLS)

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)
	@echo $(NAME) "Created"

%.o:%.c philo.h
	@$(CC) $(CFLAGS) -c  $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

clean_b:
	@$(RM) $(OBJBNS)

fclean_b: clean_b
	@$(RM) $(CHECKER_B)

re: fclean all

re_b: fclean_b bonus

.PHONY: all clean fclean re