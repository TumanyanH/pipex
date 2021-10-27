/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htumanya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 21:34:56 by htumanya          #+#    #+#             */
/*   Updated: 2021/10/27 16:38:40 by htumanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int		find_env(char **envp)
{
	int i;

	i = 0;
	while (ft_strncmp(ft_split(envp[i], '=')[0], "PATH", 4) != 0)
		i++;
	return (i);
}

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**cmd_dets;
	char	**paths;
	int 	i;

	i = 0;
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) < 0)
			ft_exit(1, "Error: CMD wrong!\n");
		path = cmd;
	}
	else
	{
		cmd_dets = ft_split(cmd, ' ');
		paths = ft_split(ft_split(envp[find_env(envp)], '=')[1], ':');
		while (paths[i])
		{
			path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd_dets[0]);
			if (access(path, F_OK) == 0)
				return (path);
			++i;
		}
		return (NULL);
	}
	return (path);
}

void	ctrl_proc(char *cmd, int *pipes, char **envp)
{
	pid_t	pid;
	int		buffer_size;
	char	*full_cmd;
	
	pid = fork();
	if (pid < 0)
		ft_exit(1, "Error: not forked\n");
	if (pid == 0)
	{
		close(pipes[0]);
		dup2(pipes[1], 1);
		full_cmd = find_path(cmd, envp);
		if (full_cmd)
			execve(find_path(cmd, envp), ft_split(cmd, ' '), envp);
		else
			ft_exit(1, "Error: command\n");
	}
	else
	{
		close(pipes[1]);
		dup2(pipes[0], 0);
	}
}
