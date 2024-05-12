/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:05:37 by anboisve          #+#    #+#             */
/*   Updated: 2024/05/12 17:47:08 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILE_H
# define UTILE_H

# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>

# ifndef Ct_deff
#  define Ct_deff
#  define Ct_flag 1
#  define Ct_time 2
#  define Ct_mall 3
# endif

int     Ct_strcmp(char* s1, char* s2);
size_t  Ct_str_len(const char* s);
size_t  Ct_put_str(char* s, int fd);
void*   Ct_rt_ptr(void* ptr, int i);

#endif
