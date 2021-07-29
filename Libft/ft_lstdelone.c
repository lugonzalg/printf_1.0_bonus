/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:10:03 by lugonzal          #+#    #+#             */
/*Updated: 2021/06/04 11:14:38 by lugonzal               ###   ########.fr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	else
	{	
		del(lst->content);
		free(lst);
		lst = lst->next;
	}
}
