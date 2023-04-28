# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:34:33 by oboucher          #+#    #+#              #
#    Updated: 2023/04/27 22:20:14 by oboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--- LIBRARY NAME ---#
NAME = push_swap

#--- COMMAND VARIABLES ---#
CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

RM = rm -f

AR = ar rcs

MK = mkdir -p

#--- COLORS ---#
GREEN	=	\033[1;32m

RED		=	\033[1;31m

BLUE	=	\033[1;34m

YELLOW	=	\033[1;93m

WHITE	=	\033[1;97m

RESET 	= 	\033[0m

#--- INCLUDE ---#
INCDIR = inc

#--- SOURCE ---#
SRCDIR = src

SRC = 	push_swap.c

VPATH	=	${SRCDIR}

#--- OBJECT ---#
OBJDIR  =   obj

OBJ = $(addprefix ${OBJDIR}/, ${SRC:.c=.o})


#--- RULES ---#
${OBJDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@
	
all				: 	 	$(NAME)
	
$(NAMES)		: 		$(OBJDIR) $(OBJ)
	@${CC} ${CFLAGS} -I${INCDIR} -o ${NAMES} ${OBJ}
	
	
${NAME}		:		$(OBJDIR) $(OBJ)
	@${CC} ${CFLAGS} -I${INCDIR} -o ${NAME} ${OBJ}
	@echo "$(NAME)${GREEN} sucessefully compiled 📁.${RESET}"

$(OBJDIR)		:
	@$(MK) ${OBJDIR}

run				:		all
	@./${NAME}

update:
	git submodule update --remote --recursive

init:
	git submodule update --init --recursive

clean			:
	@$(RM) $(OBJ)
	@$(RM)r $(OBJDIR)
	
fclean			: 		clean	
	@$(RM) $(NAME)
	@echo "$(NAME)${GREEN} object files and executable successfully removed 🗑.${RESET}"

re				: 		fclean all

.PHONY			: 		all clean fclean re