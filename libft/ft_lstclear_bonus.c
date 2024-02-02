/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:52:52 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/10 19:04:10 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actnod;
	t_list	*nxtnod;

	if (!lst || !*lst)
		return ;
	actnod = *lst;
	while (actnod)
	{
		nxtnod = actnod->next;
		if (del)
			del(actnod->content);
		free(actnod);
		actnod = nxtnod;
	}
	*lst = NULL;
}
