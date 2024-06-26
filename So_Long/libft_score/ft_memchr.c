/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:56:39 by vleonel           #+#    #+#             */
/*   Updated: 2024/05/14 07:56:40 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)ptr++ == (unsigned char)c)
			return ((void *)(unsigned char *)ptr - 1);
	}
	return (NULL);
}
