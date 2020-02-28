/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:11:09 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 13:08:10 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_H
# define LI_H

# include "li_board.h"
# include "li_link.h"
# include "li_room.h"

# define LI_CMD_START "##start\n"
# define LI_CMD_END "##end\n"

int						li_perror(int code, const char *message);

#endif
