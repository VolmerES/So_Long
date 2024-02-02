/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:56:21 by jdelorme          #+#    #+#             */
/*   Updated: 2023/09/20 17:39:53 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}
/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int b;

	a = 'C';
	b = ft_tolower(a);
	printf("%c \n", b);
	
	return (0);
}*/
