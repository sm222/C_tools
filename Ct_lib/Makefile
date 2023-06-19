NAME	=	libft.a

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

# Sources are all .c files
SRCS	=	Ct_atoi.c\
			Ct_bzero.c\
			Ct_calloc.c\
			Ct_close_fds.c\
			Ct_combine.c\
			Ct_cpy_double_char.c\
			Ct_double_sfree.c\
			Ct_free.c\
			Ct_isalnum.c\
			Ct_isalpha.c\
			Ct_isascii.c\
			Ct_isdigit.c\
			Ct_isprint.c\
			Ct_itoa.c\
			Ct_lstadd_back.c\
			Ct_lstadd_front.c\
			Ct_lstclear.c\
			Ct_lstdelone.c\
			Ct_lstiter.c\
			Ct_lstlast.c\
			Ct_lstmap.c\
			Ct_lstnew.c\
			Ct_lstsize.c\
			Ct_memchr.c\
			Ct_memcmp.c\
			Ct_memcpy.c\
			Ct_memmove.c\
			Ct_memset.c\
			Ct_printf.c\
			Ct_put_hex.c\
			Ct_put_p.c\
			Ct_put_u.c\
			Ct_putchar_fd.c\
			Ct_putendl_fd.c\
			Ct_putnbr_fd.c\
			Ct_putstr_fd.c\
			Ct_realloc.c\
			Ct_return_ptr.c\
			Ct_split.c\
			Ct_str_split.c\
			Ct_strchr.c\
			Ct_strdup.c\
			Ct_striteri.c\
			Ct_strjoin.c\
			Ct_strlcat.c\
			Ct_strlcpy.c\
			Ct_strlen.c\
			Ct_strlen_double.c\
			Ct_strmapi.c\
			Ct_strncmp.c\
			Ct_strnstr.c\
			Ct_strrchr.c\
			Ct_strtrim.c\
			Ct_substr.c\
			Ct_tolower.c\
			Ct_toupper.c\
			Ct_ulltoa.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)
# Removes objects
clean:
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

# for i in Ct_*.c; do mv "$i" "${i/Ct_/Ct_}"; done 