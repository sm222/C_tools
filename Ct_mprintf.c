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

#include "C_tool.h"

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
void	Ct_mprintf(void *ptr, size_t size, int type, int name)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return ;
	printf("[%c]", name);
	if (type == 0)
	{
		while (i < size)
			printf("%12d | ", ((char *)ptr)[i++]);
	}
	else if (type == 1)
	{
		while (i < size)
		{
			if (((char *)ptr)[i] > 31 && ((char *)ptr)[i] < 127)
				printf("%3c | ", ((char *)ptr)[i]);
			else if (((char *)ptr)[i] == 0)
				printf(" \\0 | ");
			else if (((char *)ptr)[i] == 1)
				printf("SHO | ");
			else if (((char *)ptr)[i] == 2)
				printf("STX | ");
			else if (((char *)ptr)[i] == 3)
				printf("ETX | ");
			else if (((char *)ptr)[i] == 4)
				printf("EOT | ");
			else if (((char *)ptr)[i] == 5)
				printf("ENQ | ");
			else if (((char *)ptr)[i] == 6)
				printf("ACK | ");
			else if (((char *)ptr)[i] == 7)
				printf(" \\a | ");
			else if (((char *)ptr)[i] == 8)
				printf(" \\b | ");
			else if (((char *)ptr)[i] == 9)
				printf(" \\t | ");
			else if (((char *)ptr)[i] == 10)
				printf(" \\n | ");
			else if (((char *)ptr)[i] == 11)
				printf(" \\v | ");
			else if (((char *)ptr)[i] == 12)
				printf(" \\f | ");
			else if (((char *)ptr)[i] == 13)
				printf(" \\r | ");
			else if (((char *)ptr)[i] == 14)
				printf(" SO | ");
			else if (((char *)ptr)[i] == 15)
				printf(" SI | ");
			else if (((char *)ptr)[i] == 16)
				printf("DLE | ");
			else if (((char *)ptr)[i] == 17)
				printf("DC1 | ");
			else if (((char *)ptr)[i] == 18)
				printf("DC2 | ");
			else if (((char *)ptr)[i] == 19)
				printf("DC3 | ");
			else if (((char *)ptr)[i] == 20)
				printf("DC4 | ");
			else if (((char *)ptr)[i] == 21)
				printf("NAK | ");
			else if (((char *)ptr)[i] == 22)
				printf("SYN | ");
			else if (((char *)ptr)[i] == 23)
				printf("ETB | ");
			else if (((char *)ptr)[i] == 24)
				printf("CAN | ");
			else if (((char *)ptr)[i] == 25)
				printf(" EM | ");
			else if (((char *)ptr)[i] == 26)
				printf("SUB | ");
			else if (((char *)ptr)[i] == 27)
				printf("ESC | ");
			else if (((char *)ptr)[i] == 28)
				printf(" FS | ");
			else if (((char *)ptr)[i] == 29)
				printf(" GS | ");
			else if (((char *)ptr)[i] == 30)
				printf(" RS | ");
			else if (((char *)ptr)[i] == 31)
				printf(" US | ");
			else
				printf("%3d | ", ((char *)ptr)[i]);
			i++;
		}
	}
	printf("\n");
}
