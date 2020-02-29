/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:11:09 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 16:22:14 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_H
# define LI_H

# include "li_board.h"
# include "li_link.h"
# include "li_room.h"

# define LI_MAXLINELEN 32000

# define LI_ERROR_ANTS_BAD_COUNT -126
# define LI_ERROR_ANTS_READ_FAIL -125
# define LI_ERROR_ROOMS_DUPLICATE -124
# define LI_ERROR_ROOMS_SYNTAX -123
# define LI_ERROR_ROOMS_BAD_X -122
# define LI_ERROR_ROOMS_BAD_Y -121
# define LI_ERROR_LINKS_SYNTAX 120


# define LI_CMD_START "##start\n"
# define LI_CMD_END "##end\n"

int						li_perror(int code, const char *message);
void					li_print_input(t_li_board *board);
void					li_print_result(t_li_board *board);

#endif
