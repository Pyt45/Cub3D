/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:32:46 by aaqlzim           #+#    #+#             */
/*   Updated: 2019/11/07 12:45:47 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;
	size_t	j;

	str1 = (char *)haystack;
	str2 = (char *)needle;
	i = 0;
	if (str2[0] == '\0')
		return (str1);
	while (i < len && str1[i] != '\0')
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			while (str1[i + j] == str2[j] && (i + j) < len)
			{
				if (str2[j + 1] == '\0')
					return (str1 + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}
