/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_result.c                                  :+:      :+:    :+:   */
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
** Every ant choose a path it will take.
*/

void			li_print_result_2(t_board *board, t_array *pathes_a)
{
	int		*choices;

	if (!(choices = li_ant_choices_create(board, pathes_a)))
		return ;
	li_print_result_from_choices(board, pathes_a, choices);
	ft_free0(choices);
}

/*
** proceed the final output of the ants moves.
*/

int				li_print_result(t_li_board *board)
{
	t_array			*pathes_a;
	ft_putchar('\n');

	if (board->resolve_result == 2)
		return (li_print_singleround_result(board));
	if (!(pathes_a = li_pathes_create(board)))
		return (-1);
	if (pathes_a->item_count == 0)
	{
		li_pathes_destroy(&pathes_a);
		return (-1);
	}
	li_print_result_2(board, pathes_a);
	li_pathes_destroy(&pathes_a);
	return (0);
}
