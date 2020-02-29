/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing_nextline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:26:33 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 16:36:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

char						*li_parsing_nextline(t_li_board *b)
{
	int		rst;
	char	*line;

	(void)b;
	rst = ft_readtonl(0, &line, LI_MAXLINELEN);
	if (rst <= 0)
		return (NULL);
	// TODO: delete the entire file ??? 
}
