/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:04:57 by fsalimba          #+#    #+#             */
/*   Updated: 2023/03/17 12:04:58 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	if (ptr2 < ptr1)
		while (++i <= n)
			ptr1[n - i] = ptr2[n - i];
	else
		while (n-- > 0)
			*(ptr1++) = *(ptr2++);
	return (dest);
}
