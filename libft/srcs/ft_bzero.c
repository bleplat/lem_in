/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:58:30 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/08 12:16:57 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t len)
{
	while (len > sizeof(long))
	{
		len -= sizeof(long);
		*(long *)((char *)s + len) = 0L;
	}
	while (len > sizeof(int))
	{
		len -= sizeof(int);
		*(int *)((char *)s + len) = (int)0;
	}
	while (len > 0)
	{
		len -= 1;
		((char *)s)[len] = '\0';
	}
}
