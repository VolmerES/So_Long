/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:09:11 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/04 20:09:16 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*actnod;
	t_list	*nxtnod;

	if (!lst)
		return ;
	actnod = lst;
	while (actnod)
	{
		nxtnod = actnod->next;
		if (f)
			f(actnod->content);
		actnod = nxtnod;
	}
}
