/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing_should_line_be_ignored.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:39:13 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/04 19:06:43 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

/*
** Return non-zero if the ine should be ignored.
** Return 0 otherwise.
*/

int				li_parsing_should_line_be_ignored(char *line)
{
	if (!line)
		return (0);
	if (ft_strcmp(line, LI_CMD_START) == 0 || ft_strcmp(line, LI_CMD_END) == 0)
		return (0);
	if (line[0] == '#')
		return (1);
	return (0);
}
