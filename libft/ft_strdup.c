/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:19:23 by jdelorme          #+#    #+#             */
/*   Updated: 2024/02/02 16:58:43 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
/*
int	main()
{
	char *ptr = NULL;
	char *f;

	f = ft_strdup(ptr);
	printf("La copia devuelve %s \n", f);
	return(0);
}*/
