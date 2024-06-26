/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 00:05:28 by vleonel           #+#    #+#             */
/*   Updated: 2024/05/19 00:05:29 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return (0);
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	return (0);
}