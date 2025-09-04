/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C_tool.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:39:33 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/09 18:39:33 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_TOOL_H
# define C_TOOL_H

# include "color.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "Ct_err.h"
# include "macro.h"
# include "c_tool_ft.h"
# define  LINE "__________________________________"


# define TRACV(val)   (data_trac_t){val}

# define MEM_OUT_FILE	".mem_file"




//malloc

//

typedef struct s_tool {
  int     i;
  int     j;
  size_t  x;
  size_t  y;
  char*   s;
  char*   str;
} t_tool;


#endif
