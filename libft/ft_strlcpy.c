/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:40:24 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/11/07 15:24:25 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		slen;
	size_t		max;

	if ((!dst && !size) || !size)
		return (ft_strlen(src));
	slen = ft_strlen(src);
	max = size - 1;
	i = 0;
	if (size == 0)
		return (slen);
	while (src[i] != '\0' && max > 0)
	{
		dst[i] = src[i];
		i++;
		max--;
	}
	dst[i] = '\0';
	return (slen);
}
