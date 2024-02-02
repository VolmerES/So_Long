/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelorme <jdelorme@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:47:46 by jdelorme          #+#    #+#             */
/*   Updated: 2023/10/04 19:59:06 by jdelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int	main()
{
	t_list *my_list = NULL;

	int size = ft_lstsize(my_list);
	for (int i = 0; i < 5; i++)
	{
		int *new_content = malloc(sizeof(int));
		*new_content = i;
		t_list *new_node = ft_lstnew(new_content);
		ft_lstadd_back(&my_list, new_node);
		printf("Tamaño: %d->", size);
}

	printf("Tamaño: %d\n", size);

	while (my_list)
	{
		t_list *next = my_list -> next;
		free(my_list->content);
		free(my_list);
		my_list = next;
	}
	return(0);
}*/
