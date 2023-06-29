# ====================== VARIABLES ====================== #

# ---- Final executable ---- #

NAME 			=	philo

HEAD 			=	head/philo.h

SRC 			= 	philo.c \
					src/print.c

# ---- Directories ---- #

DIR_SRC			=	src/
					
DIR_HEAD 		= 	head/

DIR_OBJS 		=	.objs

# ---- Paths ---- #

OBJS 			=	${addprefix ${DIR_OBJS}/, ${SRC:.c=.o}}

# ---- Variables ---- #

DEBUG			=	no

VALGRIND		= 	no

# ---- Commands ---- #

RMF				=	rm -rf

# ====================== FLAGS AND COMPILATION ====================== #

# ---- Compilation flags ---- #

CC 				= cc

CFLAGS 			= -Wall  -Wextra -Werror -I ${DIR_HEAD} 

# ---- Debug Compilation flags ---- #

DFLAGS			= -g3 -fsanitize=address

ifeq (${DEBUG}, yes)
CFLAGS		+= ${DFLAGS}
endif

# ---- Leaks Compilation flags ---- #

LEAKS			=	valgrind 

#--track-fds=yes



# ====================== RULES ====================== #

# ---- Compilation rules ---- #

all :
	${MAKE} ${NAME}

${NAME}: ${OBJS} 
	${CC} ${CFLAGS} $^ -o $@ 

${DIR_OBJS}/%.o: %.c ${HEAD} 
	@mkdir -p ${dir $@}
	${CC} ${CFLAGS} -c $< -o $@
	
# ---- Debug rules ---- #

debug:
	${MAKE} re DEBUG=yes
	

# ---- Leaks rules ---- #
	
leaks:
	clear
	${MAKE} re VALGRIND=yes
	${LEAKS} ./minishell

# ---- Clean rules --- #

clean :
	${RMF} ${DIR_OBJS}

fclean : clean 
	${RMF}  ${NAME}

re : fclean
	${MAKE} all

.PHONY: all  clean fclean re