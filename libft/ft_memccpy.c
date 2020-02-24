/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:26:08 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/11/07 12:35:24 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*from;
	char			*to;
	size_t			i;

	i = 0;
	from = (unsigned char *)src;
	to = (char *)dst;
	while (i < n)
	{
		to[i] = from[i];
		if (from[i] == (unsigned char)c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (0);
}
