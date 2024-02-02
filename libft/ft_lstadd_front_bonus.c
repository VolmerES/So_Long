/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:54:37 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/18 12:23:56 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new -> next = *lst;
	*lst = new;
}
/*
int	main()
{
	//char str[8] = "hola";
	int *n = malloc(4);
	*n = 6;

	t_list *my_list = ft_lstnew(n);

	for (int i = 0; i < 20; i++)
	{
		ft_lstadd_front(&my_list, ft_lstnew(n));
	}
	t_list *node1 = ft_lstnew((&hola);
	t_list *node2 = ft_lstnew((int*) 7);
	t_list *node3 = ft_lstnew((int*) 8);
	t_list *node4 = ft_lstnew((int*) 9);
	t_list *node5 = ft_lstnew((int*) 10);

	node1->content = (int *)6;
	node2->content = (int *)7;
	node3->content = (int *)8;
	node4->content = (int *)9;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//node5->content = (int *) 10;
	node5->next = NULL;

	ft_lstadd_front(&node1, node5);
	//for (int i = 0; i++)
	for (int i = 0; i < 20; i++)
	{
		printf("%d->", *((int *)my_list->content));
		my_list = my_list->next;
	}
	return 0;
}*/
