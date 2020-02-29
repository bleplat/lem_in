/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:59:08 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/29 18:03:41 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

void	li_insertion_sort(int *str, size_t size)
{
	size_t	i;
	size_t	j;
	int		buff;

	i = -1;
	j = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (str[j] < str[i])
			{
				buff = str[i];
				str[i] = str[j];
				str[j] = buff;
				j = i;
			}
		}
	}
}
