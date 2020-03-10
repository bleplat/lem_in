/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/10 01:15:00 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Initialize the array of usages
*/

void			init_usages(t_array *pathes_a, unsigned int *usages)
{
	int		i_path;
	t_array	*path;

	i_path = 0;
	while (i_path < pathes_a->item_count)
	{
		path = *(void**)ft_array_at(pathes_a, i_path);
		usages[i_path] = path->item_count;
		i_path++;
	}
}

/*
** Find the less used index and return it, and increment its usage
** in the provided array.
*/

int				next_path_index(unsigned int *usages, int path_count)
{
	int					i;
	unsigned int		min;
	int					i_min;

	min = FT_INT32_MAX;
	i = 0;
	{
		while (i < path_count)
		{
			if (usages[i] < min)
			{
				i_min = i;
				min = usages[i];
			}
			i++;
		}
	}
	usages[i_min]++;
	return (i_min);
}

/*
** Create an array of int telling for every ant wich path it will take.
*/

int				*li_ant_choices_create(t_board *brd, t_array *pathes_a)
{
	int						*choices;
	unsigned int			*usages;
	int						i;

	if (!(choices = malloc(sizeof(int) * brd->ants_count)))
		return (NULL);
	if (!(usages = malloc(sizeof(int) * pathes_a->item_count)))
		return (ft_freen(choices));
	init_usages(pathes_a, usages);
	i = brd->ants_count - 1;
	while (i >= 0)
	{
		choices[i] = next_path_index(usages, pathes_a->item_count);
		i--;
	}
	ft_free0(usages);
	return (choices);
}
