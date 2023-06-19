RED		=	"\x1B[31m"
GRN		=	"\x1B[32m"
YEL		=	"\x1B[33m"
BLU		=	"\x1B[34m"
MAG		=	"\x1B[35m"
CYN		=	"\x1B[36m"
WHT		=	"\x1B[37m"
RESET	=	"\x1B[0m"
CLE 	=	\e[1;1H\e[2J

NAME	=	C_tool.a

LIB		= Ct_lib/libft.a
LIB_DIR	= Ct_lib

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	Ct_mprintf.c\
			Ct_memcmp.c\
			Ct_utils.c\
			Ct_flag.c\
			Ct_time.c\
			Ct_debug.c

OBJS	=	$(SRCS:.c=.o)

all: lib $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@cp $(LIB) $(NAME)
	@ar -rcs $(NAME) $(OBJS) $(LIB)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo making $(NAME)

lib:
	@echo $(GRN)making libft$(RESET)
	@make -C $(LIB_DIR)

# Removes objects
clean:
	@echo $(GRN)clean$(RESET)
	@make -C $(LIB_DIR) clean
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@echo $(GRN)fclean$(RESET)
	@make -C $(LIB_DIR) fclean
	@$(RM) -f $(NAME)
	@$(RM) -f a.out
	@make -C get_next_line/ fclean

flag: all
	make -C get_next_line/

build: all
	$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

# Removes objects and executables and remakes
re: fclean all