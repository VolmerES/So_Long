/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:02:21 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/17 15:14:38 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t numelem, size_t sizeelem)
{
	int	*ptr;

	ptr = malloc(numelem * sizeelem);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, numelem * sizeelem);
	return (ptr);
}

/*int	main()
{
	char *p;
	p = ft_calloc(20, 2);
	write(1, p, 40);
	write(1, "\n", 1);
	return(0);
}*/
