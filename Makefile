NAME	=	C_tool.a

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f



# Sources are all .c files
SRCS	=	Ct_mprintf.c\
			Ct_memcmp.c\
			Ct_utils.c\
			Ct_flag.c\
			Ct_time.c



OBJS	=	$(SRCS:.c=.o)
# BSources are all .c files

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
# Removes objects
clean:
	$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

build: all
	$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

# Removes objects and executables and remakes
re: fclean all