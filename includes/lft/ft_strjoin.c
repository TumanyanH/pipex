/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:26:29 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/25 21:57:25 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	newstrlen;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	newstrlen = ft_strlen(s1) + ft_strlen(s2);
	if (!(newstr = malloc(sizeof(char *) * newstrlen + 1)))
		return (NULL);
	while (*s1 != '\0')
	{
		*newstr = *s1;
		++s1;
		++newstr;
	}
	while (*s2 != '\0')
	{
		*newstr = *s2;
		++s2;
		++newstr;
	}
	*newstr = '\0';
	return (newstr - newstrlen);
}
