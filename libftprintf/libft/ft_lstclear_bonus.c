/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:08:48 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:46:46 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		prev = *lst;
		*lst = prev->next;
		ft_lstdelone(prev, del);
	}
}
