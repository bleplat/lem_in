/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/03 18:57:39 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

void					li_print_result(t_li_board *board)
{
	(void)board;
	li_board_dump(board); // replace by results
	ft_printf("L1->2\n");
	ft_printf("L1->2 L3->1\n");
	ft_printf("L0->void\n");
}
