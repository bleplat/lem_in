/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:56:04 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/05 19:24:53 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
**Matrice Value:
**
**0: No link
**1: Link
**2: Used Link whith A path
**3: Used link whith B path
**4: matrice[x][y] direction is x->y
**5: matrice[x][y] direction is y->x
**6: Used C path with 4
**7: Used C path with 5
*/

void li_free_matrice(int **matrice, int size)
{
	while (--size >= 0)
		free(matrice[size]);
	free(matrice);
}

int		**li_create_matrice(int size_room)
{
	int **matrice;
	int i;

	i = -1;
	if (!(matrice = (int **)malloc(sizeof(int *) * size_room)))
		return (NULL);
	while (++i < size_room)
	{
		if (!(matrice[i] = (int *)ft_memalloc(sizeof(int) * size_room)))
		{
			while (--i >= 0)
				free(matrice[i]);
			free(matrice);
			return (NULL);
		}
	}
	return (matrice);
}
