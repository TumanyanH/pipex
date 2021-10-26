/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:35:41 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/25 21:19:30 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ucc;

	ucc = (unsigned char)c;
	if (ucc == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == ucc)
		{
			return ((char *)(s));
		}
		++s;
	}
	return (NULL);
}
