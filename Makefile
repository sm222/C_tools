NAME	=	C_tool.a

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS	=	Ct_mprintf.c\
			Ct_memcmp.c\
			Ct_utils.c\
			Ct_flag.c\
			Ct_time.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo making $(NAME)
$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)

# Removes objects
clean:
	$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	$(RM) a.out
	make -C get_next_line/ fclean

flag: all
	@make -C get_next_line/

build: all
	$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

# Removes objects and executables and remakes
re: fclean all