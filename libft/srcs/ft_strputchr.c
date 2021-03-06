/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strputchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:58:39 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 16:59:58 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_strputchr(char *str, char c)
{
	while (*str != '\0')
		str++;
	*str = c;
}
