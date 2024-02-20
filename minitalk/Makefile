# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 13:10:19 by fvaliyak          #+#    #+#              #
#    Updated: 2023/03/11 14:19:10 by fvaliyak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1		:= client
NAME2		:= server

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror 

SRCS1		:=	client.c \

SRCS2		:=	server.c \

OBJS1		:= $(SRCS1:.c=.o)

OBJS2		:= $(SRCS2:.c=.o)

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN		:= \033[1;36m
RM			:= rm -f

all:		all2 all1

${NAME2}:	${OBJS2}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME2) ${CLR_RMV}..."
			${CC} ${CFLAGS} -o ${NAME2} ${OBJS2}
			@echo "$(GREEN)$(NAME2) created[0m ✔️"

${NAME1}:	${OBJS1}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME1) ${CLR_RMV}..."
			${CC} ${CFLAGS} -o ${NAME1} ${OBJS1}
			@echo "$(GREEN)$(NAME1) created[0m ✔️"

all2:		${NAME2}

all1:		${NAME1}

clean:
			@ ${RM} *.o 
			@ echo "$(RED)Deleting $(CYAN)$(NAME1) and $(NAME2) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME1} ${NAME2}
			@ echo "$(RED)Deleting $(CYAN)$(NAME1) and $(NAME2) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re