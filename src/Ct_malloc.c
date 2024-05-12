/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:00:38 by anboisve          #+#    #+#             */
/*   Updated: 2023/07/03 21:00:38 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/C_tool.h"
#include "../Ct_lib/inc/Ct_lib.h"


extern int  Ct_err_code;

void  Ct_mall_track(void* ptr) {
  static void**  keep = NULL;
  size_t         i = 0;

  if (ptr) {
    if (!keep) {
      keep = Ct_calloc(2, sizeof(void *));
      if (!keep) {
        return ;
      }
    }
    else {
      while (keep[i])
        i++;
      Ct_realloc(keep, sizeof(void *), i, i + 2);
    }
    keep[i] = ptr;
    Ct_debug_pro(no_err, MEM_OUT_FILE, 0, "add %p\n", ptr);
  }
}


void  *Ct_malloc(size_t size)
{
  void*  new;

  new = Ct_calloc(size, 1);
  Ct_mall_track(new);
  return new;
}
