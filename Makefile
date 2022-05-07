# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asokolov <asokolov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 22:04:13 by asokolov          #+#    #+#              #
#    Updated: 2022/05/06 11:11:08 by asokolov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CC = gcc

SR_SRC =	big_sort.c 					\
			big_sort_helpers.c			\
			big_sort_scores.c			\
			big_sort_rotations.c		\
			malloc_and_free.c			\
			ft_atoi.c 					\
			ft_split.c					\
			ft_calloc.c					\
			small_sort.c 				\
			utils.c 					\
			errors_checker.c			\
			better_sorting.c			\
			../main.c


OP_SRC = 	reverse_rotate.c 			\
			push.c 						\
			rotate.c 					\
			swap.c


SR_OBJS = $(SR_SRC:.c=.o)
OP_OBJS = $(OP_SRC:.c=.o)

SR_PATH = sorting/
OP_PATH = operations/

%.o : %.c
	${CC} -c $< -o ${<:.c=.o}

$(NAME): 	$(addprefix $(SR_PATH), $(SR_OBJS)) $(addprefix $(OP_PATH), $(OP_OBJS))
			$(CC) $(CFLAGS) -o $@ $^
			
all: $(NAME)

clean: 
	rm -f  $(addprefix $(SR_PATH), $(SR_OBJS)) \
			$(addprefix $(OP_PATH), $(OP_OBJS))

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


$(SR_PATH)%.o : $(SR_PATH)%.c
				$(CC) $(CFLAGS) -o $@ -c $<
				
$(OP_PATH)%.o : $(OP_PATH)%.c
				$(CC) $(CFLAGS) -o $@ -c $<
