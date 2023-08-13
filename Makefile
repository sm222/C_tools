# Colors
RED		=	"\x1B[31m"
GRN		=	"\x1B[32m"
YEL		=	"\x1B[33m"
BLU		=	"\x1B[34m"
MAG		=	"\x1B[35m"
CYN		=	"\x1B[36m"
WHT		=	"\x1B[37m"
RESET	=	"\x1B[0m"
CLE 	=	\e[1;1H\e[2J

# Output file and dependencies
NAME	=	C_tool.a
LIB		= 	Ct_lib/Ct_lib.a
LIB_DIR	= 	Ct_lib

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -fr
MK 		= 	mkdir -p

# INCLUDE
INCDIR = inc

# Sources and objects
SRCSDIR = src
SRCS	=	Ct_mprintf.c\
			Ct_memcmp.c\
			Ct_utils.c\
			Ct_flag.c\
			Ct_time.c\
			Ct_debug.c\
			Ct_malloc.c
VPATH	=	${SRCSDIR}
OBJSDIR  =   bin
OBJS	=	$(addprefix ${OBJSDIR}/, ${SRCS:.c=.o})

all: lib $(NAME)

${OBJSDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

# Generates output file
$(NAME): $(OBJSDIR) $(OBJS) $(LIB)
	@cp $(LIB) $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@echo $(GRN)making $(NAME)

$(OBJSDIR)		:
	@$(MK) ${OBJSDIR}

# Make lib
lib:
	@echo $(GRN)making $(LIB)$(RESET)
	@make -C $(LIB_DIR)

# Removes objects
clean:
	@echo $(RED)clean$(RESET)
	@make -C $(LIB_DIR) clean
	@$(RM) $(OBJS)
	@$(RM) $(OBJDIR)

# Removes objects and executables
fclean: clean
	@echo $(RED)fclean$(RESET)
	@make -C $(LIB_DIR) fclean
	@$(RM) -f $(NAME)
	@$(RM) -f a.out
	@make -C out_flag/ fclean

flag: all
	make -C out_flag/

build: all
	$(CC) $(CFLAGS) main.c $(NAME) && ./a.out

# Removes objects and executables and remakes
re: fclean all