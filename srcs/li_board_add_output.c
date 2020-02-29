/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_add_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:16:49 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 17:18:37 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_board.h"

int					li_board_add_output(t_li_board *brd, const char *line)
{
	const char		**new_item;

	new_item = ft_array_newitem(brd->output_a);
	if (!new_item)
		return (-1);
	*new_item = line;
	return (0);
}
