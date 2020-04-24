/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_calc_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:31:01 by jthierce          #+#    #+#             */
/*   Updated: 2020/04/24 18:14:38 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "li_resolve.h"

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
