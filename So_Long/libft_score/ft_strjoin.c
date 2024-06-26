/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 08:07:18 by vleonel           #+#    #+#             */
/*   Updated: 2024/05/17 08:07:19 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dup, char const *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = (char)src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = ft_strlen(s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, s1);
	while (s2[i] != '\0')
	{
		dest[j + i] = s2[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
