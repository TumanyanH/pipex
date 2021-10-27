/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:07:15 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/27 16:35:58 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_args
{
	char	*infile;
	int		infile_fd;
	char	*cmd_1;
	char	*cmd_2;
	char	*outfile;
	int		outfile_fd;
}				t_args;

void	ft_putstr(char *string);
int		ft_exit(int ret, char *err);
t_args	init_args(char **av);
int		get_next_line(int fd, char **line);
void	ctrl_proc(char *cmd, int *pipes, char **envp);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif