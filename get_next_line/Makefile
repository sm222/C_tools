
NAME	=	flag_cap.out

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Sources are all .c files
SRCS	=	get_next_line.c\
			get_next_line_utils.c\
			out_flag.c

OBJS	=	$(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) ../C_tool.a -o ../$(NAME)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo making $(NAME)

# Generates output file
# Removes objects
clean:
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@$(RM) ../$(NAME)

# Removes objects and executables and remakes
re: fclean all

.PHONY: all