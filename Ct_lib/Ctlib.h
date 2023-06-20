/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ctlib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:18 by anboisve          #+#    #+#             */
/*   Updated: 2023/06/19 22:15:04 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTLIB_H
# define CTLIB_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "index.h"
# include "Ct_printf.h"

# define HEX_TABLE "0123456789abcdef"

//made by @sm222
//char		\verification

int		Ct_isalpha(int c);
int		Ct_isdigit(int c);
int		Ct_isascii(int c);
int		Ct_isalnum(int c);
int		Ct_isprint(int c);
int		Ct_isprint(int c);

//char				\modify

int		Ct_tolower(int c);
int		Ct_toupper(int c);

//str												\manipulation

char	*Ct_strdup(const char *s1);
char	*Ct_strdup_c(const char *str, char c);
char	*Ct_strjoin(char const *s1, char const *s2);
char	*Ct_strtrim(char const *s1, char const *set);
size_t	Ct_strlcat(char *dst, const char *src, size_t dstsize);
size_t	Ct_strlcpy(char *dst, const char *src, size_t dstsize);
char	*Ct_substr(char const *s, unsigned int start, size_t len);

//str															\compare

size_t	Ct_strlen(const char *s);
size_t	Ct_strlen_double(char **s);
char	*Ct_strchr(const char *s, int c);
char	*Ct_strrchr(const char *s, int c);
int		Ct_strncmp(const char *s1, const char *s2, size_t n);
void	Ct_striteri(char *s, void (*f)(unsigned int, char *));
char	*Ct_strmapi(char const *s, char (*f)(unsigned int, char));
char	*Ct_strnstr(const char *haystack, const char *needle, size_t len);
char	**Ct_cpy_double_char(char **str);
char	*Ct_combine(char *s, va_list arg);

//memory										\manipulation

void	*Ct_free(void *p);
void	Ct_bzero(void *s, size_t n);
void	**Ct_double_sfree(void **ptr);
void	*fr_return_ptr(void *ptr, int i);
void	*Ct_calloc(size_t count, size_t size);
void	*Ct_memset(void *b, int c, size_t len);
void	*Ct_memchr(const void *s, int c, size_t n);
char	**Ct_str_split(const char *s, char **list);
void	*Ct_memcpy(void *dst, const void *src, size_t n);
int		Ct_memcmp(const void *s1, const void *s2, size_t n);
void	*Ct_memmove(void *dst, const void *src, size_t len);
void	*Ct_realloc(void *old, size_t count, size_t size, size_t new_size);

//output								//

int		Ct_putchar_fd(char c, int fd);
int		Ct_putstr_fd(char *s, int fd);
int		Ct_putnbr_fd(int n, int fd);
int		Ct_putendl_fd(char *s, int fd);

//conversion							//

int		Ct_atoi(const char *str);
char	*Ct_itoa(int n);
char	**Ct_split(char const *s, char c);

//fd									//

int		Ct_close_fds(int **fds, int f_ptr, int size);


//GNL									//

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

/*
# if __MACH__
#  define PTR_SIZE unsigned long
# else if
#  define PTR_SIZE unsigned long long
# endif
*/

#endif
