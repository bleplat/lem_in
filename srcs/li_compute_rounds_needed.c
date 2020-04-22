/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:14 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/12 20:17:35 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

void			sort(int count, int *ints)
{
	int		run;
	int		i;
	int		swp;

	run = 1;
	while (run)
	{
		run = 0;
		i = 0;
		while (i < count - 1)
		{
			if (ints[i] > ints[i + 1])
			{
				swp = ints[i];
				ints[i] = ints[i + 1];
				ints[i + 1] = swp;
				run = 1;
			}
			i++;
		}
	}
}

int				min_count(int count, unsigned int *ints)
{
	int total;

	total = 1;
	while (total < count)
	{
		if (ints[total] == ints[total - 1])
			total++;
		else
			break;
	}
	return (total);
}

int				pop(int *ants_cnt, int count, unsigned int *ints)
{
	int		min_cnt;
	int		i_int;

	min_cnt = min_count(count, ints);
	i_int = 0;
	while (i_int < min_cnt)
	{
		ints[i_int] += 1;
		i_int++;
	}
	// TODO: can be improved
	(*ants_cnt) -= min_cnt;
	return (1);
}

/*
** Compute the rounds needed from the count of ants and pathes, and the
** len of every path.
*/

int				li_compute_rounds_needed(int ants, int pathes, int *pathes_len)
{
	int		round_cnt;

	sort(pathes, pathes_len);
	round_cnt = pathes_len[0];
	while (1)
	{
		round_cnt += pop(&ants, pathes, (unsigned int*) pathes_len);
		if (ants <= 0)
			return (round_cnt);
	}
}
