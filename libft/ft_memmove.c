/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:33:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/11/07 17:46:34 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*v_dst;
	const char	*v_src;

	v_dst = (char *)dst;
	v_src = (const char *)src;
	if (!len)
		return (dst);
	if (v_dst <= v_src)
	{
		return (ft_memcpy(v_dst, v_src, len));
	}
	v_dst += len;
	v_src += len;
	while (len--)
		*--v_dst = *--v_src;
	return (dst);
}
