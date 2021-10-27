#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_args	args;
	int		pipes[2];

	if (ac != 5)
		ft_exit(1, "Error: argument\n");
	pipe(pipes);
	args = init_args(av);
	ctrl_proc(args.cmd_1, pipes, envp);
	ctrl_proc(args.cmd_2, pipes, envp);
	dup2(0, args.outfile_fd);
	ft_exit(0, NULL);
}
