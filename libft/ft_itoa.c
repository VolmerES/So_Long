/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:42:45 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/13 19:27:06 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int dig)
{
	int	i;

	i = 0;
	if (dig == 0)
		return (1);
	if (dig < 0)
		i++;
	while (dig != 0)
	{
		dig = dig / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		can;
	char	*str;
	long	aux;

	aux = n;
	can = ft_counter(n);
	str = ((char *)malloc((can + 1) * sizeof(char)));
	if (!str)
		return (NULL);
	str[can] = '\0';
	if (aux < 0)
	{
		aux *= -1;
		str[0] = '-';
	}
	while (can > (n < 0))
	{
		str[--can] = ((aux % 10) + '0');
		aux /= 10;
	}
	return (str);
}
/*
int	main()
{
	char  *f;
	
	f = ft_itoa(0);
	printf ("Itoa devuelve %s \n", f);
	return(0);
}*/
