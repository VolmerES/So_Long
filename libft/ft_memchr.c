/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:28:55 by jdelorme          #+#    #+#             */
/*   Updated: 2023/09/27 15:55:11 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int val, size_t num)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (num > 0)
	{
		if (s[i] == (char)val)
			return ((void *) s + i);
		i++;
		num--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char cad[] = "Hola 42";
	char *f;
	int	i = 'a';

	f = ft_memchr(cad, i, 5);
	printf("El caracter se encuentra en la posicion %p \n", (char *) f);
	f = memchr(cad, i, 5);
	printf("El caracter se encuentra en la posicion %p \n", f);
	return(0);
}*/
