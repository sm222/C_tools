#ifndef COLOR_H
# define COLOR_H

# ifndef COLORS
#  define COLORS
#  define C_START     "\001" //*start code
#  define C_END       "\002" //*end   code
#  define RED         C_START"\e[31m"C_END
#  define GRN         C_START"\e[32m"C_END
#  define YEL         C_START"\e[33m"C_END
#  define BLU         C_START"\e[34m"C_END
#  define MAG         C_START"\e[35m"C_END
#  define CYN         C_START"\e[36m"C_END
#  define WHT         C_START"\e[37m"C_END
#  define ORG         C_START"\e[38;5;202m"C_END
#  define PIK         C_START"\e[38;5;176m"C_END
#  define TOX         C_START"\e[38;5;51m"C_END
#  define RESET       C_START"\e[0m\022" C_END
#  define CLE         C_START"\e[1;1H\x1b[2J"C_END
#  define GIT         C_START"\e[38;5;82m"C_END
#  define GIT_B       C_START"\e[38;5;94m"C_END
#  define UNDERLINE   C_START"\e[4m"C_END
# endif

#endif // COLOR_H