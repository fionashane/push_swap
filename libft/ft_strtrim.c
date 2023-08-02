/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:09:52 by fsalimba          #+#    #+#             */
/*   Updated: 2023/03/23 11:45:32 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	len;

	if (*s1 == '\0')
	{
		trim = (char *)malloc(sizeof(char));
		if (!trim)
			return (NULL);
		*trim = '\0';
		return (trim);
	}
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 2;
	trim = (char *)malloc(sizeof(char) * len);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[start], len);
	return (trim);
}
