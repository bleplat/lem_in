/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:56:04 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/27 17:37:40 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		if (!(matrice[i] = (int *)malloc(sizeof(int) * size_room)))
		{
			while (--i >= 0)
				free(matrice[i]);
			free(matrice);
			return (NULL);
		}
		ft_bzero(matrice[i], size_room);
	}
	return (matrice);
}
