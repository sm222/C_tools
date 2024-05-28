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
  gettimeofday(start, NULL);
  return 0;
}

const char* Ct_stop_time(tt_time* start, tt_time* stop, char* out, int size) {
  //static pthread_mutex_t key = PTHREAD_MUTEX_INITIALIZER;
  
  char buff[TMP_BUFF_SIZE + 1];
  if (!start || !stop || size < 1)
    return out;
  gettimeofday(stop, NULL);
  int len = snprintf(buff, TMP_BUFF_SIZE, "%ld", \
  (stop->tv_sec - start->tv_sec) + (stop->tv_usec - start->tv_usec));
  for (int i = 0; i < size && i < len; i++) {
    out[i] = buff[i];
  }
  return (out);
}
