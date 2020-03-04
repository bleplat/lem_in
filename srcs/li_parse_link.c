/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:20:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/04 19:07:46 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Parse a single link from a line.
*/

int				li_parse_link(t_li_board *board, t_array *links_a, char *line)
{
	t_li_link	*new_link;
	char		*stick;
	char		*nl;

	if (!(stick = ft_strchr(line, '-')))
		return (LI_ERROR_LINKS_SYNTAX);
	if (!(nl = ft_strchr(stick, '\n')))
		return (LI_ERROR_LINKS_SYNTAX);
	*stick = '\0';
	*nl = '\0';
	if (!(new_link = ft_array_newitem(links_a)))
		return (-1);
	if (li_make_link(new_link, board, line, stick + 1) != 0)
		return (ft_array_pop0(links_a) + LI_ERROR_LINKS_ROOM_DO_NOT_EXIST);
	*stick = '-';
	*nl = '\n';
	return (0);
}
