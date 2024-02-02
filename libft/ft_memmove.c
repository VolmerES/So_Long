/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:28:16 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/07 18:58:43 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*d;
	unsigned char	*s;

	if (src == NULL && dest == NULL)
		return (NULL);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (s < d && s + num > d)
	{
		d += num;
		s += num;
		while (num--)
		{
			*--d = *--s;
		}
	}
	else
	{
		while (num--)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
