/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:50:23 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/01 18:39:24 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

int	li_memrealloc(void **mem, size_t previous_size, size_t new_size)
{
	void		*new_mem;
	size_t		cp_len;

	if (previous_size == new_size)
		return (0);
	if (mem == NULL)
		return (1);
	new_mem = ft_memalloc(new_size);
	if (new_mem == NULL)
		return (1);
	if (*mem != NULL)
	{
		cp_len = (previous_size < new_size) ? (previous_size) : new_size;
		ft_memcpy(new_mem, *mem, cp_len);
		ft_memdel(&(*mem));
	}
	*mem = new_mem;
	return (0);
}
