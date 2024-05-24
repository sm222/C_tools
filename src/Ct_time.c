/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:29:19 by anboisve          #+#    #+#             */
/*   Updated: 2023/05/08 21:29:19 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/C_tool.h"
#include "../inc/utile.h"
#include  <time.h>

void  Ct_time_print(void) {
  time_t rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("\r%s", asctime(timeinfo));
}

char*  Ct_time_return(void) {
  time_t     rawtime;
  struct tm* timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  return(asctime(timeinfo));
}

short  Ct_start_time(tt_time* start) {
  if (!start)
    return 1;
  (*start) = (struct timeval){-1, -1};
  gettimeofday(start, NULL);
  return 0;
}

const char* Ct_stop_time(tt_time* start, tt_time* stop) {
  static char buff[TMP_BUFF_SIZE + 1];
  if (!start || !stop)
    return buff;
  (*stop) = (struct timeval){-1, -1};
  gettimeofday(stop, NULL);
  snprintf(buff, TMP_BUFF_SIZE, "%ld", \
  (stop->tv_sec - start->tv_sec) + (stop->tv_usec - start->tv_usec));
  return (buff);
}
