/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/12 20:18:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Print an ant move.
** is_first is used to know if the ant is the first on its line,
** and is set to 0 before the function return.
*/

int			li_print_move(int i_ant, t_room *dst, int *is_first)
{
	if (i_ant < 0)
		return (0);
	if (!(*is_first))
		ft_putchar(' ');
	ft_putchar('L');
	ft_putnbr(i_ant + 1);
	ft_putchar('-');
	ft_putstr(dst->name);
	*is_first = 0;
	return (2);
}
