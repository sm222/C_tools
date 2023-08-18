NAME	=	Ct_lib.a

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -fr
MK 		= 	mkdir -p

# Include
INCDIR = inc

# Sources are all .c files
SRCSDIR = src
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
			Ct_ulltoa.c\
			Ct_get_next_line.c

VPATH	=	${SRCSDIR}

# Objects
OBJSDIR  =   bin
OBJS	=	$(addprefix ${OBJSDIR}/, ${SRCS:.c=.o})

all: $(NAME)

# Generates output file
${OBJSDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

$(NAME): ${OBJSDIR} $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJSDIR)		:
	@$(MK) ${OBJSDIR}

# Removes objects
clean:
	@$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJSDIR)

# Removes objects and executables and remakes
re: fclean all

# for i in Ct_*.c; do mv "$i" "${i/Ct_/Ct_}"; done 