/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:51:02 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/11/07 12:37:38 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int a, size_t len)
{
	char	*str;

	str = (char *)ptr;
	while (len--)
	{
		*str++ = (unsigned char)a;
	}
	return ((void *)ptr);
}
