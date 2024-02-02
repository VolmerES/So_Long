/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:22:16 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/07 19:30:19 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		total;

	i = 0;
	j = 0;
	total = (ft_strlen(dest) + ft_strlen(src));
	while (i < dstsize && dest[i] != '\0')
		i++;
	while ((i + j + 1) < dstsize && src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
