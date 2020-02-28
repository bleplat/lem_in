/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:11:09 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 14:43:29 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_H
# define LI_H

# include "li_board.h"
# include "li_link.h"
# include "li_room.h"

# define LI_MAXLINELEN 32000

# define LI_ERROR_ANTS_BAD_COUNT -126
# define LI_ERROR_ANTS_READ_FAIL -126

# define LI_CMD_START "##start\n"
# define LI_CMD_END "##end\n"

int						li_perror(int code, const char *message);
void					li_print_input(t_li_board *board);
void					li_print_result(t_li_board *board);

#endif
