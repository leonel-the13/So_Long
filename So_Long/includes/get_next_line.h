/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleonel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:24:01 by vleonel           #+#    #+#             */
/*   Updated: 2024/05/30 09:24:02 by vleonel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_len(const char *s);
char	*get_next_line(int fd);
char	*ft_rchr(const char *s, int c);
char	*ft_dup(const char *s1);
char	*ft_join(char *s1, const char *s2);
char	*ft_sub(const char *s, size_t start, size_t len);

#endif
