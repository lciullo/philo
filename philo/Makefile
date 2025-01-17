# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 13:49:00 by lciullo           #+#    #+#              #
#    Updated: 2023/08/05 18:24:55 by lciullo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ====================== VARIABLES ====================== #

# ---- Final execuphilo ---- #

NAME 			=	philo

HEAD 			=	head/philo.h

SRC 			= 	philo.c \
					src/eat.c \
					src/init.c \
					src/is_dead.c \
					src/libft_utils.c \
					src/loop_philo.c \
					src/parsing.c \
					src/routine.c \
					src/utils.c 

# ---- Directories ---- #

DIR_SRC			=	src/
					
DIR_HEAD 		= 	head/

DIR_OBJS 		=	.objs

# ---- Paths ---- #

OBJS 			=	${addprefix ${DIR_OBJS}/, ${SRC:.c=.o}}

# ---- Variables ---- #

DEBUG_A			=	no

DEBUG_T			=	no

VALGRIND		= 	no

# ---- Commands ---- #

RMF				=	rm -rf

# ====================== FLAGS AND COMPILATION ====================== #

# ---- Compilation flags ---- #

CC 				= cc

CFLAGS 			= -Wall  -Wextra -Werror -I ${DIR_HEAD} 

# ---- Debug Compilation flags ---- #

DFLAGS		=	-g3 -fsanitize=address
ifeq (${DEBUG_A}, yes)
CFLAGS 		+=	${DFLAGS}
endif

DFLAGS		=	-g3 -fsanitize=thread
ifeq (${DEBUG_T}, yes)
CFLAGS 		+=	${DFLAGS}
endif

# ---- Leaks Compilation flags ---- #

LEAKS			=	valgrind --tool=helgrind 

#--tool=drd

# ====================== RULES ====================== #

# ---- Compilation rules ---- #

all :
	${MAKE} ${NAME}

${NAME}: ${OBJS} 
	${CC} ${CFLAGS} $^ -o $@ -pthread

${DIR_OBJS}/%.o: %.c ${HEAD} 
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< -o $@
	
# ---- Debug rules ---- #

debug_address:
	${MAKE} re DEBUG_A=yes

debug_thread:
	${MAKE} re DEBUG_T=yes
# ---- Leaks rules ---- #
	
leaks:
	clear
	${MAKE} re VALGRIND=yes
	${LEAKS} ./philo

# ---- Clean rules --- #

clean :
	${RMF} ${DIR_OBJS}

fclean : clean 
	${RMF}  ${NAME}

re : fclean
	${MAKE} all

.PHONY: all leaks debug_address debug_thread re clean fclean