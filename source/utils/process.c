/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:34:56 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/26 21:22:11 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_dets;
	char	**paths;
	int 	i;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == -1)
			ft_exit(1, "Error: CMD wrong!\n");
		path = cmd;
	}
	else
	{
		cmd_dets = ft_split(cmd, ' ');
		paths = ft_split(ft_split(envp[12], '=')[1], ':');
		while (paths[i])
		{
			path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd_dets[0]);
			if (access(path, X_OK) == 0)
				return (path);
			++i;
		}
		return (NULL);
	}
	return (path);
}

void	ctrl_proc(t_args args, int *pipes, char **envp)
{
	pid_t	pid;
	int		buffer_size;

	pid = fork();
	if (pid < 0)
		ft_exit(1, "Error: not forked\n");
	if (pid == 0)
	{
		close(pipes[0]);
		dup2(pipes[1], 1);
		execve(find_path(args.cmd_1, envp), ft_split(args.cmd_1, ' '), envp);
	}
	else
	{
		close(pipes[1]);
		dup2(pipes[0], 0);
		printf("%s\n", pro_read(pipes[0]));
	}
}
