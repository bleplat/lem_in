/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_calc_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:31:01 by jthierce          #+#    #+#             */
/*   Updated: 2020/04/24 15:01:11 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "li_resolve.h"

static int li_total_step(int *calc, ssize_t size)
{
	int		total;
	ssize_t	i;

	total = 0;
	i = 0;
	while (i < size - 1)
	{
		total += calc[i];
		i++;
	}
	return (total);
}

static void li_delete_step(int *calc, int step_destroy, ssize_t size)
{
	ssize_t i;

	while (step_destroy > 0)
	{
		i = 0;
		while (i < size)
			i++;
		while (--i != -1)
		{
			step_destroy--;
			calc[i]--;
		}
	}
}

static void	li_add_step(int *calc, int step_add, ssize_t size)
{
	ssize_t i;

	while (step_add > 0)
	{
		i = 0;
		while (step_add != 0 && i < size)
		{
			if (calc[i] == -2)
				calc[i] = 1;
			else
				calc[i]++;
			i++;
			step_add--;
		}
	}
}

int li_calc(t_calc_step step, t_board board)
{
	int		*calc;
	ssize_t	i;
	int		j;

	i = -1;
	if (!(calc = (int *)malloc(sizeof(int) * (step.size))))
		return (-1);
	while (++i < step.size)
		calc[i] = 0;
	i = -1;
	while (++i < step.size)
	{
		if (i + 1 < step.size)
		{
			j = i + 1;
			while (--j != -1)
				calc[j] += step.distance[i + 1] - step.distance[i];
		}
		else
			calc[i] = -2;
	}
	j = li_total_step(calc, step.size);
	j = board.ants_count - j;
	if (j < 0)
		li_delete_step(calc, j * -1, step.size);
	else if (j > 0)
		li_add_step(calc, j, step.size);
	j = step.distance[0] + calc[0] - 1;
	free(calc);
	return (j);
}

/*
** Calcul le nombre d'etape minimum avec les nouveaux chemins.
**
** Si la valeur est plus grande que celle d'avant alors la fonctin retourne
** un code d'erreur ce qui arrete l'algo et retroune en arriere.
*/

int			li_calc_step(t_board board, int status)
{
	static t_calc_step	step = {INT_MAX, NULL, 0};
	int 				i;

	i = 0;
	if (status == 1)
	{
		if (step.distance != NULL)
			free(step.distance);
		return (step.step);
	}
	if (li_memrealloc((void **)&(step.distance), sizeof(int) * (step.size),
	sizeof(int) * (step.size + 1)))
		return (-1);
	step.size++;
	li_distance_path(board, step.distance, step.size);
	i = li_compute_rounds_needed(board.ants_count, step.size, step.distance);
	if (i <= step.step)
	{
		step.step = i;
		return (0);
	}
	return (-2);
}
