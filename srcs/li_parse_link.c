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

static int	exist(t_array *links_a, t_link *link)
{
	t_li_link	*link_list;
	int			i_link;

	link_list = (t_li_link *)links_a->items;
	i_link = 0;
	while (i_link < links_a->item_count)
	{
		if (link_list[i_link].i_room_a == link->i_room_a
			&& link_list[i_link].i_room_b == link->i_room_b)
			return (1);
		i_link++;
	}
	return (0);
}

/*
** Add a link, unless it's in double.
*/

static int	push_link(t_board *board, t_array *links_a,
				char *line, char *stick)
{
	t_li_link		*new_link;
	t_li_link		link;

	if (li_make_link(&link, board, line, stick + 1) != 0)
		return (LI_ERROR_LINKS_ROOM_DO_NOT_EXIST);
	if (exist(links_a, &link))
		return (0);
	if (!(new_link = ft_array_newitem(links_a)))
		return (-1);
	*new_link = link;
	return (0);
}

/*
** Parse a single link from a line.
*/

int			li_parse_link(t_li_board *board, t_array *links_a, char *line)
{
	int			rst;
	char		*stick;
	char		*nl;

	if (!(stick = ft_strchr(line, '-')))
		return (LI_ERROR_LINKS_SYNTAX);
	if (!(nl = ft_strchr(stick, '\n')))
		return (LI_ERROR_LINKS_SYNTAX);
	*stick = '\0';
	*nl = '\0';
	rst = push_link(board, links_a, line, stick);
	*stick = '-';
	*nl = '\n';
	return (rst);
}
