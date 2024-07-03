# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olivierboucher <olivierboucher@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:34:33 by oboucher          #+#    #+#              #
#    Updated: 2023/10/28 21:06:44 by olivierbouc      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--- LIBRARY NAME ---#
NAME = push_swap
LDIR = libft_/
LIBFT = libft.a

#--- COMMAND VARIABLES ---#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
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

SRC = 	push_swap.c pp.c rr.c rrr.c s.c small_sort.c string.c utils.c dlst.c pars.c radix_sort.c error.c index.c

VPATH	=	${SRCDIR}

#--- OBJECT ---#
OBJDIR  =   obj

OBJ = $(addprefix ${OBJDIR}/, ${SRC:.c=.o})


#--- RULES ---#
${OBJDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@
	
all				: 	  libft $(NAME) visu_download_install
	
${NAME}		:		$(OBJDIR) $(OBJ)
	@${CC} ${CFLAGS} -I${INCDIR} -o ${NAME} ${OBJ} $(LDIR)$(LIBFT)
	@echo "${GREEN}$(NAME) sucessefully compiled 📁.${RESET}"

$(OBJDIR)		:
	@$(MK) ${OBJDIR}

run				:		all
	@./${NAME}

libft :
	@$(MAKE) -C $(LDIR)

clean			:
	@$(RM) $(OBJ)
	@$(RM)r $(OBJDIR)
	@$(MAKE) -C $(LDIR) clean
	
fclean			: 		clean	
	@$(RM) $(NAME)
	@$(RM)r push_swap_visualizer/
	@$(MAKE) -C $(LDIR) fclean
	@echo "${GREEN}$(NAME) object files and executable successfully removed 🗑.${RESET}"

visu_download_install:
	git clone https://github.com/o-reo/push_swap_visualizer.git && cd push_swap_visualizer && mkdir build && cd build && cmake .. && make

visu_update:
	cd push_swap_visualizer/build && make

visu_download:
	git clone https://github.com/o-reo/push_swap_visualizer.git

visu:
	./push_swap_visualizer/build/bin/visualizer

test:
	@echo "10 tests/ 0 - 500"
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..500).to_a.shuffle.join(' ')"` | wc -l
	@echo "/	/	/	/	/"
	@echo "10 tests/ 0 - 100"
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (1..100).to_a.shuffle.join(' ')"` | wc -l
	@echo "/	/	/	/	/"
	@echo "10 tests/ 0 - 3"
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..2).to_a.shuffle.join(' ')"` | wc -l

re				: 		fclean all

.PHONY			: 		all clean fclean libft re