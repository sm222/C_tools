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

/*
	ptr = data
	size = width of the pointer
	type , 0 int , 1 char
	name = exp : 'A' 'B' 'C'
*/
void	Ct_mprintf(void *ptr, size_t size, int type, int name)
{
	size_t	i;

	i = 0;
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

/*
00	'\0' 	(null character)
1 	  SOH	(start of heading)
2 	  STX	(start of text)
3 	  ETX	(end of text)
4 	  EOT	(end of transmission)
5 	  ENQ	(enquiry)
6 	  ACK	(acknowledge)
7 	  BEL	'\a' (bell)
8 	  BS 	'\b' (backspace)
9 	  HT 	'\t' (horizontal tab)
10	  LF 	'\n' (new line)
11	  VT 	'\v' (vertical tab)
12	  FF 	'\f' (form feed)
13	  CR 	'\r' (carriage ret)
14	  SO 	(shift out)
15	  SI 	(shift in)
16	  DLE	(data link escape)
17	  DC1	(device control 1)
18	  DC2	(device control 2)
19	  DC3	(device control 3)
20	  DC4	(device control 4)
21	  NAK	(negative ack.)
22	  SYN	(synchronous idle)
23	  ETB	(end of trans. blk)
24	  CAN	(cancel)
25	  EM 	(end of medium)
26	  SUB	(substitute)
27	  ESC	(escape)
28	  FS 	(file separator)
29	  GS 	(group separator)
30	  RS 	(record separator)
31	  US 	(unit separator)
*/