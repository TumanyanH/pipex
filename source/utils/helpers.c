/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:53:42 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/26 21:59:33 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	ft_putstr(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
}

int	ft_exit(int ret, char *err)
{
	if (err)
		perror(err);
	exit(ret);
}

char	*cust_realloc(char *old_str, int extend)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (extend + ft_strlen(old_str)));
	ft_strlcpy(new, old_str, ft_strlen(old_str));
	return (new);
}

char	*pro_read(int fd)
{
	char *line;
	int i = 1;
	
	line = (char *)malloc(sizeof(char) + 2);
	
	while (read(fd, line, i) > 0)
	{
		line = cust_realloc(line, 1);
		++i;
	}
	return (line);
}