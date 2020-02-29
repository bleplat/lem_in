/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_calc_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:31:01 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/29 18:23:25 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

static int li_total_step(int *calc)
{
	int total;
	int	i;

	total = 0;
	i = -1;
	while (calc[++i] != 0)
		total += calc[i];
	return (total);
}

static void li_delete_step(int *calc, int step_destroy)
{
	int i;

	while (step_destroy > 0)
	{
		i = 0;
		while (calc[i] != 0)
			i++;
		while (--i != -1)
		{
			step_destroy--;
			calc[i]--;
		}
	}
}

static int	li_add_step(int *calc, int step_add)
{
	int i;

	while (step_add != 0)
	{
		i = -1;
		while (step_add != 0 && calc[++i] != 0)
		{
			if (calc[i] == -2)
				calc[i] = 1;
			else
				calc[i]++;
			step_add--;
		}
	}
}

static int li_calc(t_calc_step step, t_board board)
{
	int *calc;
	int	i;
	int j;

	i = -1;
	if (!(calc = (int *)malloc(sizeof(int) * step.size)))
		return (-1);
	ft_bzero(calc, step.size);
	while (++i < step.size)
	{
		if (i + 1 < step.size)
		{
			j = i + 1;
			while (--j != -1)
				calc[j] += step.distance[i] - step.distance[i + 1];
		}
		else
			calc[j] = -2;
	}
	j = li_total_step(calc);
	j = board.ants_count - j;
	if (j < 0)
		li_delete_step(calc, j * -1);
	else if (j > 0)
		li_add_step(calc, j);
	return (calc[0]);
}

int			li_calc_step(t_board board, int status)
{
	static t_calc_step step = {0, NULL, 0};
	t_room				*room;
	int 				i;

	i = 0;
	room = &(board.rooms[1]);
	if (status == 1)
	{
		free(step.distance);
		return (step.step);
	}
	if (ft_memrealloc(&(step.distance), &(step.size), step.size + 1))
		return (-1);
	while (room->prev != NULL)
	{
		i++;
		room = room->prev;
	}
	step.distance[step.size - 1] = i;
	li_insertion_sort(step.distance, step.size);
	if ((i = li_calc(step, board)) == -1)
	{
		free(step.distance);
		return (-1);
	}
	if (i >= step.step);
	{
		step.step = i;
		return (0);
	}
	return (-2);
}
