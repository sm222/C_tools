#ifndef COLOR_H
# define COLOR_H

# ifndef COLORS
#  define COLORS
#  define C_START        "\001" //*start code
#  define C_END          "\002" //*end   code
#  define Ct_RED         C_START"\e[31m"C_END
#  define Ct_GRN         C_START"\e[32m"C_END
#  define Ct_YEL         C_START"\e[33m"C_END
#  define Ct_BLU         C_START"\e[34m"C_END
#  define Ct_MAG         C_START"\e[35m"C_END
#  define Ct_CYN         C_START"\e[36m"C_END
#  define Ct_WHT         C_START"\e[37m"C_END
#  define Ct_ORG         C_START"\e[38;5;202m"C_END
#  define Ct_PIK         C_START"\e[38;5;176m"C_END
#  define Ct_TOX         C_START"\e[38;5;51m"C_END
#  define Ct_RESET       C_START"\e[0m\022" C_END
#  define Ct_CLE         C_START"\e[1;1H\x1b[2J"C_END
#  define Ct_GIT         C_START"\e[38;5;82m"C_END
#  define Ct_GIT_B       C_START"\e[38;5;94m"C_END
#  define Ct_UNDERLINE   C_START"\e[4m"C_END
# endif

#endif // COLOR_H