/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 08:02:47 by vleonel           #+#    #+#             */
/*   Updated: 2024/05/14 08:02:48 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dup, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strdup(const char *str)
{
	char	*duplicate;

	duplicate = (char *)malloc(ft_strlen(str) + 1);
	if (duplicate != NULL)
		ft_strcpy(duplicate, (char *)str);
	return (duplicate);
}
