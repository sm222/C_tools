/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:10:49 by anboisve          #+#    #+#             */
/*   Updated: 2023/07/05 14:38:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/C_tool.h"
#include "../inc/utile.h"
#include "../Ct_lib/inc/Ct_lib.h"


int  Ct_err_code = 0;

const char* const Ct_err_msg[] = {
  "no err",
  "err malloc",
  "did't call flag_init",
  "can't make flag",
  "call flag_end with no flag",
  "call flag_init more that once",
  "call flag_end with no flag",
  "call flag_print with no flag",
  "make a flag with a negative number",
  "call flag_print with no flag_init",
  "can't open file",
  "can't make file",
  "bad args",
  //
};



int  Ct_strcmp(char* s1, char* s2) {
  size_t  i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

size_t  Ct_str_len(const char* s) {
  if (!s)
    return 0;
  return (strlen(s));
}

size_t	Ct_put_str(char* s, int fd) {
  return (write(fd, s, Ct_str_len(s)));
}

/// @brief tell what ft did't work well
/// @param msg tell what was the problem
void	Ct_err(char* msg) {
  Ct_printf(2, "%o%s: %s\n", NULL, msg, (char *)Ct_err_msg[Ct_err_code]);
}

/// @brief return 
/// @param ptr input adrres
/// @param i give the index of the adrres you want
/// @return return the adress ask
void  *Ct_rt_ptr(void* ptr, int i) {
  static void* list[100];

  if (ptr && i > 0 && i < 101)
    list[i] = ptr;
  if (!ptr && i > 0 && i < 101)
    return (list[i]);
  if (i < 0 && i > -101)
  	list[i * -1] = NULL;
  return NULL;
}

static int  size_of_unb(unsigned long long nb, int base) {
  int  size;

  size = 0;
  while (nb) {
    size++;
    nb /= base;
  }
  return size;
}

char*  ft_ulltoa(unsigned long long nb, int base, char* out) {
  int  i;

  i = size_of_unb(nb, base);
  if (nb == 0)
    i++;
  out[i] = 0;
  while (i--) {
    out[i] = HEX_TABLE[nb % base];
    nb /= base;
  }
  return out;
}

static int  num_s(int n) {
  int  i;

  i = 1;
  if (n == -2147483648)
    return 11;
  else if (n < 0) {
    n = n * -1;
    i++;
  }
  while (n > 9) {
    n = n / 10;
    i++;
  }
  return i;
}

static void set_str(char *s, int i, int long n) {
  if (i > 0) {
    s[i] = n % 10 + '0';
    set_str(s, i - 1, n / 10);
  }
  else
    s[i] = n % 10 + '0';
}

char*  ft_itoa(int n, char* buff) {
  long int  temp;

  temp = n;
  if (temp < 0)
    temp = temp * -1;
  set_str(buff, num_s(n) - 1, temp);
  if (n < 0)
    buff[0] = '-';
  return buff;
}


const char* const list[] = {
    " \\0",
    "SHO",
    "STX",
    "ETX",
    "EOT",
    "ENQ",
    "ACK",
    " \\a",
    " \\b",
    " \\t",
    " \\n",
    " \\v",
    " \\f",
    " \\r",
    " SO",
    " SI",
    "DLE",
    "DC1",
    "DC2",
    "DC3",
    "DC4",
    "NAK",
    "SYN",
    "ETB",
    "CAN",
    " EM",
    "SUB",
    "ESC",
    " FS",
    " GS",
    " RS",
    " US",
};

void  give_spcial_char(char c, char buff[TMP_BUFF_SIZE], bool file) {
  size_t line = 0;

  if (!file)
    line = strlen(Ct_UNDERLINE);
  bzero(buff, TMP_BUFF_SIZE);
  if (c > 31 && c < 127) {
    buff[0] = c;
    return ;
  }
  else if (c >= 0 && c <= 31) {
    memcpy(buff + line, list[(int)c], 3);
  }
  else
    memcpy(buff + line, "DEL", 3);
  if (!file) {
    memcpy(buff, Ct_UNDERLINE, line);
    memcpy(buff + line + 3, Ct_RESET, strlen(Ct_RESET));
  }
}