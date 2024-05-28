# Colors
RED		=	\x1B[31m
GRN		=	\x1B[32m
YEL		=	\x1B[33m
BLU		=	\x1B[34m
MAG		=	\x1B[35m
CYN		=	\x1B[36m
WHT		=	\x1B[37m
RESET	=	\x1B[0m
CLE 	=	\e[1;1H\e[2J

ifeq ($(shell uname -s), Darwin)
    L = "
else
    L = '
endif

NAME	=	C_tools.a

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

# Sources are all .c files
SRCS	=	src/Ct_flag.c\
			src/Ct_debug.c\
			src/Ct_flag.c\
			src/Ct_malloc.c\
			src/Ct_memcmp.c\
			src/Ct_mprintf.c\
			src/Ct_out.c\
			src/Ct_time.c\
			src/Ct_utils.c\
			src/Ct_err.c

OBJS	=	$(SRCS:.c=.o)

all: lib $(NAME)

# Generates output file
$(NAME): $(OBJS)
	cp -p Ct_lib/Ct_lib.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
lib:
	make -C Ct_lib

test:
	gcc -Wall -Werror -Wextra main.c C_tools.a

# Removes objects
clean:
	$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all