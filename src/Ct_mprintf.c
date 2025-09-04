/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ct_mprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:37:45 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/09 18:37:45 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

const char* const names[] = {
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
  "---",
  NULL
};

/// @brief use to pritn the memorry from a int or char ptr
/// @param ptr adress
/// @param size width of the pointer (length of the array)
/// @param type  0 int , 1 char
/// @param name exp : 'A' 'B' 'C'
/// @details 00	'\0' 	(null character)
/// @details 1 	  SOH	(start of heading)
/// @details 2 	  STX	(start of text)
/// @details 3 	  ETX	(end of text)
/// @details 4 	  EOT	(end of transmission)
/// @details 5 	  ENQ	(enquiry)
/// @details 6 	  ACK	(acknowledge)
/// @details 7 	  BEL	'\a' (bell)
/// @details 8 	  BS 	'\b' (backspace)
/// @details 9 	  HT 	'\t' (horizontal tab)
/// @details 10	  LF 	'\n' (new line)
/// @details 11	  VT 	'\v' (vertical tab)
/// @details 12	  FF 	'\f' (form feed)
/// @details 13	  CR 	'\r' (carriage ret)
/// @details 14	  SO 	(shift out)
/// @details 15	  SI 	(shift in)
/// @details 16	  DLE	(data link escape)
/// @details 17	  DC1	(device control 1)
/// @details 18	  DC2	(device control 2)
/// @details 19	  DC3	(device control 3)
/// @details 20	  DC4	(device control 4)
/// @details 21	  NAK	(negative ack.)
/// @details 22	  SYN	(synchronous idle)
/// @details 23	  ETB	(end of trans. blk)
/// @details 24	  CAN	(cancel)
/// @details 25	  EM 	(end of medium)
/// @details 26	  SUB	(substitute)
/// @details 27	  ESC	(escape)
/// @details 28	  FS 	(file separator)
/// @details 29	  GS 	(group separator)
/// @details 30	  RS 	(record separator)
/// @details 31	  US 	(unit separator)
void  Ct_mprintf(void* ptr, size_t size, int type, int name) {
  size_t  i;

  i = 0;
  if (!ptr)
    return ;
  printf("[%c]", name);
  if (type == 0) {
    while (i < size)
      printf("%12d | ", ((char *)ptr)[i++]);
  }
  else if (type == 1) {
    while (i < size) {
      if (((char *)ptr)[i] > 31 && ((char *)ptr)[i] < 127)
      	printf("%3c | ", ((char *)ptr)[i]);
      else if (((char *)ptr)[i] >= 0) {
        const int v = ((char *)ptr)[i];
        printf("%3s| ", names[v]); //printf("%3s | ", names[((int)((int *)ptr)[i])]);
      }
      else
      	printf("%3d | ", ((char *)ptr)[i]);
      i++;
    }
  }
  printf("\n");
}
