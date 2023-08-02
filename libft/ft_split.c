/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:06:23 by fsalimba          #+#    #+#             */
/*   Updated: 2023/03/23 11:35:37 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_substrs(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	ft_gen_splits(char const *s, char c, char **strs)
{
	char const	*s_tmp;
	char		**strs_tmp;

	s_tmp = s;
	strs_tmp = strs;
	while (*s_tmp)
	{
		while (*s == c)
			++s;
		s_tmp = s;
		while (*s_tmp && *s_tmp != c)
			++s_tmp;
		if (s_tmp > s || *s_tmp == c)
		{
			*strs_tmp = ft_substr(s, 0, s_tmp - s);
			s = s_tmp;
			++strs_tmp;
		}
	}
	*strs_tmp = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		count;

	count = ft_count_substrs(s, c);
	strs = malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	ft_gen_splits(s, c, strs);
	return (strs);
}
