/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:09:14 by fsalimba          #+#    #+#             */
/*   Updated: 2023/03/23 16:06:26 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	n = ft_strlen(needle);
	while (n <= len && *haystack)
	{
		if (*haystack == *needle && !(ft_strncmp(haystack, needle, n)))
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
