/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:57:33 by vleonel           #+#    #+#             */
/*   Updated: 2024/05/14 07:57:35 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	if (*nd == '\0')
		return ((char *)h);
	i = 0;
	while (i < len && h[i] != '\0')
	{
		j = 0;
		if (h[i] == nd[0])
			while (nd[j] != '\0' && (i + j) < len && h[i + j] == nd[j])
				j++;
		if (nd[j] == '\0')
			return ((char *)h + i);
		i++;
	}
	return (NULL);
}
