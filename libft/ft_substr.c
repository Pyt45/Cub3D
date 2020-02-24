/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:14:46 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/11/07 19:50:12 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	j;
	size_t	size;

	j = 0;
	if (!s)
		return (NULL);
	if (!s[start])
		return (ft_strdup(""));
	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (!(ptr = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start < size)
	{
		while (j < len && s[start] != '\0')
		{
			ptr[j++] = s[start++];
		}
	}
	ptr[j] = '\0';
	return (ptr);
}
