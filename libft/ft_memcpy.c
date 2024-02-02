/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:33:21 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/07 18:43:19 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (destination == NULL && source == NULL)
		return (NULL);
	d = (unsigned char *) destination;
	s = (const unsigned char *) source;
	i = 0;
	while (i < num)
	{
		d[i] = s[i];
		i++;
	}
	return (destination);
}
