# include "../inc/utile.h"
# include "../Ct_lib/inc/Ct_lib.h"


const char* const  colorName = "RGYBMCWOrz";
const char* const colorList[] = {
  RED,
  GRN,
  YEL,
  BLU,
  MAG,
  CYN,
  WHT,
  ORG,
  RESET,
  CLE,
};

static void set_time_buff(char buff[TMP_BUFF_SIZE]) {
  time_t     rawtime;
  struct tm* timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  memcpy(buff, asctime(timeinfo) + 11, TMP_BUFF_SIZE - (22));
}

static int	print_select(va_list *list, char c, char *buff, char** ref, char* color)
{
  int     nb;
  char*   s;
  char*   testColor;

  *ref = NULL;
  bzero(buff,  TMP_BUFF_SIZE);
  bzero(color, TMP_BUFF_SIZE);
  testColor = strchr(colorName, c);
  if (c == 's')
  {
    s = va_arg(*list, char *);
    if (!s) {
      memcpy(buff, "(null)", 7);
      return 6;
    }
    *ref = s;
    return (strlen(s));
  }
  else if (c == 'i' || c == 'd') {
    nb = va_arg(*list, int);
    ft_itoa(nb, buff);
		return (strlen(buff));
  }
  else if (c == 'c') {
    nb = (va_arg(*list, int));
    buff[0] = nb;
    buff[1] = 0;
    return 1;
  }
  else if (c == 'p') {
    ft_ulltoa(va_arg(*list, unsigned long), 16, buff + 2);
    memcpy(buff, "0x", 2);
    return (strlen(buff));
  }
  else if (c == '%') {
    memcpy(buff, "%", 2);
    return 1;
  }
  else if (c == 'x') {
    ft_ulltoa(va_arg(*list, unsigned long), 16, buff);
    return (strlen(buff));
  }
  else if (c == 'u') {
    ft_ulltoa(va_arg(*list, unsigned long), 10, buff);
    return (strlen(buff));
  }
  else if (testColor) {
    size_t tmp = (colorName - testColor) *-1;
    memcpy(color, colorList[tmp], strlen(colorList[tmp]) + 1);
  }
  else if (c == 'F') {
    s = va_arg(*list, char *);
    if (!s) {
      return 0;
    }
    *ref = s;
  }
  else if (c == 'T') {
    set_time_buff(buff);
    return (strlen(buff));
  }
  return 0;
}


static short add_buff(char* arg, t_buff* buff) {
  if (!buff->str) {
    buff->str = calloc(SIZE_BUFF + 1, sizeof(char));
    if (!buff->str)
      return 1;
    buff->len = SIZE_BUFF;
  }
  ssize_t sLen = strlen(arg);
  while (buff->dest > buff->len / 2 || sLen + buff->dest > buff->len / 2) {
    buff->str = realloc(buff->str, buff->len * BUFF_MUL);
    if (!buff->str)
      return 1;
    buff->len *= BUFF_MUL;
  }
  memmove(buff->str + buff->dest, arg, sLen);
  buff->dest += sLen;
  return 0;
}


static ssize_t calculate_size(const char* s, va_list* list, t_buff out[2]) {
  ssize_t   i = 0, j = 0;
  char      buff[TMP_BUFF_SIZE], color[TMP_BUFF_SIZE];
  t_buff    file;
  char*     str = NULL;
  short     err = 0;

  if (!s)
    return -1;
  bzero(&file, sizeof(file));
  while (s[i]) {
    if (s[i] != '%') {
      buff[0] = s[i];
      buff[1] = 0;
      err += add_buff(buff, &out[0]);
      err += add_buff(buff, &out[1]);
      j++;
    }
    else {
      j += print_select(list, s[++i], buff, &str, color);
      if (str && s[i] != 'F') {
        err += add_buff(str, &out[0]);
        err += add_buff(str, &out[1]);
        str = NULL;
      }
      else if (color[0])
        err += add_buff(color, &out[0]);
      else if (str) {
        out[1].outfile = str;
      }
      else {
        err += add_buff(buff, &out[0]);
        err += add_buff(buff, &out[1]);
      }
    }
    i++;
    if (err) {
      Ct_err_code = -4;
      return -1;
    }
  }
  return j;
}


/// @brief 
/// @param s 
/// @param  
/// @return raw size of text with no color or flag init
ssize_t Ct_debug_info(const char* s, ...) {
  va_list   args;
  ssize_t   i = 0;
  t_buff    buff[2];

  if (!s) {
    Ct_err_code = bad_args;
    return -1;
  }
  bzero(buff, sizeof(buff));
  va_start(args, s);
  if (DEBUG_FLAG > 0) {
    i = calculate_size(s, &args, buff);
    if (i != -1 && DEBUG_FLAG & DflagOut)
      write(STDERR_FILENO, buff[0].str, strlen(buff[0].str));
    if (buff[1].outfile) {
      int fd = open(buff[1].outfile, O_CREAT | O_APPEND | O_RDWR, 0644);
      if (fd > -1) {
        write(fd, buff[1].str, strlen(buff[1].str));
        close(fd);
      }
      else {
        Ct_err_code = cant_make_file;
      }
    }
    if (i == -1)
        Ct_err_code = err_malloc;
    free(buff[0].str);
    free(buff[1].str);
  }
  va_end(args);
  return i;
}